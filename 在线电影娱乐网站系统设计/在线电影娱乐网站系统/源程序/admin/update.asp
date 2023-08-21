<!------更新新数据库---------->
<!--#include file="conn.asp"-->
<%
	sql="update download set dayhits=0,weekhits=0,lasthits=date(),stop=0,hots=0 where ID>=1"
	conn.Execute(sql)
	response.write "success"
%>