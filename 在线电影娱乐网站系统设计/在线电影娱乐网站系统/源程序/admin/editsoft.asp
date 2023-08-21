<%
  if session("admin")="" then
  response.redirect "admin.asp"
  else
	if session("flag")>2 then
		response.write "<br><p align=center>您没有操作的权限</p>"
		response.end
	end if
  end if
%>
<!--#include file="conn.asp"-->
<!--#include file="../inc/const.asp"-->
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<meta name="GENERATOR" content="Microsoft FrontPage 4.0">
<title>修 改 下 载 视 频</title>
<link rel="stylesheet" type="text/css" href="style.css">
</head>
<%
dim rs
dim sql
dim count
set rs=server.createobject("adodb.recordset")
sql = "select * from Nclass order by Nclassid asc"
rs.open sql,conn,1,1
%>
<SCRIPT language = "JavaScript">
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
<body bgcolor=#468ea3>
<form method="POST"  name="myform"  action="adminsave.asp?id=<%=request("id")%>&action=edit">
  <TABLE width="602" border="0" align="center" cellspacing="1">
    <TR align="center"> 
      <TD colspan="4" height="30" bgcolor="#145f74" width="594"><b><FONT color="#FFFFFF">修 
        改 下 载 视 频</FONT></b></TD>
    </TR>
    <tr> 
      <td width="75" align="right" valign="top" height="30" bgcolor="#a5d0dc"><b><font color="#FF0000">影片类型：</font></b></td>
      <td width="225" bgcolor="#a5d0dc" height="30"> 
        <SELECT name="classid" onChange="changelocation(document.myform.classid.options[document.myform.classid.selectedIndex].value)" size="1">
          <%dim classid,Nclassid
	classid=request("classid")
	Nclassid=request("Nclassid")
  sql="select * from class"
 	rs.open sql,conn,1,1
	if rs.eof and rs.bof then
		response.write "Not record."
	else
	do while not rs.eof
        if classid=cstr(rs("classid")) then
               sel="selected"
        else
               sel=""
        end if	
	response.write "<option " & sel & " value='"+CStr(rs("classID"))+"' name=classid>"+rs("class")+"</option>"+chr(13)+chr(10)
	rs.movenext
    	loop
	end if
	rs.close
%>
        </SELECT>
      </td>
      <td width="75" bgcolor="#a5d0dc" align="right" height="30"> <B>选择分类：</B> 
      </td>
      <td width="225" bgcolor="#a5d0dc" height="30"> 
        <SELECT name="Nclassid" size="1">
          <%             
  	sql="select * from Nclass"             
 	rs.open sql,conn,1,1             
	if rs.eof and rs.bof then             
		response.write "Not record."             
	else             
        do while not rs.eof             
        if Nclassid=cstr(rs("Nclassid")) then             
               sel="selected"             
        else             
               sel=""             
        end if	             
        response.write "<option " & sel & " value='" +  Cstr(rs("Nclassid")) + "'>" + rs("Nclass") + "</option>"             
        rs.MoveNext             
        Loop             
	end if             
        rs.close             
%>
        </SELECT>
      </td>
    </tr>
    <%             
	sql="select * from download where id="&request("id")             
	rs.open sql,conn,1,1             
%>
    <tr> 
      <td width="75" align="right" height="30" bgcolor="#CCE6ED"><b><font color="#FF0000">影片</font></b><font color="#FF0000"><b>名称：</b></font></td>
      <td width="225" height="30" bgcolor="#CCE6ED"> <FONT color="#FF0000"> 
        <input type="text" name="txtshowname" size="33"            
          class="smallinput" maxlength="100" value="<%=rs("showname")%>">
        </FONT></td>
      <td width="75" height="30" bgcolor="#CCE6ED" align="right"> <b>影片版本：</b></td>
      <td width="225" height="30" bgcolor="#CCE6ED"> <FONT color="#FF0000"> 
        <input type="text" name="txtbb" size="33"            
          class="smallinput" maxlength="100" value="<%=rs("bb")%>">
        </FONT> </td>
    </tr>
    <tr> 
      <td width="75" align="right" height="14" nowrap bgcolor="#A5D0DC">电影格式:</td>
      <td width="450" height="14" colspan="3" bgcolor="#A5D0DC"> [<img border="0" src="../images/rm.gif"> 
        <input type="radio" value="rm" name="movie"<%if rs("movie")="rm" then%> checked<%end if%>>
        ]&nbsp;&nbsp;&nbsp;&nbsp; [<img border="0" src="../images/win.gif"> 
        <input type="radio" value="win" name="movie"<%if rs("movie")="win" then%> <%end if%> checked>
        ]&nbsp;&nbsp;&nbsp; [不是电影 
        <input type="radio" value="" name="movie" >
        ]如果是在线电影请选择播放格式</td>
    </tr>
    <tr> 
      <td width="75" align="right" height="15" nowrap bgcolor="#A5D0DC">会员：</td>
      <td width="450" height="15" colspan="3" bgcolor="#A5D0DC">是否会员
