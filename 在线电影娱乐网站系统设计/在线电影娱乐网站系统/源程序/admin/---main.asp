<%
  	if session("admin")="" then
  		response.redirect "admin.asp"
  	end if
%>
<html>

<head>
<link rel="stylesheet" href="style.css">
</head>

<BODY bgcolor="#009458">
<P>&nbsp;</P><table border="0" cellspacing="1" width="80%" align=center bgcolor="#a5d0dc">
    <tr>
      
<td width="100%">
      <p align=center><b>视频管理系统管理页面</b></p>
      <p><b>管理员可进行操作说明</b>：<br>
        <br>
        1，对已经添加影片修改或删除，请点左边相关连接进行操作。操作用户：超级用户，普通管理员 <br>
        <br>
        2，对影片栏目进行添加修改删除，请点左边相关连接进行操作。操作用户：超级用户 <br>
        <br>
        3，用户的增加修改删除，请点左边相关连接进行操作。操作用户：超级用户 <br>
        <br>
        4，<font color=red>为了系统的安全性，离开管理请点击退出系统</font> </p>
      </td>
    </tr>
</table>
</html>