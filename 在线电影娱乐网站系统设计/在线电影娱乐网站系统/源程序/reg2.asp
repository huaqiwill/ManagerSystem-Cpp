<%PageName="UserRegPost"%>
<!--#include file="conn.asp"-->
<!--#include file="reg3.asp"-->
<!--#include file="topMain.asp"-->
<%
founderr=false

if request.form("User")="" or len(request.form("User"))>20 then
	errmsg=errmsg+"<br>"+"<li>用户名输入错误(未输入或长度超过了20个字节)。"
	founderr=true
else
	User=trim(request.form("User"))
end if
if request.form("sex")="" then
	errmsg=errmsg+"<br>"+"<li>请选择您的性别。"
	founderr=true
elseif request.form("sex")=0 or request.form("sex")=1 then
	sex=request.form("sex")
else
	errmsg=errmsg+"<br>"+"<li>您输入的字符非法。"
	founderr=true
end if
if request.form("password")="" or Len(request.form("password"))>20 then
	errmsg=errmsg+"<br>"+"<li>请输入您的密码(长度不能大于20)。"
	founderr=true
else
	password=request.form("password")
end if
if password<>request("password2") then
	errmsg=errmsg+"<br>"+"<li>您输入的密码和确认密码不一致。"
	founderr=true
end if
if IsValidEmail(trim(request.form("Email")))=false then
	errmsg=errmsg+"<br>"+"<li>您的Email有错误。"
	founderr=true
else
	Email=trim(request.form("Email"))
end if



if founderr=true then
	call error()
else
	set rs=server.createobject("adodb.recordset")
	sql="select * from user where user='"&user&"'"
	rs.open sql,conn,1,1
	if not rs.eof or user=WebName then
		errmsg="<br>"+"<li>对不起，您输入的用户名已经被注册，请重新输入。"
		founderr=true
	else
	rs.close
	set rs7=server.createobject("adodb.recordset")
	sql7="insert into user(user,password) values('"&user&"','"&password&"')"
rs7.open sql7,conn,3,3
	
	end if


	if founderr=true then
		call error()
	else
%>
<div align="center">
  <center>
<table cellpadding=0 cellspacing=0 border=1 width=760 bgcolor=#3399FF >
  <tr>
    <td align=center>　
        <TR align=middle bgcolor=#414141>
          <TD colSpan=2 height=39 bgcolor=#3399FF width="325">
          　</TD>
        </TR>
        <TR align=middle bgcolor=#414141>
          <TD colSpan=2 height=25 bgcolor=#FFCC99 width="325">
          <span style="font-size: 9pt">会员注册成功</span></TD>
        </TR>
        <TR>
          <TD width=120 align=right bgcolor="#FFFFFF" height="1">
          <span style="font-size: 9pt; font-weight: 700">注册名<span lang="zh-cn">：</span>&nbsp;
          </span></TD>
          <TD bgcolor="#FFFFFF" height="1" width="250"><%=user%><span style="font-size: 9pt">
          </span>　</TD>
        </TR>
        <TR>
          <TD align=right bgcolor="#FFFFFF" height="1">
          <span style="font-size: 9pt; font-weight: 700">性别<span lang="zh-cn">：</span></span></TD>
          <TD bgcolor="#FFFFFF" height="1" width="227"><%if sex=1 then%><span style="font-size: 9pt">男<%else%>女<%end if%></span></TD>
        </TR>
        <TR>
          <TD align=right bgcolor="#FFFFFF" height="1">
          <span style="font-size: 9pt; font-weight: 700">密码<span lang="zh-cn">：</span></span></TD>
          <TD bgcolor="#FFFFFF" height="1" width="227"><%=password%>　</TD>
        </TR>
        <TR>
          <TD align=right bgcolor="#FFFFFF" height="1">
          <span style="font-size: 9pt; font-weight: 700">Email<span lang="zh-cn">：</span></span></TD>
          <TD bgcolor="#FFFFFF" height="1" width="227"><%=email%>　</TD></TR>
        <TR>
          <TD align=right bgcolor="#FFFFFF" height="1">
          <span style="font-size: 9pt; font-weight: 700">OICQ<span lang="zh-cn">：</span></span></TD>
          <TD bgcolor="#FFFFFF" height="1" width="227"><%if request.form("oicq")="" then%><span style="font-size: 9pt">未注册<%else%><%=request.form("oicq")%><%end if%>
          </span> </TD>
        </TR>
              <TR>
          <TD align=center colSpan=2 bgcolor="#FFFFFF" height="8" width="325">
          <span style="font-size: 9pt"><a href="user.asp">会员登陆</a></span></TD>
        </TR>
              <TR>
          <TD align=center colSpan=2 bgcolor="#3399FF" height="50" width="325">
          　</TD>
        </TR>
      </TABLE>
    <br>
  
  </center>
</div>

<!--#include file="CopyRight.asp"-->
</html>
<%
	end if
	set rs=nothing
end if
conn.close
set conn=nothing
%>