<input type="checkbox" name="club" value="on" <%if rs("club")="1" then%> checked<%end if%>>&nbsp;如果选择会员，只有会员才可观看</td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="75" align="right" height="30"><b><font color="#FF0000">下载地址1</font>：</b></td>
      <td width="450" height="30" colspan="3"> 
        <input type="text" name="txtfilename" size="82"            
          class="smallinput" maxlength="100" value="<%=rs("filename")%>">
      </td>
    </tr>
    <tr> 
      <td width="75" align="right" height="30" bgcolor="#a5d0dc"><b>下载地址2：</b></td>
      <td width="450" height="30" bgcolor="#a5d0dc" colspan="3"> 
        <input type="text" name="txtfilename1" size="82"             
          class="smallinput" maxlength="100" value="<%=rs("filename1")%>">
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="75" align="right" height="30"><b>下载地址3：</b></td>
      <td width="450" height="30" colspan="3"> 
        <input type="text" name="txtfilename2" size="82"             
          class="smallinput" maxlength="100" value="<%=rs("filename2")%>">
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="75" align="right" height="30" bgcolor="#A5D0DC"><b>推荐度：</b></td>
      <td width="450" height="30" colspan="3" bgcolor="#A5D0DC"> 
        <select name="hot" size="1">
          <option <%if rs("hot")=1 then%> selected <%end if%> value="1" name="hot">一星级</option>
          <option <%if rs("hot")=2 then%> selected <%end if%> value="2" name="hot">二星级</option>
          <option <%if rs("hot")=3 then%> selected <%end if%> value="3" name="hot">三星级</option>
          <option <%if rs("hot")=4 then%> selected <%end if%> value="4" name="hot">四星级</option>
          <option <%if rs("hot")=5 then%> selected <%end if%> value="5" name="hot">五星级</option>
        </select>
        <!--<input type="text" name="hot" size="60" class="smallinput" maxlength="100" value="3">-->
      </td>
    </tr>
    <tr> 
      <td width="75" align="right" height="30" bgcolor="#CCE6ED"><b>影片大小：</b></td>
      <td width="225" height="30" bgcolor="#CCE6ED"> 
        <!--<input type="text" name="system" size="60" class="smallinput" maxlength="100" value="Win98/2000+PWS4&NT+IIS4/5">-->
        <input type="text" name="size" size="33"             
          class="smallinput" maxlength="100" value="<%if rs("size")<>"" then%><%=rs("size")%><%else%>K<%end if%>">
      </td>
      <td width="75" height="30" bgcolor="#CCE6ED" align="right"> <b>运行环境：</b> 
      </td>
      <td width="225" height="30" bgcolor="#CCE6ED"> 
        <select name="system" size="1">
          <option value="Win9x/WinNT/Win2000/WinME" selected name="system">Win9x/WinNT/Win2000/WinME</option>
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
      <td width="75" align="right" height="30" bgcolor="#A5D0DC"><b>影片来源：</b></td>
      <td height="30" bgcolor="#A5D0DC" width="225"> 
        <input type="text" name="fromurl" size="33"             
          class="smallinput" maxlength="100" value="<%=rs("fromurl")%>">
      </td>
      <td height="30" bgcolor="#A5D0DC" width="75" align="right"><B>影片图片：</B></td>
      <td height="30" bgcolor="#A5D0DC" width="225"> 
        <INPUT type="text" name="images" size="33"             
          class="smallinput" maxlength="160" value="<%=rs("images")%>">
      </td>
    </tr>
    <tr bgcolor="#cce6ed"> 
      <td width="75" align="right" height="30"><b>授权形式：</b></td>
      <td width="450" height="30" colspan="3"> 
        <select name="order" size="1">
          <option selected value="共享影片" name="order">共享影片</option>
          <option value="免费影片" name="order">免费影片</option>
          <option value="商业影片" name="order">商业影片</option>
        </select>
        <!--<input type="text" name="order" size="60" class="smallinput" maxlength="100" value="免费">-->
        是否推荐 
        <input type="checkbox" name="hots" value="on" <%if rs("hots")="1" then%> checked<%end if%>>
        是否精品
<input type="checkbox" name="hide" value="on" <%if rs("stop")="1" then%> checked<%end if%>>
      </td>
    </tr>
    <tr bgcolor="#a5d0dc"> 
      <td width="75" align="right" valign="top" height="30"><b><font color="#FF0000">影片简介</font>：</b></td>
      <td width="450" colspan="3" height="30"> 
        <textarea rows="6" name="txtnote" cols="82" class="smallarea"><%
	content=replace(rs("note"),"<br>",chr(13))
	content=replace(content,"&nbsp;"," ")
	response.write content
%></textarea>
      </td>
    </tr>
  </table>             
                       
  <div align="center"><center><p><input type="submit" value=" 修 改 "             
  name="cmdok" class="buttonface">&nbsp; <input type="reset" value=" 清 除 "             
  name="cmdcancel" class="buttonface"></p>             
  </center></div>             
</form>             
</body>             
</html>             
<%             
	set rs=nothing             
	conn.close             
	set conn=nothing             
%>