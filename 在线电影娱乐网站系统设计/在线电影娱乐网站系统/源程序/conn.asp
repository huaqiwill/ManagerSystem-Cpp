<%
	dim conn
	dim dbpath
   	set conn=server.createobject("adodb.connection")
	   dbpath="DBQ="+server.mappath("vod.mdb")+";DefaultDir=;DRIVER={Microsoft Access Driver (*.mdb)};"
	conn.Open  dbpath
%>

