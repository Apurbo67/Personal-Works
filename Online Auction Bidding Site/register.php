<?php
// handle registration request
header('Content-Type: text/html; charset=UTF-8');
session_start();

// get input values
$fname = isset($_GET['fname']) ? trim($_GET['fname']) : '';
$lname = isset($_GET['lname']) ? trim($_GET['lname']) : '';
$email = isset($_GET['email']) ? trim($_GET['email']) : '';
$pass  = isset($_GET['password']) ? trim($_GET['password']) : '';

if ($fname === '' || $lname === '' || $email === '' || $pass === '') {
  echo '<span class="err">Please fill all fields.</span>';
  exit;
}

// email validation pattern
$pattern = '/^(?!\.)(?!.*\.\.)[A-Za-z0-9!#$%&\'*+\-\/=?^_`{|}~.]+(?<!\.)@(?:[A-Za-z0-9](?:[A-Za-z0-9\-]{0,61}[A-Za-z0-9])?\.)+[A-Za-z]{2,}$/';
if (!preg_match($pattern, $email)) {
  echo '<span class="err">Invalid email format.</span>';
  exit;
}

if (strlen($pass) < 6) {
  echo '<span class="err">Password must be at least 6 characters.</span>';
  exit;
}

// locate XML file
$base = dirname(__FILE__);
$base = dirname($base);
$base = dirname($base);
$xmlPath = $base . '/data/customer.xml';

// load or create XML
if (file_exists($xmlPath)) {
  $doc = new DOMDocument();
  $doc->load($xmlPath);
  $root = $doc->documentElement;
} else {
  $doc = new DOMDocument('1.0', 'UTF-8');
  $doc->formatOutput = true;
  $root = $doc->createElement('Customers');
  $doc->appendChild($root);
}

// check duplicate email
$emails = $doc->getElementsByTagName('Email');
foreach ($emails as $node) {
  if (strcasecmp(trim($node->textContent), $email) === 0) {
    echo '<span class="err">This email is already registered.</span>';
    exit;
  }
}

// create customer id
function nextCustomerId($doc) {
  $ids = $doc->getElementsByTagName('ID');
  $max = 0;
  foreach ($ids as $idNode) {
    $num = preg_replace('/\D/', '', $idNode->textContent);
    $max = max($max, intval($num));
  }
  return 'C' . str_pad($max + 1, 6, '0', STR_PAD_LEFT);
}
$cid = nextCustomerId($doc);

// add new customer
$cust = $doc->createElement('Customer');
$root->appendChild($cust);

$elements = array(
  'ID' => $cid,
  'FirstName' => $fname,
  'LastName' => $lname,
  'Email' => $email,
  'Password' => $pass,
  'Created' => gmdate('c')
);
foreach ($elements as $tag => $val) {
  $el = $doc->createElement($tag);
  $el->appendChild($doc->createTextNode($val));
  $cust->appendChild($el);
}

$doc->save($xmlPath);

// send email
$to = $email;
$subject = 'Welcome to ShopOnline!';
$body = "Dear $fname, welcome to use ShopOnline! Your customer id is $cid and the password is $pass.";
$headers = "From: registration@shoponline.com.au\r\nReply-To: registration@shoponline.com.au\r\n";
$sent = @mail($to, $subject, $body, $headers);

// show result
if ($sent) {
  echo '<span class="ok">Registered successfully. A welcome email was sent to <b>' . htmlspecialchars($email) . '</b>. Your Customer ID is <b>' . htmlspecialchars($cid) . '</b>.</span>';
} else {
  echo '<span class="ok">Registered successfully. (Mail server not available.)<br>To: ' . htmlspecialchars($email) . '<br>Message: Dear ' . htmlspecialchars($fname) . ', welcome to use ShopOnline! Your customer id is <b>' . htmlspecialchars($cid) . '</b> and the password is <b>' . htmlspecialchars($pass) . '</b>.</span>';
}
?>
