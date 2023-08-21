<%
if session("admin")="" then
  response.redirect "admin.asp"
end if
%>
<!--#include file="conn.asp"-->
<!--#include file="../inc/const.asp"-->
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<title>添 加 下 载 视 频</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<%
dim rs
dim sql
dim count
set rs=server.createobject("adodb.recordset")
sql = "select * from Nclass order by Nclassid asc"
rs.open sql,conn,1,1
%><SCRIPT language = "JavaScript">
var onecount;
onecount=0;
subcat = new Array();
        <%
        count = 0
        do while not rs.eof 
        %>
subcat[<%=count%>] = new Array("<%= trim(rs("Nclass"))%>","<%= trim(rs("classid"))%>","<%= trim(rs("Nclassid"))%>");
        <%
        count = count + 1
        rs.movenext
        loop
        rs.close
        %>
onecount=<%=count%>;

function changelocation(locationid)
    {
    document.myform.Nclassid.length = 0; 

    var locationid=locationid;
    var i;
    for (i=0;i < onecount; i++)
        {
            if (subcat[i][1] == locationid)
            { 
                document.myform.Nclassid.options[document.myform.Nclassid.length] = new Option(subcat[i][0], subcat[i][2]);
            }        
        }
        
    }    
</SCRIPT>
<SCRIPT language="javascript">
<!--
function CheckForm()
{
	document.myform.txtcontent.value=document.myform.doc_html.value;
	return true
}
//-->
</SCRIPT>
<body bgcolor=#009458>
<form method="POST" name="myform" action="adminsave.asp?action=add">
  <TABLE width="602" border="0" align="center" cellspacing="1">
    <TR align="center"> 
      <TD colspan="4" height="25" bgcolor="#145f74" width="594"><b><FONT color="#FFFFFF">添 
        加 下 载 视 频</FONT></b></TD>
    </TR>
    <TR> 
      <TD align="right" width="76" nowrap bgcolor="#A5D0DC" height="30"><B><font color="#FF0000">影片类型</font>：</B></TD>
      <TD width="225" bgcolor="#A5D0DC" height="30"> 
        <%
        sql = "select * from class"
        rs.open sql,conn,1,1
	if rs.eof and rs.bof then
	response.write "请先添加栏目。"
	response.end
	else
%>
        <SELECT name="classid" onChange="changelocation(document.myform.classid.options[document.myform.classid.selectedIndex].value)" size="1">
          <OPTION selected value="">==请选类型==</OPTION>
          <% 
        do while not rs.eof
%>
          <OPTION value="<%=trim(rs("classid"))%>"><%=trim(rs("class"))%></OPTION>
          <%
        rs.movenext
        loop
	end if
        rs.close
        set rs = nothing
        conn.Close
        set conn = nothing
