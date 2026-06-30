<?php

header('Content-Type: text/html; charset=UTF-8');

session_start();
if (!isset($_SESSION['customer_id'])) {
  echo '<span class="err">You must be logged in to list an item.</span>';
  exit;
}
$sellerID = $_SESSION['customer_id'];

// inputs
$title   = isset($_GET['title']) ? trim($_GET['title']) : '';
$cat     = isset($_GET['cat']) ? trim($_GET['cat']) : '';
$desc    = isset($_GET['desc']) ? trim($_GET['desc']) : '';
$start   = isset($_GET['start']) ? trim($_GET['start']) : '';
$reserve = isset($_GET['reserve']) ? trim($_GET['reserve']) : '';
$buy     = isset($_GET['buy']) ? trim($_GET['buy']) : '';
$dur_s   = isset($_GET['dur_s']) ? intval($_GET['dur_s']) : 0;

if ($title==='' || $cat==='' || $start==='' || $reserve==='' || $dur_s<=0) {
  echo '<span class="err">Missing or invalid data.</span>'; exit;
}

// Paths (primary + fallback)
$DATA_PRIMARY  = '/home/students/accounts/s105950524/cos80021/www/data/auction.xml'; // /www/data/
$DATA_FALLBACK = __DIR__ . '/data/auction.xml'; // /htdocs/Project2/data/
$xmlPath = null;

$tryPaths = [$DATA_PRIMARY, $DATA_FALLBACK];
foreach ($tryPaths as $p) {
  @mkdir(dirname($p), 0777, true);
  if (!is_file($p)) @file_put_contents($p, "<Auctions/>");
  if (is_file($p) && is_writable($p)) { $xmlPath = $p; break; }
}
if ($xmlPath === null) {
  echo '<span class="err">Server cannot write auction.xml. Check permissions.</span>'; exit;
}

// Load/create XML
$doc = new DOMDocument();
$doc->preserveWhiteSpace = false;
$doc->formatOutput = true;
if (file_exists($xmlPath)) {
  $doc->load($xmlPath);
  $root = $doc->documentElement;
} else {
  $doc = new DOMDocument('1.0','UTF-8');
  $doc->formatOutput = true;
  $root = $doc->createElement('Auctions');
  $doc->appendChild($root);
}

// Next ID
function nextItemId($doc){
  $ids = $doc->getElementsByTagName('ItemID');
  $max = 0;
  foreach ($ids as $n) { $v = preg_replace('/\D/','',$n->textContent); $max = max($max, intval($v)); }
  return 'I' . str_pad(strval($max+1), 6, '0', STR_PAD_LEFT);
}
$itemID = nextItemId($doc);

// Times
$startTime = gmdate('c');
$endTime   = gmdate('c', time() + $dur_s);

// Build node
$item = $doc->createElement('Item');
$add = function($name,$val) use($doc,$item){ $el=$doc->createElement($name); $el->appendChild($doc->createTextNode($val)); $item->appendChild($el); };

$add('ItemID', $itemID);
$add('SellerID', $sellerID);
$add('Title', $title);
$add('Category', $cat);
$add('Description', $desc);
$add('StartPrice', number_format((float)$start,2,'.',''));
$add('ReservePrice', number_format((float)$reserve,2,'.',''));
$add('BuyNowPrice', $buy!=='' ? number_format((float)$buy,2,'.','') : '');
$add('StartTime', $startTime);
$add('EndTime', $endTime);
$add('HighestBid', '0.00');
$add('HighestBidderID', '');
$add('Status', 'OPEN');
$item->appendChild($doc->createElement('Bids'));

$root->appendChild($item);
$doc->save($xmlPath);

echo '<span class="ok">Item created successfully. Item ID: <b>' .
      htmlspecialchars($itemID,ENT_QUOTES,'UTF-8') . '</b></span>';
