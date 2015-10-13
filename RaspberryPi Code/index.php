
<?php
echo "Level: ";
if (!empty($_GET['readLevel'])) {
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
$serial->sendMessage("L");
$data = $serial->readPort();
echo $data;
echo "</br>";
$serial->deviceClose();
}
else {
echo "-</br>";
}
echo "Moisture: ";
if (!empty($_GET['readMoist'])) {
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
$serial->sendMessage("M");
$data = $serial->readPort();
echo $data;
echo "</br>";
$serial->deviceClose();
}
else {
echo "-</br>";
}

if (!empty($_GET['waterPlant'])) {
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
$serial->sendMessage("W");
$serial->deviceClose();
echo "Plant Watered!</br>";
}

?>
<html>
<head>
</head>
<body>
<form action="index.php" method="get">
  <input type="hidden" name="readLevel" value="run">
  <input type="submit" value="Read Level" style="height:300px; width:600px">
</form>
<form action="index.php" method="get">
  <input type="hidden" name="readMoist" value="run">
  <input type="submit" value="Read Moisture" style="height:300px; width:600px">
</form>
<form action "index.php" method="get">
	<input type="hidden" name="waterPlant" value="run">
	<input type="submit" value="Water Plant" style="height:300px; width:600px">
</form>
</body>
</html>