%>
        </SELECT>
      </TD>
      <TD align="right" width="76" bgcolor="#A5D0DC" height="30"><B>选择分类：</B></TD>
      <TD width="225" bgcolor="#A5D0DC" height="30"> 
        <SELECT name="Nclassid">
          <OPTION selected value="">==请选分类==</OPTION>
        </SELECT>
      </TD>
    </TR>
    <tr> 
      <td width="76" align="right" height="30" nowrap bgcolor="#CCE6ED"><b><font color="#FF0000">影片名称</font>：</b></td>
      <td width="225" height="30" bgcolor="#CCE6ED"> 
        <input type="text" name="txtshowname" size="33"              
          class="smallinput" maxlength="100">
      </td>
      <td width="76" height="30" bgcolor="#CCE6ED"> 
        <p align="right"><b>影片版本：</b>
      </td>
      <td width="225" height="30" bgcolor="#CCE6ED"> 
        <input type="text" name="txtbb" size="33"             
          class="smallinput" maxlength="100">
      </td>
    </tr>
    <tr> 
      <td width="76" align="right" height="14" nowrap bgcolor="#A5D0DC">电影格式:</td>
      <td width="450" height="14" colspan="3" bgcolor="#A5D0DC"> [<img border="0" src="../images/rm.gif"> 
        <input type="radio" value="rm" name="movie" checked>
        ]&nbsp; [<img border="0" src="../images/win.gif"> 
        <input type="radio" value="win" name="movie">
        ]&nbsp; [不是电影 
        <input type="radio" value="" name="movie">
        ]&nbsp;&nbsp;&nbsp; 如果是在线电影请选择播放格式</td>
    </tr>
    <tr> 
      <td width="76" align="right" height="15" nowrap bgcolor="#A5D0DC">会员：</td>
      <td width="450" height="15" colspan="3" bgcolor="#A5D0DC">是否会员 
        <input type="checkbox" name="club" value="on">&nbsp;如果选择会员，只有会员才可观看</td>
    </tr>
    <tr> 
      <td width="76" align="right" height="30" nowrap bgcolor="#cce6ed"><b><font color="#FF0000">下载地址1</font>：</b></td>
      <td width="450" height="30" colspan="3" bgcolor="#cce6ed"> 
        <input type="text" name="txtfilename" size="82"            
          class="smallinput" maxlength="100" value="<%=downdir1%>">
      </td>
    </tr>
    <tr> 
      <td width="76" align="right" height="30" nowrap bgcolor="#a5d0dc"><b>下载地址2：</b></td>
      <td width="450" height="30" colspan="3" bgcolor="#a5d0dc"> 
        <input type="text" name="txtfilename1" size="82"               
          class="smallinput" maxlength="100" value="">
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="76" align="right" height="30" nowrap><b>下载地址3：</b></td>
      <td width="450" height="30" colspan="3"> 
        <input type="text" name="txtfilename2" size="82"               
          class="smallinput" maxlength="100" value="">
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="76" align="right" height="30" nowrap bgcolor="#A5D0DC"><b>推荐度：</b></td>
      <td width="450" height="30" colspan="3" bgcolor="#A5D0DC"> 1星. 
        <input type="radio" value="1" name="hot">
        &nbsp;&nbsp;&nbsp; 2星. 
        <input type="radio" value="2" name="hot">
        &nbsp;&nbsp;&nbsp; 3星. 
        <input type="radio" value="3" name="hot" checked>
        &nbsp;&nbsp;&nbsp; 4星. 
        <input type="radio" value="4" name="hot">
        &nbsp;&nbsp;&nbsp; 5星. 
        <input type="radio" value="5" name="hot">
        <!--<input type="text" name="hot" size="60" class="smallinput" maxlength="100" value="3">-->
      </td>
    </tr>
    <tr> 
      <td width="76" align="right" height="30" nowrap bgcolor="#CCE6ED"><b>影片大小：</b></td>
      <td width="225" height="30" bgcolor="#CCE6ED"> 
        <!--<input type="text" name="system" size="60" class="smallinput" maxlength="100" value="Win98/2000+PWS4&NT+IIS4/5">-->
        <input type="text" name="size" size="20"               
          class="smallinput" maxlength="100" value="K">
      </td>
      <td width="76" height="30" bgcolor="#CCE6ED" align="right"> 
        <p align="right"><b>运行环境：</b> 
      </td>
      <td width="225" height="30" bgcolor="#CCE6ED"> 
        <select name="system" size="1">
          <option value="Win9x/WinNT/Win2000/WinME" name="system">Win9x/WinNT/Win2000/WinME</option>
          <option value="Win9x/WinNT/Win2000" name="system">Win9x/WinNT/Win2000</option>
          <option value="Windows9x/NT" name="system">Win9x/WinNT</option>
          <option value="Win9x/WinME" name="system">Win9x/WinME</option>
          <option value="WinNT/Win2000" name="system">WinNT/Win2000</option>
          <option value="ASP环境" name="system">ASP环境</option>
          <option value="PHP环境" name="system">PHP环境</option>
          <option value="CGI环境" name="system">CGI环境</option>
          <option value="JSP环境" name="system">JSP环境</option>
          <option value="Linux环境" name="system">Linux环境</option>
        </select>
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="76" align="right" height="30" nowrap bgcolor="#A5D0DC"><b>相关链接：</b></td>
      <td width="225" height="30" bgcolor="#A5D0DC"> 
        <input type="text" name="fromurl" size="33"               
          class="smallinput" maxlength="100" value="">
      </td>
      <td width="76" height="30" align="right" bgcolor="#A5D0DC"><B>影片图片：</B></td>
      <td width="225" height="30" bgcolor="#A5D0DC"> 
        <INPUT type="text" name="images" size="33"               
          class="smallinput" maxlength="160">
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="76" align="right" height="30" nowrap><b>授权形式：</b></td>
      <td width="450" height="30" colspan="3"> 
        <select name="order" size="1">
          <option selected value="共享影片" name="order">共享影片</option>
          <option value="免费影片" name="order">免费影片</option>
          <option value="商业影片" name="order">商业影片</option>
        </select>
        <!--<input type="text" name="order" size="60" class="smallinput" maxlength="100" value="免费">-->
        是否推荐 
        <input type="checkbox" name="hots" value="on">
        是否精品 
        <input type="checkbox" name="hide" value="on">
        <font color="#FF0000">（如果选择最好加上图片地址，在首页显示）</font></td>
    </tr>
    <tr> 
      <td width="76" align="right" valign="top" nowrap bgcolor="#a5d0dc"><b><font color="#FF0000">影片简介：</font></b></td>
      <td width="450" colspan="3" bgcolor="#a5d0dc"> <FONT color="#FF0000"> 
        <textarea rows="6" name="txtnote" cols="82" class="smallarea"></textarea>
        </FONT></td>
    </tr>
  </TABLE>               
<div align="center"><center><p><input type="submit" value=" 添 加 "               
  name="cmdok" class="buttonface">&nbsp; <input type="reset" value=" 清 除 "               
  name="cmdcancel" class="buttonface"></p>               
  </center></div>               
</form>               
</body>               
</html>               
