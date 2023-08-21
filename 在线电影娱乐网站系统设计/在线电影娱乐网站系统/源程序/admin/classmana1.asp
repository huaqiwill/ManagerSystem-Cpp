<%@ LANGUAGE="VBSCRIPT" %>
<!--#include file="conn.asp"-->
<%
  if session("admin")="" then
  response.redirect "admin.asp"
  else
	if session("flag")>1 then
		response.write "<br><p align=center>您没有操作的权限</p>"
		response.end
	end if
  end if

   dim sql
   dim rs
   dim cmdTemp
   
   select case request.form("options")
     case "rename"
       on error resume next
       Set cmdTemp = Server.CreateObject("ADODB.Command")
       set rs=server.createobject("adodb.recordset")
       cmdTemp.CommandText = "SELECT * FROM class where classid=" & request.form("subject")
       cmdTemp.CommandType = 1
       Set cmdTemp.ActiveConnection = conn   
       rs.Open cmdTemp, , 1, 3
       if err.Number<>0 then
            err.clear
            response.write " 数 据 库 操 作 失 败 ! "
       else
         rs("class") = request.form("reTitle")
         rs.Update
         rs.Close
         set rs=nothing
         set cmdTemp=nothing
         finished
       end if
     case "del"
	Rem 删除栏目
        sql="delete from class where classid=" & request.form("subject")
        conn.execute sql
	Rem 删除相关栏目下子栏目
        sql="delete from Nclass where classid=" & request.form("subject")
        conn.execute sql
	Rem 删除相关栏目对应影片信息
        sql="delete from download where classid=" & request.form("subject")
        conn.execute sql
        if err.Number<>0 then
            err.clear
            response.write " 数 据 库 操 作 失 败 ! "
        else
            finished
        end if
     case "new"
       on error resume next
       Set cmdTemp = Server.CreateObject("ADODB.Command")
       set rs=server.createobject("adodb.recordset")
       cmdTemp.CommandText = "SELECT * FROM class where (classid IS NULL)"
       cmdTemp.CommandType = 1
       Set cmdTemp.ActiveConnection = conn   
       rs.Open cmdTemp, , 1, 3
       if err.Number<>0 then
            err.clear
            response.write " 数 据 库 操 作 失 败 ! "
       else
         rs.AddNew
         rs("class") = request.form("newTitle")
         rs.Update
         rs.Close
         set rs=nothing
         set cmdTemp=nothing
         finished
       end if
   end select

   sub finished()
     %>
<html>
<head>
<title>修改成功</title>
<meta http-equiv="refresh" content='0; URL=classmana.asp'>
</head>
<body>
<p align="center"><b>类别修改成功！</b></p>

<%
 end sub
%>