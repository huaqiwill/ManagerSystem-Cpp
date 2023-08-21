<%@ Language=VBScript %>
<%
  if session("admin")="" then
  response.redirect "admin.asp"
  else
	if session("flag")>1 then
		response.write "<br><p align=center>您没有操作的权限</p>"
		response.end
	end if
  end if
%>
<!--#include file="conn.asp"-->
<%
   user=LCase(Request("user"))
   password=LCase(Request("newpin"))
   'right_class=CInt(Request("right_class"))

   Set rs=Server.CreateObject("Adodb.RecordSet")
   
   rs.Open "Select * from [user] where [user]='"&user&"'",conn

   if not rs.EOF then

   Response.Write "<font color=red><div align=center><br><br>该用户名已经存在</div></font>"
   Response.End   

   end if
   rs.close
   sql="select * from [user]"
   rs.open sql,conn,1,3
   rs.addnew
   rs("user")=user
   rs("password")=password
   'rs("flag")=right_class
   rs.update
   rs.Close
   set rs=Nothing
   
   conn.Close
   set conn=Nothing

   Response.Redirect "adminuser1.asp"
%>