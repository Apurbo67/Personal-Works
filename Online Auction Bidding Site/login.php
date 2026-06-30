<?php
// login
header('Content-Type: application/json; charset=UTF-8');
session_start();

// inputs
$email = isset($_POST['email']) ? trim($_POST['email']) : '';
$pass  = isset($_POST['password']) ? trim($_POST['password']) : '';

if ($email === '' || $pass === '') {
  echo json_encode(array('ok'=>false,'error'=>'Please enter email and password.'));
  exit;
}

// locate XML (primary /www/data, fallback project/data)
$wwwRoot = dirname(dirname(dirname(__FILE__)));     // .../www
$primary = $wwwRoot . '/data/customer.xml';
$fallback= dirname(__FILE__) . '/data/customer.xml';
$path = file_exists($primary) ? $primary : (file_exists($fallback) ? $fallback : '');

if ($path === '') {
  echo json_encode(array('ok'=>false,'error'=>'No customer data file.'));
  exit;
}

// load
$doc = new DOMDocument();
if (!@$doc->load($path)) {
  echo json_encode(array('ok'=>false,'error'=>'Cannot read customer data.'));
  exit;
}

// find user
$items = $doc->getElementsByTagName('Customer');
$found = false; $cid=''; $name='';
foreach ($items as $c) {
  $e = $c->getElementsByTagName('Email')->item(0);
  $p = $c->getElementsByTagName('Password')->item(0);
  if ($e && $p && strcasecmp(trim($e->textContent), $email)===0 && trim($p->textContent)===$pass){
    $id = $c->getElementsByTagName('ID')->item(0);
    $fn = $c->getElementsByTagName('FirstName')->item(0);
    $ln = $c->getElementsByTagName('LastName')->item(0);
    $cid = $id ? trim($id->textContent) : '';
    $name = (($fn?$fn->textContent:'').' '.($ln?$ln->textContent:''));
    $found = true;
    break;
  }
}

if (!$found) {
  echo json_encode(array('ok'=>false,'error'=>'Invalid email or password.'));
  exit;
}

// session
$_SESSION['customer_id'] = $cid;
$_SESSION['customer_name'] = trim($name);
$_SESSION['customer_email'] = $email;

echo json_encode(array('ok'=>true,'name'=>trim($name),'id'=>$cid));
