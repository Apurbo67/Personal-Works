<?php
/* Kazi Apurbo | 105950524 */
session_start();
require 'config.php';

if (!isset($_SESSION['email'])) {
  
  if (isset($_GET['email']) && $_GET['email'] !== '') {
    $_SESSION['email'] = $_GET['email'];
  } else {
    header('Location: login.php');
    exit;
  }
}
$customerEmail = $_SESSION['email'];

$error = '';
$okay  = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  
  $email   = $customerEmail; // always use the logged-in customer's email
  $pname   = trim(isset($_POST['passenger_name']) ? $_POST['passenger_name'] : '');
  $pphone  = trim(isset($_POST['passenger_phone']) ? $_POST['passenger_phone'] : '');
  $unit    = trim(isset($_POST['unit_no']) ? $_POST['unit_no'] : '');
  $stno    = trim(isset($_POST['street_no']) ? $_POST['street_no'] : '');
  $stname  = trim(isset($_POST['street_name']) ? $_POST['street_name'] : '');
  $suburb  = trim(isset($_POST['suburb']) ? $_POST['suburb'] : '');
  $dest    = trim(isset($_POST['dest_suburb']) ? $_POST['dest_suburb'] : '');
  $pdate   = trim(isset($_POST['pickup_date']) ? $_POST['pickup_date'] : '');
  $ptime   = trim(isset($_POST['pickup_time']) ? $_POST['pickup_time'] : '');

  if ($pname==='' || $pphone==='' || $stno==='' || $stname==='' || $suburb==='' || $dest==='' || $pdate==='' || $ptime==='') {
    $error = 'All fields except unit number are required.';
  } else {
    /* pickup time 40mins from the booking */
    $pickupString = $pdate . ' ' . $ptime . ':00';
    $pickupTs     = strtotime($pickupString);
    $nowTs        = time();

    if ($pickupTs === false) {
      $error = 'Please enter a valid pickup date and time.';
    } elseif ($pickupTs - $nowTs < 40 * 60) {
      $error = 'Pickup time must be at least 40 minutes from now.';
    } else {
      /* Create booking */
      $ref      = strtoupper(substr(uniqid('BRN'), 0, 10));
      $bookedAt = date('Y-m-d H:i:s');
      $pickupAt = date('Y-m-d H:i:s', $pickupTs);

      $sql = "INSERT INTO booking
        (booking_ref,email,passenger_name,passenger_phone,unit_no,street_no,street_name,suburb,dest_suburb,pickup_datetime,booking_datetime,status)
        VALUES (?,?,?,?,?,?,?,?,?,?,?,'unassigned')";
      $st = mysqli_prepare($conn, $sql);
      mysqli_stmt_bind_param(
        $st, 'sssssssssss',
        $ref, $email, $pname, $pphone, $unit, $stno, $stname, $suburb, $dest, $pickupAt, $bookedAt
      );

      if (mysqli_stmt_execute($st)) {
        /* Required confirmation message (keep wording) */
        $okay = "Thank you! Your booking reference number is $ref. ".
                "The pick up of the passengers will be in front of your provided address at ".
                date('H:i', $pickupTs)." on ".date('Y-m-d', $pickupTs).".";

        
        
        $from = '105950524@student.swin.edu.au';
        $to = $email;
        $subject = 'Your booking request with CabsOnline!';
        $message = "Dear $pname, Thanks for booking with CabsOnline! Your booking reference number is $ref. ".
                   "We will pick up the passengers in front of your provided address at ".
                   date('H:i', $pickupTs)." on ".date('Y-m-d', $pickupTs).".";

        $headers  = "From: $from\r\n";
        $headers .= "Reply-To: $from\r\n";
        $headers .= "MIME-Version: 1.0\r\n";
        $headers .= "Content-Type: text/plain; charset=UTF-8\r\n";

       
        $queued = @mail($to, $subject, $message, $headers, "-f $from");
        if (!$queued) { @mail($to, $subject, $message, $headers, "-r $from"); }
      } else {
        $error = 'Could not save your booking. Please try again.';
      }
    }
  }
}
?>
<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title>CabsOnline Booking</title>
  <style>
    .sid{position:fixed;top:8px;right:12px;font:12px monospace;opacity:.6}
    .bar{margin-bottom:10px}
    input{margin:3px 0}
  </style>
</head>
<body>
<div class="sid">Kazi 105950524</div>

<div class="bar">
  Logged in as: <?php echo esc($customerEmail); ?> |
  <a href="logout.php">Logout</a>
</div>

<h2>CabsOnline Booking</h2>

<?php if ($error): ?><p style="color:red"><?php echo esc($error); ?></p><?php endif; ?>
<?php if ($okay):  ?><p style="color:green"><?php echo esc($okay); ?></p><?php endif; ?>

<form method="post">
  Passenger Name:<br>
  <input name="passenger_name" value="<?php echo esc(isset($_POST['passenger_name'])?$_POST['passenger_name']:''); ?>"><br>

  Contact Phone:<br>
  <input name="passenger_phone" value="<?php echo esc(isset($_POST['passenger_phone'])?$_POST['passenger_phone']:''); ?>"><br>

  Unit No (optional):<br>
  <input name="unit_no" value="<?php echo esc(isset($_POST['unit_no'])?$_POST['unit_no']:''); ?>"><br>

  Street No:<br>
  <input name="street_no" value="<?php echo esc(isset($_POST['street_no'])?$_POST['street_no']:''); ?>"><br>

  Street Name:<br>
  <input name="street_name" value="<?php echo esc(isset($_POST['street_name'])?$_POST['street_name']:''); ?>"><br>

  Suburb:<br>
  <input name="suburb" value="<?php echo esc(isset($_POST['suburb'])?$_POST['suburb']:''); ?>"><br>

  Destination Suburb:<br>
  <input name="dest_suburb" value="<?php echo esc(isset($_POST['dest_suburb'])?$_POST['dest_suburb']:''); ?>"><br>

  Pick-up Date (YYYY-MM-DD):<br>
  <input name="pickup_date" placeholder="2025-09-14" value="<?php echo esc(isset($_POST['pickup_date'])?$_POST['pickup_date']:''); ?>"><br>

  Pick-up Time (HH:MM 24h):<br>
  <input name="pickup_time" placeholder="14:30" value="<?php echo esc(isset($_POST['pickup_time'])?$_POST['pickup_time']:''); ?>"><br><br>

  <button type="submit">Submit Booking</button>
</form>
</body>
</html>
