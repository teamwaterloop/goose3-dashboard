
// Set up the serialport connection
var serialport = require("serialport"); 
var SerialPort = serialport.SerialPort; 

var serialPort = new SerialPort("port name", {
  baudrate: 9600,
  parser: serialport.parsers.readline("\n")
});

//Set up the websockets connection
var WebSocketServer = require('websocket').server;
var http = require('http');
 
var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(8080, function() {
    console.log((new Date()) + ' Server is listening on port 8080');
});


server.on('request', function(r){
    var connection = request.accept('pod-data', request.origin);
    console.log((new Date()) + ' Connection accepted.');
    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log('Received Message: ' + message.utf8Data);
            connection.sendUTF(message.utf8Data);
        }
        
    });
    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
    });
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
    	wsServer.emit(data) 
        console.log(data); 
    });  
}

serialPort.on('open', function() 
{
    // execute your functions
    //write(); 
    read(); 
});