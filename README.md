# thirsty-plant

This project contains source code for a Arduino + RaspberryPi plant watering system.

It is a simple client-server system, where the Arduino listens and responds to commands from the RaspberryPi.

The RaspberryPi hosts a simple web page containing a user interface to control the system.
The Pi  communicates with the Arduino via a serial interface using the PHP-Serial library.
