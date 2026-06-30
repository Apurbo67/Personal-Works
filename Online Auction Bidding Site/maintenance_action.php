<?php
header('Content-Type: application/json; charset=UTF-8');
session_start();

$PRIMARY  = '/home/students/accounts/s105950524/cos80021/www/data/auction.xml';
$FALLBACK = __DIR__ . '/data/auction.xml';

function loadXmlPath() {
  global $PRIMARY, $FALLBACK;
  if (is_file($PRIMARY)) return $PRIMARY;
  if (is_file($FALLBACK)) return $FALLBACK;
  // create primary if nothing exists
  @mkdir(dirname($PRIMARY), 0777, true);
  @file_put_contents($PRIMARY, "<Auctions/>");
  return $PRIMARY;
}
function loadXml($path) {
  libxml_use_internal_errors(true);
  $xml = simplexml_load_file($path);
  return $xml ?: simplexml_load_string("<Auctions/>");
}
function saveXml($xml, $path) {
  $dom = dom_import_simplexml($xml)->ownerDocument;
  $dom->formatOutput = true;
  $dom->save($path);
}

$action = isset($_POST['action']) ? $_POST['action'] : '';
$now = time();
$path = loadXmlPath();
$xml  = loadXml($path);

if ($action === 'process') {
  $processed = $sold = $failed = 0;
  foreach ($xml->Item as $it) {
    $status = strtoupper((string)$it->Status ?: 'OPEN');
    if ($status !== 'OPEN') continue;

    $endTs = strtotime((string)$it->EndTime) ?: 0;
    if ($endTs > $now) continue; // not expired

    $processed++;
    $highest = (float)$it->HighestBid;
    $reserve = (float)$it->ReservePrice;

    if ($highest >= $reserve) {
      $it->Status = 'SOLD'; $sold++;
    } else {
      $it->Status = 'FAILED'; $failed++;
    }
  }
  saveXml($xml, $path);
  echo json_encode(['ok'=>true,'processed'=>$processed,'sold'=>$sold,'failed'=>$failed]); exit;
}

if ($action === 'report') {
  $remove = isset($_POST['remove']) && $_POST['remove'] === '1';
  $items = [];
  $soldCount = 0; $failedCount = 0; $revenue = 0.0;

  // collect sold/failed
  foreach ($xml->Item as $idx => $it) {
    $status = strtoupper((string)$it->Status);
    if ($status !== 'SOLD' && $status !== 'FAILED') continue;

    $item = [
      'id'      => (string)$it->ItemID,
      'title'   => (string)$it->Title,
      'category'=> (string)$it->Category,
      'seller'  => (string)$it->SellerID,
      'price'   => (float)$it->HighestBid,
      'reserve' => (float)$it->ReservePrice,
      'status'  => $status,
    ];
    $items[] = $item;

    if ($status === 'SOLD') { $soldCount++; $revenue += 0.04 * $item['price']; }
    else { $failedCount++; $revenue += 0.01 * $item['reserve']; }
  }

  // optionally remove them from XML
  $removed = false;
  if ($remove && count($items) > 0) {
    // rebuild <Auctions> excluding those items
    $new = new SimpleXMLElement('<Auctions/>');
    foreach ($xml->Item as $it) {
      $st = strtoupper((string)$it->Status);
      if ($st === 'SOLD' || $st === 'FAILED') continue;
      $dst = $new->addChild('Item');
      foreach ($it->children() as $k => $v) {
        $dst->addChild($k, (string)$v);
      }
      // copy nested Bids if present
      if (isset($it->Bids)) {
        $bids = $dst->addChild('Bids');
        foreach ($it->Bids->Bid as $b) {
          $nb = $bids->addChild('Bid');
          $nb->addChild('BidderID', (string)$b->BidderID);
          $nb->addChild('Amount', (string)$b->Amount);
          $nb->addChild('Time', (string)$b->Time);
        }
      }
    }
    saveXml($new, $path);
    $removed = true;
  } else {
    // just save original (no change)
    saveXml($xml, $path);
  }

  echo json_encode([
    'ok'=>true,
    'items'=>$items,
    'summary'=>['sold'=>$soldCount,'failed'=>$failedCount,'revenue'=>round($revenue,2)],
    'removed'=>$removed
  ]);
  exit;
}

echo json_encode(['ok'=>false,'error'=>'Unknown action.']);
