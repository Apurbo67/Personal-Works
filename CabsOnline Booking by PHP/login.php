<?php
/* Kazi Apurbo | 105950524 */
require 'config.php';

$msg = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  $email = trim(isset($_POST['email']) ? $_POST['email'] : '');
  $pw    = isset($_POST['password']) ? $_POST['password'] : '';

  if ($email === '' || $pw === '') {
    $msg = 'Please enter email and password.';
  } else {
    $sql = "SELECT passwd FROM customer WHERE email = ?";
    $st  = mysqli_prepare($conn, $sql);
    mysqli_stmt_bind_param($st, 's', $email);
    mysqli_stmt_execute($st);
    mysqli_stmt_bind_result($st, $dbpw);

    if (mysqli_stmt_fetch($st) && $pw === $dbpw) {
      header('Location: booking.php?email=' . rawurlencode($email));
      exit;
    } else {
      $msg = 'Login failed. Check your details.';
    }
  }
}
?>
<!doctype html>
<html>
<head>
  <meta charset="utf-8">
  <title>Login</title>
  <style>.sid{position:fixed;top:8px;right:10px;font:12px monospace;opacity:.7}</style>
</head>
<body>
<div class="sid">Kazi 105950524</div>
<h2>Customer Login</h2>

<?php if ($msg): ?>
  <p style="color:red;"><?php echo esc($msg); ?></p>
<?php endif; ?>

<form method="post">
  Email:<br>
  <input name="email" value="<?php echo esc(isset($_POST['email']) ? $_POST['email'] : ''); ?>"><br>
  Password:<br>
  <input type="password" name="password"><br><br>
  <button type="submit">Click to Login</button>
</form>

<p>New customer? <a href="register.php">Register here</a>.</p>
</body>
</html>
