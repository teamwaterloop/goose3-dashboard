
// Set up the serialport connection
var SerialPort = require('serialport');

var serialPort = new SerialPort("/dev/cu.usbmodem14431", {
  baudRate: 9600,
  //parser: new SerialPort.parsers.Readline("\n")
}, false);

//Set up the websockets connection
var WebSocketServer = require('websocket').server;
var http = require('http');
 
var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
});
server.listen(8080, function() {
    console.log((new Date()) + ' Server is listening on port 8080');
});

wsServer = new WebSocketServer({ httpServer: server});

wsServer.on('request', function(r){
    var connection = r.accept(null, r.origin);
    console.log((new Date()) + ' Connection accepted.');
    connection.on('message', function(message) {
    	console.log(message.type);
        if (message.type === 'utf8') {
            console.log('Received Message: ' + message.utf8Data);
            connection.sendUTF(message.utf8Data);
        }
        
    });
    setInterval(function(){
            connection.sendUTF(JSON.stringify({"name":"John", "age":30, "car":null}));
        }, 1000);
    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
    });
});


serialPort.on('data', function (data) {
	//var _data =  JSON.stringify(data);

  console.log(data.toString("utf8"));
  wsServer.emit({"name":"John", "age":30, "car":null});
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
        serialPort.write();
    });
}

function read () // for reading
{
    serialPort.on('data', function(data)
    {
    	wsServer.emit({"name":"John", "age":30, "car":null});
        console.log(data); 
    });  
}

//serialPort.on('open', function() 
//{
    // execute your functions
    //write(); 
//    read(); 
//});