<%if request("show")="big" then
response.write "<img src=showpic.asp?id="&request("id")&">"
else%>
<!--#include file="conn.asp"-->
<%
set rs=server.createobject("adodb.recordset")
sql="select * from download where id="&request("id")         
rs.open sql,conn,1,1
response.redirect rs("images")
rs.close                               
set rs=nothing                               
conn.close                               
set conn=nothing%>
<%end if%>
















