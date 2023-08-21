<!--#include file="conn.asp"-->
<HTML>
<HEAD>

  <TITLE>-用户登录</TITLE>
</HEAD>
<!--#include file="topMain.asp"-->
<body bgcolor="#efefef" leftmargin="0" topmargin="0">
    <div align="center">
      <center>
    <table border="0" cellpadding="0" cellspacing="0"  bordercolor="#6699FF" width="770" height="232" bgcolor="#6699FF">
      <tr>
        <td width="201" height="105" rowspan="2">
        　</td>
        <td width="260" height="88" colspan="2">
        <p align="center">
		<form method="post" action="users.asp">
		<%
if session("user")<>"" then%>
<%
  dim rs
  set rs = server.createobject("adodb.recordset")
%>
                      <%sql="select * from [user] where [user]='"&session("user")&"'"
					  response.write sql
        rs.open sql,conn,3,3
        %>
  <p align="center">
  &nbsp;会员名<font color="#FF0000"><%=rs("user")%></font>登陆成功　<a href="logout.asp">注销登陆</a> <%rs.close%><%else%></td>
  <div align="center">
    <center>
</td>
        <td width="183" height="105" rowspan="2">
        　</td>
      </tr>
      <tr>
        <td width="260" height="25" colspan="2" bgcolor="#FFCC99">
        <p align="center">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 用户登录</td>
      </tr>
      <tr>
        <td width="302" height="23">
        　</td>
        <td width="120" height="23" bgcolor="#FFFFFF">
        <p align="right">&nbsp;<b><font color="#000000">会员名：</font></b> </td>
        <td width="250" height="23" bgcolor="#FFFFFF"><span lang="en-us">&nbsp;</span><input type="text" name="user" size="18" class="input1" style="font-family: Arial; height:18">
        <a href="reg1.asp">
        <font color="#0000FF"><u>免费注册</u></font></a></td>
        <td width="292" height="23">　</td>
      </tr>
      <tr>
        <td width="302" height="24">
        　</td>
        <td width="105" height="24" bgcolor="#FFFFFF">
        <p align="right">
<b>
<font color="#000000">密码</font>：</b> <%end if%></td>
        <td width="235" height="24" bgcolor="#FFFFFF"><span lang="en-us">&nbsp;</span><input type="password" name="password" size="18" class="input1" style="font-family: Arial; height:18"></td>
        <td width="292" height="24">　</td>
      </tr>
      <tr>
        <td width="302" height="104" rowspan="2">　</td>
        <td width="340" height="8" bgcolor="#FFFFFF" colspan="2" align="center">&nbsp;<input type="submit" value="确定" name="B3" class="input2" style="height: 16 width:44">&nbsp;
<input type="reset" value="重置" name="Submit22" class="input2" style="height: 16 width:44"></td>
        <td width="292" height="104" rowspan="2">　</td>
      </tr>
      <tr>
        <td width="340" height="69" bgcolor="#6699FF" colspan="2">　</td>
      </tr>
    </table>
      </center>
   </BODY>
<!--#include file="CopyRight.asp"-->
</HTML>