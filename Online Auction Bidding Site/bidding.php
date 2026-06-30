<?php
session_start();
if (!isset($_SESSION['customer_id'])) {
  header('Location: login.htm');
  exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>ShopOnline - Bidding</title>
<meta name="viewport" content="width=device-width,initial-scale=1">
<style>
  :root{
    --fg:#1f2937;--muted:#6b7280;--border:#e5e7eb;
    --brand:#0b5ed7;--ok:#0a7a0a;--err:#b00020;
    --panel:#f9fafb;--white:#fff;
  }
  *{box-sizing:border-box}
  body{font-family:Segoe UI,Roboto,Arial,sans-serif;margin:0;background:#f3f4f6;color:var(--fg)}
  .header{background:var(--white);border-bottom:1px solid var(--border);padding:10px 20px;text-align:center}
  .title{font-weight:700;font-size:22px;margin:6px 0}
  .nav{display:flex;gap:10px;justify-content:center;margin:8px 0}
  .btn{appearance:none;border:1px solid var(--border);background:var(--white);
       padding:8px 14px;border-radius:8px;cursor:pointer}
  .btn:hover{background:#f5f5f5}
  .btn.active{box-shadow:0 0 0 2px #e0e7ff inset;background:#eef2ff}
  .wrap{max-width:900px;margin:25px auto;padding:0 18px}
  .note{text-align:center;color:var(--muted);margin-bottom:10px}
  .card{background:var(--white);border:1px solid var(--border);border-radius:8px;
        padding:14px 16px;margin-bottom:16px;box-shadow:0 1px 3px rgba(0,0,0,0.05)}
  .card h3{margin:0 0 6px 0;color:#111}
  .row{margin:2px 0}
  .timeleft{color:#0b5ed7;font-style:italic;margin-top:4px}
  .actions{margin-top:8px}
  .actions button{margin-right:6px;border:none;border-radius:6px;padding:6px 12px;cursor:pointer}
  .bid{background:#0b5ed7;color:#fff}
  .buy{background:#198754;color:#fff}
  #msg{text-align:center;margin:10px 0;font-weight:500}
</style>
</head>
<body>
<header class="header">
  <div class="title">ShopOnline</div>
  <div class="nav">
    <button class="btn" onclick="location.href='home.htm'">Home</button>
    <button class="btn" onclick="location.href='listing.htm'">Listing</button>
    <button class="btn active" onclick="location.href='bidding.php'">Bidding</button>
    <button class="btn" onclick="location.href='maintenance.htm'">Maintenance</button>
    <button class="btn" onclick="location.href='logout.php'">Log Out</button>
  </div>
</header>

<div class="wrap">
  <div class="note">
    <p><b>Current auction items are listed below.</b><br>
    To place a bid or buy an item, use the buttons below.<br>
    <i>NOTE: Item remaining time and prices update every 5 seconds.</i></p>
  </div>

  <div id="list"></div>
  <div id="msg"></div>
</div>

<script src="bidding_new.js?v=20251026" defer></script>
</body>
</html>
