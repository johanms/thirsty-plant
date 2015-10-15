<html>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<head>
</head>
<body>
<h1>Bonsai Life Support</h1>
<h2>Status:</h2>
<?php
echo "Tank Level: ";
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

echo "Soil Moisture: ";
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
?>
<body>
<h2>Controls:</h2>
</br>
<form action "index.php" method="get">
	<input type="hidden" name="waterPlant" value="run">
	<div style="text-align: center">
		<input type="submit" value="Water" style="font-size: 120%; width: 40%; height: 20%">
	</div>
</form>
</body>
</html>
