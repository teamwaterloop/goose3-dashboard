# goose3-dashboard
Dashboard code for Goose 3 Waterloop Pod

Qt-client contains the test project for the client side code for QT to communicate with the relay_server using JSON over UDP
and to send commands to the relay_server over TCP.

Qt-client:
  main.cpp - runs the console application to read data from relay server

  myudp.h 
  myudp.cpp - Receives UDP data and prints it. In the completed version with all relevent sensors, the data gets processed here.
  
  mytcp.h
  mytcp.cpp - Establishes a tcp connection to the relay_server and sends commands to relay_server. 
              Should be usable in the generic sense, and send any commands that the user deems necessary.

  Might add a few more files to help with data processing and graphing. Smoothing out of sensor data is also required for Pod stability UI features.
  
  
Python testing scripts for UDP and TCP respectively  
test-python tcp client-server
test-python udp client-server 


