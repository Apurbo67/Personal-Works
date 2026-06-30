<?php
header('Content-Type: application/json; charset=utf-8');
$PRIMARY  = '/home/students/accounts/s105950524/cos80021/www/data/auction.xml';
$FALLBACK = __DIR__ . '/data/auction.xml';

function loadXml($p){
  if (!is_file($p)) return null;
  libxml_use_internal_errors(true);
  return simplexml_load_file($p) ?: null;
}

$cats = ['All'];
foreach ([loadXml($PRIMARY), loadXml($FALLBACK)] as $xml){
  if (!$xml) continue;
  foreach ($xml->Item as $it){
    $c = trim((string)$it->Category);
    if ($c !== '' && !in_array($c, $cats, true)) $cats[] = $c;
  }
}
echo json_encode($cats);
