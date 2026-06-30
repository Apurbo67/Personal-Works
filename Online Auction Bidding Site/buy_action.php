<?php

header('Content-Type: text/plain; charset=UTF-8');
session_start();

if (!isset($_SESSION['customer_id'])) { echo "Sorry, purchase failed."; exit; }
$customerID = $_SESSION['customer_id'];

$itemID = isset($_POST['itemID']) ? trim($_POST['itemID']) : (isset($_GET['itemID']) ? trim($_GET['itemID']) : '');
if ($itemID === '') { echo "Sorry, purchase failed."; exit; }

// Resolve data file
$PRIMARY  = '/home/students/accounts/s105950524/cos80021/www/data/auction.xml';
$FALLBACK = __DIR__ . '/data/auction.xml';
$xmlPath  = is_file($PRIMARY) ? $PRIMARY : (is_file($FALLBACK) ? $FALLBACK : $PRIMARY);
@mkdir(dirname($xmlPath), 0777, true);
if (!is_file($xmlPath)) @file_put_contents($xmlPath, "<Auctions/>");

libxml_use_internal_errors(true);
$xml = simplexml_load_file($xmlPath);
if (!$xml) { echo "Sorry, purchase failed."; exit; }

// Find item
$it = null;
foreach ($xml->Item as $n) {
  if ((string)$n->ItemID === $itemID) { $it = $n; break; }
}
if (!$it) { echo "Sorry, purchase failed."; exit; }

// Check status
$status = strtoupper((string)$it->Status ?: 'OPEN');
if ($status !== 'OPEN') { echo "Sorry, purchase failed."; exit; }

$buyNow = (float)((string)$it->BuyNowPrice !== '' ? $it->BuyNowPrice : 0);
$it->HighestBid      = number_format($buyNow, 2, '.', '');
$it->HighestBidderID = $customerID;
$it->Status          = 'SOLD';

// Save
$dom = dom_import_simplexml($xml)->ownerDocument;
$dom->formatOutput = true;
$dom->save($xmlPath);

// Spec message
echo "Thank you for purchasing this item.";
