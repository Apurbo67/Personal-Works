<?php
/* Kazi Apurbo | 105950524 */
$host = 'feenix-mariadb.swin.edu.au';
$user = 'YOUR_DB_USER';
$pass = 'YOUR_DB_PASSWORD';
$db   = 'YOUR_DB_NAME';

$conn = mysqli_connect($host, $user, $pass, $db);
/* Connection error */
if (!$conn) {
  die('Sorry, cannot connect to database: ' . mysqli_connect_error());
}


function esc($txt) {
  if (!isset($txt)) {
    $txt = '';
  }
  return htmlspecialchars($txt, ENT_QUOTES, 'UTF-8');
}
