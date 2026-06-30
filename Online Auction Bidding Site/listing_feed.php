<?php

ob_start(); 
header('Content-Type: application/json; charset=utf-8');

// capture warnings/notices
$CAPTURED = [];
set_error_handler(function($errno, $errstr, $file, $line) {
  global $CAPTURED;
  $CAPTURED[] = $errstr . ' @ ' . basename($file) . ':' . $line;
  return true;
});

$PRIMARY  = '/home/students/accounts/s105950524/cos80021/www/data/auction.xml';
$FALLBACK = __DIR__ . '/data/auction.xml';
$DEBUG    = isset($_GET['debug']);

function loadXmlStrict($path, &$status) {
  if (!is_file($path)) { $status = 'not_found'; return null; }
  $status = 'ok';
  libxml_use_internal_errors(true);
  $txt = @file_get_contents($path);
  if ($txt === false) { $status = 'unreadable'; return null; }
  $xml = simplexml_load_string($txt);
  if (!$xml) { $status = 'invalid_xml'; return null; }
  return $xml;
}

$stP = ''; $stF = '';
$xmlP = loadXmlStrict($PRIMARY, $stP);
$xmlF = loadXmlStrict($FALLBACK, $stF);

$cat = isset($_GET['category']) ? trim($_GET['category']) : '';
$q   = isset($_GET['q']) ? strtolower(trim($_GET['q'])) : '';
$now = time();

$itemsById = [];

function add_from_xml($xml, $now, $cat, $q, &$itemsById) {
  if (!$xml) return;
  foreach ($xml->Item as $it) {
    $id       = (string)$it->ItemID;
    $title    = (string)$it->Title;
    $seller   = (string)$it->SellerID;
    $category = (string)$it->Category;
    $desc     = (string)$it->Description;
    $buyNow   = (string)$it->BuyNowPrice;
    $endIso   = (string)$it->EndTime;
    $status   = strtoupper(trim((string)$it->Status ?: 'OPEN'));

    $endTs = strtotime($endIso); if ($endTs === false) $endTs = 0;

    // only active, open auctions
    if ($status !== 'OPEN') continue;
    if ($endTs && $endTs <= $now) continue;

    $startPrice = (float)$it->StartPrice;
    $highestBid = (float)$it->HighestBid;
    $current    = ($startPrice > $highestBid) ? $startPrice : $highestBid;

    // filters
    if ($cat !== '' && strcasecmp($cat, $category) !== 0) continue;
    if ($q !== '') {
      $hay = strtolower($id . ' ' . $title . ' ' . $seller . ' ' . $category . ' ' . $desc);
      if (stripos($hay, $q) === false) continue;
    }

    
    if (!isset($itemsById[$id]) || strtotime($endIso) > strtotime($itemsById[$id]['endTime'])) {
      $itemsById[$id] = [
        'id'           => $id,
        'title'        => $title,
        'seller'       => $seller,
        'category'     => $category,
        'desc'         => $desc,
        'buyNowPrice'  => $buyNow === '' ? '0.00' : number_format((float)$buyNow, 2, '.', ''),
        'current'      => number_format($current, 2, '.', ''),
        'endTime'      => $endIso,
        'status'       => $status
      ];
    }
  }
}

add_from_xml($xmlP, $now, $cat, $q, $itemsById);
add_from_xml($xmlF, $now, $cat, $q, $itemsById);

// sort by soonest ending
$items = array_values($itemsById);
usort($items, function($a, $b) {
  $ta = strtotime($a['endTime']); if ($ta === false) $ta = 0;
  $tb = strtotime($b['endTime']); if ($tb === false) $tb = 0;
  if ($ta == $tb) return 0;
  return ($ta < $tb) ? -1 : 1;
});

$noise = trim(ob_get_clean());
if ($noise !== '') $CAPTURED[] = strip_tags($noise);

$out = ['ok' => true, 'items' => $items];
if ($DEBUG) {
  $out['_debug'] = [
    'paths' => [
      'primary'  => ['path'=>$PRIMARY,  'status'=>$stP, 'items'=>$xmlP ? count($xmlP->Item) : 0],
      'fallback' => ['path'=>$FALLBACK, 'status'=>$stF, 'items'=>$xmlF ? count($xmlF->Item) : 0],
    ],
    'warnings' => $CAPTURED
  ];
}
if (!empty($CAPTURED) && !$DEBUG) {
  $out['ok'] = false;
  $out['error'] = 'Server warnings: ' . implode(' | ', $CAPTURED);
}

echo json_encode($out, JSON_UNESCAPED_SLASHES);
