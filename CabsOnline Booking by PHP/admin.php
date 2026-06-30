<?php
/* Kazi Apurbo | 105950524 */
require 'config.php';

$notice = '';
$error  = '';
$rows   = [];

if (isset($_POST['list_now'])) {
  $now  = date('Y-m-d H:i:s');
  $soon = date('Y-m-d H:i:s', time() + 2 * 3600);

  $sql = "SELECT b.booking_ref, c.cust_name, b.passenger_name, b.passenger_phone,
                 b.unit_no, b.street_no, b.street_name, b.suburb, b.dest_suburb, b.pickup_datetime
          FROM booking b
          JOIN customer c ON b.email = c.email
          WHERE b.status = 'unassigned'
            AND b.pickup_datetime BETWEEN ? AND ?
          ORDER BY b.pickup_datetime ASC";

  $st = mysqli_prepare($conn, $sql);
  mysqli_stmt_bind_param($st, 'ss', $now, $soon);
  mysqli_stmt_execute($st);
  $res = mysqli_stmt_get_result($st);

  while ($r = mysqli_fetch_assoc($res)) {
    $rows[] = $r;
  }
}


if (isset($_POST['assign_ref'])) {
  $ref = trim($_POST['assign_ref']);
  if ($ref === '') {
    $error = 'Please type a booking reference.';
  } else {
    $u = mysqli_prepare($conn, "UPDATE booking SET status='assigned' WHERE booking_ref=? AND status='unassigned'");
    mysqli_stmt_bind_param($u, 's', $ref);
    mysqli_stmt_execute($u);

    if (mysqli_stmt_affected_rows($u) > 0) {
      $notice = "The booking request $ref has been properly assigned.";
    } else {
      $error = 'No unassigned booking with that reference (or already assigned).';
    }
  }
}


function short_addr($r) {
  $front = ($r['unit_no'] !== '' ? $r['unit_no'] . '/' : '') . $r['street_no'];
  return $front . ' ' . $r['street_name'] . ', ' . $r['suburb'];
}
?>
<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title>Admin</title>
  <style>
    .sid{position:fixed;top:8px;right:10px;font:12px monospace;opacity:.7}
    table{border-collapse:collapse;margin-top:10px}
    th,td{border:1px solid #555;padding:6px 10px}
  </style>
</head>
<body>
<div class="sid">Kazi 105950524</div>
<h2>CabsOnline Admin</h2>

<?php if ($notice): ?><p style="color:green;"><?php echo esc($notice); ?></p><?php endif; ?>
<?php if ($error):  ?><p style="color:red;"><?php echo esc($error); ?></p><?php endif; ?>

<form method="post" style="margin-bottom:10px;">
  <button name="list_now" value="1">Show Unassigned (next 2 hours)</button>
</form>

<form method="post">
  Assign this booking ref:&nbsp;
  <input name="assign_ref" placeholder="e.g., BRNABC1234">
  <button type="submit">Assign</button>
</form>

<?php if ($rows): ?>
  <table>
    <tr>
      <th>Ref</th><th>Customer</th><th>Passenger</th><th>Phone</th>
      <th>Pick-up Address</th><th>Destination</th><th>Pickup Date/Time</th>
    </tr>
    <?php foreach ($rows as $r): ?>
      <tr>
        <td><?php echo esc($r['booking_ref']); ?></td>
        <td><?php echo esc($r['cust_name']); ?></td>
        <td><?php echo esc($r['passenger_name']); ?></td>
        <td><?php echo esc($r['passenger_phone']); ?></td>
        <td><?php echo esc(short_addr($r)); ?></td>
        <td><?php echo esc($r['dest_suburb']); ?></td>
        <td><?php echo esc($r['pickup_datetime']); ?></td>
      </tr>
    <?php endforeach; ?>
  </table>
<?php endif; ?>
</body>
</html>
