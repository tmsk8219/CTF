  <!DOCTYPE html>
<html>
  <head>
    <title>Simple Auth</title>
  </head>
  <body>
    <div>
<?php
$password = 'FLAG_????????????????';
if (isset($_POST['password']))
    if (strcasecmp($_POST['password'], $password) == 0)
        echo "Congratulations! The flag is $password";
    else
        echo "incorrect...";
?>
    </div>
    <form method="POST" action="http://ctfq.sweetduet.info:10080/~q32/auth.php">
      <input type="password" name="password">
      <input type="submit">
    </form>
  </body>
</html>
