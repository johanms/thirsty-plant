
<?php
echo "<h1>";
echo "Level: ";
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
echo " %";
echo "</br>";

echo "Moisture: ";
$serial->sendMessage("M");
$data = $serial->readPort();
echo $data;
echo " %";
echo "</br>";
$serial->deviceClose();

if (!empty($_GET['waterPlant'])) {
$serial->deviceOpen();
$serial->sendMessage("W");
$serial->deviceClose();
echo "Plant Watered!</br>";
}
echo "</h1>";
?>
<html>
<head>
</head>
<body>
<form action "index.php" method="get">
	<input type="hidden" name="waterPlant" value="run">
	<input type="submit" value="Water Plant">
</form>
</body>
</html>
