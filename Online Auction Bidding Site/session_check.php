<?php
// return session info to JS
header('Content-Type: application/json; charset=UTF-8');
session_start();
$ok = isset($_SESSION['customer_id']) && $_SESSION['customer_id'] !== '';
echo json_encode($ok ? array(
  'ok'=>true,
  'id'=>$_SESSION['customer_id'],
  'name'=>isset($_SESSION['customer_name'])?$_SESSION['customer_name']:''
) : array('ok'=>false));
