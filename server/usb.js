var serialport = require("serialport"); 
var SerialPort = serialport.SerialPort; 

var serialPort = new SerialPort("port name", {
  baudrate: 9600,
  parser: serialport.parsers.readline("\n")
});