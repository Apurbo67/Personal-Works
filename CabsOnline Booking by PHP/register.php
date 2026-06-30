<?php
/* Kazi Apurbo | 105950524 */
require 'config.php';
$err = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  $name  = trim(isset($_POST['cust_name']) ? $_POST['cust_name'] : '');
  $email = trim(isset($_POST['email']) ? $_POST['email'] : '');
  $pass  = isset($_POST['password']) ? $_POST['password'] : '';
  $pass2 = isset($_POST['password2']) ? $_POST['password2'] : '';
  $phone = trim(isset($_POST['phone']) ? $_POST['phone'] : '');

  if ($name === '' || $email === '' || $pass === '' || $pass2 === '' || $phone === '') {
    $err = 'All fields are required.';
  } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    $err = 'Invalid email address.';
  } elseif ($pass !== $pass2) {
    $err = 'Passwords do not match, please try again.';
  } else {
    // use $conn from config.php 
    $stmt = mysqli_prepare($conn, 'SELECT 1 FROM customer WHERE email=?');
    mysqli_stmt_bind_param($stmt, 's', $email);
    mysqli_stmt_execute($stmt);
    mysqli_stmt_store_result($stmt);

    if (mysqli_stmt_num_rows($stmt) > 0) {
      $err = 'Email already registered.';
    } else {
      $ins = mysqli_prepare($conn, 'INSERT INTO customer(email, cust_name, passwd, phone) VALUES (?,?,?,?)');
      mysqli_stmt_bind_param($ins, 'ssss', $email, $name, $pass, $phone);
      if (mysqli_stmt_execute($ins)) {
        header('Location: booking.php?email=' . rawurlencode($email));
        exit;
      } else {
        $err = 'Registration failed.';
      }
    }
  }
}
?>
<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Register</title>
<style>.sid{position:fixed;top:8px;right:12px;font:12px/1 monospace;opacity:.7}</style>
</head>
<body>
<div class="sid">Kazi 105950524</div>
<h2>New Customer Registration</h2>

<?php if ($err): ?>
  <p style="color:red"><?php echo esc($err); ?></p>
<?php endif; ?>

<form method="post">
  Name: <input name="cust_name" value="<?php echo esc(isset($_POST['cust_name']) ? $_POST['cust_name'] : ''); ?>"><br>
  Email: <input name="email" value="<?php echo esc(isset($_POST['email']) ? $_POST['email'] : ''); ?>"><br>
  Phone: <input name="phone" value="<?php echo esc(isset($_POST['phone']) ? $_POST['phone'] : ''); ?>"><br>
  Password: <input type="password" name="password"><br>
  Re-type Password: <input type="password" name="password2"><br>
  <button type="submit">Register</button>
</form>

<p><a href="login.php">Already registered? Login</a></p>
</body>
</html>
