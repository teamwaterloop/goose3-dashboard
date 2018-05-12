var serialport = require("serialport"); 
var SerialPort = serialport.SerialPort; 

var serialPort = new SerialPort("port name", {
  baudrate: 9600,
  parser: serialport.parsers.readline("\n")
});



// serialPort.on("open", function () {
//   console.log('open');
//   serialPort.on('data', function(data) {
//     console.log(data);
//   });
// });



function write() //for writing
{
    serialPort.on('data', function (data) 
    {
        serialPort.write("Write your data here");
    });
}

function read () // for reading
{
    serialPort.on('data', function(data)
    {
        console.log(data); 
    });  
}

serialPort.on('open', function() 
{
    // execute your functions
    write(); 
    read(); 
});