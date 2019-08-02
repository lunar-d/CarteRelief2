const express = require('express');
const app = express();
const SerialPort = require('serialport')

//web port
var port = 3000;

//serial port
const ArduinoSerialPort = new SerialPort('COM11', {
    baudRate: 9600
  })

//serial est on
ArduinoSerialPort.on('open',function() {
  console.log('Serial Port is opened.');
});

app.get('/', function (req, res) {

    return res.send('Working');
 
})


//action = led
app.get('/:action', function (req, res) {
    
   var action = req.params.action || req.param('action');  
   var mot = action;//num led
   var motchar = String.fromCharCode(mot);
   ArduinoSerialPort.write(motchar);  
   console.log('Action: ' + action);
   return res.send('Action: ' + action);
   
 
});

app.listen(port, function () {
  console.log('Example app listening on port http://localhost:' + port + '!');
});

