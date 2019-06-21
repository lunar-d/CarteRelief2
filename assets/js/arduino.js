const SerialPort = require('serialport');
var arduinoCOMPort = "COM3";
const arduinoSerialPort = new SerialPort(arduinoCOMPort, {  
  baudRate: 9600
 });
 arduinoSerialPort.on('open',function() {
  console.log('Serial Port ' + arduinoCOMPort + ' is opened.');
});

/* var five = require("johnny-five"),
    board = new five.Board();

board.on("ready", function() {
  // Create an Led on pin 13
  var led = new five.Led(13);

  // Strobe the pin on/off, defaults to 100ms phases
  led.strobe();
});*/