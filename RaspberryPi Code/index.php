<?php
if (!empty($_GET['ledOn'])) {
error_reporting(E_ALL);
ini_set('display_errors', '1');
include "php_serial.class.php";
$serial = new phpSerial;
$serial->deviceSet("/dev/ttyAMA0");
$serial->confBaudRate(9600);
$serial->confParity("none");
$serial->confCharacterLength(8);
$serial->confStopBits(1);
$serial->deviceOpen();
$serial->sendMessage("T");
$serial->deviceClose();
}
if (!empty($_GET['ledOff'])) {
error_reporting(E_ALL);
ini_set('display_errors', '1');
include "php_serial.class.php";
$serial = new phpSerial;
$serial->deviceSet("/dev/ttyAMA0");
$serial->confBaudRate(9600);
$serial->confParity("none");
$serial->confCharacterLength(8);
$serial->confStopBits(1);
$serial->deviceOpen();
$serial->sendMessage("F");
$serial->deviceClose();
}
?>
<html>
<head>
</head>
<body>
<form action="index.php" method="get">
  <input type="hidden" name="ledOn" value="run">
  <input type="submit" value="Turn On Led!">
</form>
<form action="index.php" method="get">
  <input type="hidden" name="ledOff" value="run">
  <input type="submit" value="Turn Off Led!">
</form>

</body>
</html>