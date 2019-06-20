const SerialPort = require('serialport');
var arduinoCOMPort = "COM11";
const arduinoSerialPort = new SerialPort(arduinoCOMPort, {  
  baudRate: 9600
 });