<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>专题管理</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<script language="javascript">
<!--
   function test(form) {
       if ((form.options.value == "rename" && form.reTitle.value == "") || (form.options.value == "new" && form.newTitle.value == ""))
       {alert("您没有填写专题名称，请填写");return false;}
       if (form.options.value == "del")
       {return confirm("将同时删除该专题中的所有内容！是否继续？");}
       return true;
    }
//-->
</script>
<body bgcolor="#468ea3">
<br>
<form method="POST" action="classmana1.asp" align="center" language="javascript" onSubmit="return test(this);">
<input type="hidden" name="options" value>
  
 <table border="0" cellpadding="0" cellspacing="1" width="95%" align="center">

    <tr>
      
 <td align="center" bgcolor="#a5d0dc">
 <p>类别： 
  <select name="subject" size="1"
      style="font-size: 9pt">
<%
         Do while not rs.eof
             response.write "<option value='" +  Cstr(rs("classid")) + "'>" + rs("class") + "</option>"
             rs.MoveNext
         Loop
%>
      </select>
      <input type="submit" value="删除" name="B2" class=buttonface onClick="form.options.value='del'" >
 </td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#cce6ed">&nbsp;</td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#a5d0dc">
 <p>新名字：
<input type="text" name="reTitle" size="20" class=smallinput>
      <input type="submit" value="改名" name="B1" class=buttonface onClick="form.options.value='rename'">
      </td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#cce6ed">&nbsp;</td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#a5d0dc">
 <p>新类别：
<input type="text" name="newTitle" size="20" class=smallinput>
      <input type="submit" value="新增" name="B3" class=buttonface onClick="form.options.value='new'"></td>
    </tr>
  </table>
</form>

<form method="POST" action="classmana2.asp" align="center" language="javascript" onSubmit="return test(this);">
<input type="hidden" name="options" value>
  
 <table border="0" cellpadding="0" cellspacing="1" width="95%" align="center">
    <tr>
      
 <td align="center" height="22" bgcolor="#a5d0dc"><b>子专题管理</b></td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#cce6ed">&nbsp;</td>
    </tr>
    <tr>
      
 <td align="center" bgcolor="#a5d0dc">
 <p>子专题： 
  <select name="subject" size="1"
      style="font-size: 9pt">
<%
         Do while not rs2.eof
             response.write "<option value='" +  Cstr(rs2("Nclassid")) + "'>" + rs2("Nclass") + "</option>"
             rs2.MoveNext
         Loop
%>
      </select>
      <input type="submit" value="删除" name="B2" class=buttonface onClick="form.options.value='del'">
 </td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#cce6ed">&nbsp;</td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#a5d0dc">
 <p>专题修改：
<input type="text" name="reTitle" size="20"  class=smallinput>
在 <select name="classid" size="1"
      style="font-size: 9pt">
<%
         rs.MoveFirst
         Do while not rs.eof
             response.write "<option value='" +  Cstr(rs("classid")) + "'>" + rs("class") + "</option>"
             rs.MoveNext
         Loop
%>
      </select> 中 
      <input type="submit" value="改名" name="B1" class=buttonface onClick="form.options.value='rename'"><br>(请选择上方相应子类别,然后输入新名字和选择类别)
      </td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#cce6ed">&nbsp;</td>
    </tr>
    <tr align="center">
      
 <td bgcolor="#a5d0dc">
 <p>新专题：
<input type="text" name="newTitle" size="20"  class=smallinput>
      在 <select name="psubject" size="1"
      style="font-size: 9pt">
<%
         rs.MoveFirst
         Do while not rs.eof
             response.write "<option value='" +  Cstr(rs("classid")) + "'>" + rs("class") + "</option>"
             rs.MoveNext
         Loop
%>
      </select> 中
      <input type="submit" value="新增" name="B3" class=buttonface onClick="form.options.value='new'"></td>
    </tr>
  </table>
</form>
</body>
</html>
<% 
     rs.close
     rs2.close
     conn.close
     set conn=nothing
end if
%>