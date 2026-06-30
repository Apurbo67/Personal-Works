<?php

header('Content-Type: text/plain; charset=UTF-8');
session_start();

if (!isset($_SESSION['customer_id'])) { echo "Sorry, your bid is not valid."; exit; }
$customerID = $_SESSION['customer_id'];

$itemID = isset($_POST['itemID']) ? trim($_POST['itemID']) : (isset($_GET['itemID']) ? trim($_GET['itemID']) : '');
$amount = isset($_POST['amount']) ? trim($_POST['amount']) : (isset($_GET['amount']) ? trim($_GET['amount']) : '');
if ($itemID === '' || $amount === '' || !is_numeric($amount)) { echo "Sorry, your bid is not valid."; exit; }
$bid = round((float)$amount, 2);
if ($bid <= 0) { echo "Sorry, your bid is not valid."; exit; }

// Resolve data file (primary then fallback)
$PRIMARY  = '/home/students/accounts/s105950524/cos80021/www/data/auction.xml';
$FALLBACK = __DIR__ . '/data/auction.xml';
$xmlPath  = is_file($PRIMARY) ? $PRIMARY : (is_file($FALLBACK) ? $FALLBACK : $PRIMARY);
@mkdir(dirname($xmlPath), 0777, true);
if (!is_file($xmlPath)) @file_put_contents($xmlPath, "<Auctions/>");

libxml_use_internal_errors(true);
$xml = simplexml_load_file($xmlPath);
if (!$xml) { echo "Sorry, your bid is not valid."; exit; }

// Find item
$it = null;
foreach ($xml->Item as $n) {
  if ((string)$n->ItemID === $itemID) { $it = $n; break; }
}
if (!$it) { echo "Sorry, your bid is not valid."; exit; }

// Check status & time
$status = strtoupper((string)$it->Status ?: 'OPEN');
$endTs  = strtotime((string)$it->EndTime) ?: 0;
if ($status !== 'OPEN' || ($endTs && $endTs <= time())) { echo "Sorry, your bid is not valid."; exit; }

// Current price
$startPrice = (float)$it->StartPrice;
$highestBid = (float)$it->HighestBid;
$current    = max($startPrice, $highestBid);

// Validate strictly higher
if ($bid <= $current) { echo "Sorry, your bid is not valid."; exit; }

// Append bid & update highest
if (!isset($it->Bids)) { $it->addChild('Bids'); }
$rec = $it->Bids->addChild('Bid');
$rec->addChild('BidderID', $customerID);
$rec->addChild('Amount', number_format($bid, 2, '.', ''));
$rec->addChild('Time', gmdate('c'));

$it->HighestBid      = number_format($bid, 2, '.', '');
$it->HighestBidderID = $customerID;

// Save
$dom = dom_import_simplexml($xml)->ownerDocument;
$dom->formatOutput = true;
$dom->save($xmlPath);

// Spec message
echo "Thank you! Your bid is recorded in ShopOnline.";
