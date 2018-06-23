# Waterloop Goose 2 Showcase Event Dashboard

**For UI testing purposes:**

> pip3 install git+https://github.com/Pithikos/python-websocket-server

Visit https://github.com/Pithikos/python-websocket-server#api for more information on the WebsocketServer API
The script will send a json value to the UI to check if it updates correctly, and will also print received commands to the console.

run ws_server.py to test dashboard values

LOGGER CLASS:
	Logger(const QString &fileName, const QString &extension = "csv", const bool showDateTimePerLine = false, const bool dateTimeInFileName = true,QObject *parent = nullptr); 
	- fileName = name of destination file
	- extension = extension for destination file. Default is "csv"
	- showDateTimePerLine = if true, each line logged also includes the time
		and date
	- dateTimeInFileName = if true, the name of the destination file will
		include the date and time when the file was created. 
		This is useful since you won't be overwriting older files. The 
		Logger class overwrites rather than appends due to how 
		QSaveFile works.
		destination file
.
