<!--#include file="conn.asp"-->
<%
set rs=server.createobject("adodb.recordset")
sql="select * from download where id="&request("id")         
rs.open sql,conn,1,1
%>
<%
if session("user")="" and rs("club")<>"" then
%>
<script>alert('对不起！此为会员程序，请注册成我们的会员！');window.close();</script>
<%else 	  
if request("downid")="2" then
url=rs("filename1")
elseif request("downid")="3" then
url=rs("filename2")
else
url=rs("filename")
end if
%>
<head>
<title>在线点播</title>
<meta http-equiv=Content-Type content="text/html; charset=gb2312">
<style type=text/css>
td{font-size:9pt;line-height:13pt}
a:link{color:#FFFF00;text-decoration:none}
a:visited{color:#FFFF00;text-decoration:none}
a:hover{color:#FFFF00;text-decoration:underline}</style>
</head>

<body bgcolor="#000000" text="#FFFFFF" topmargin="0" leftmargin="0">
<table border="0" width="610" cellspacing="1" cellpadding="0" bgcolor="#3F3F3F">
  <tr>
    <td width="450" valign="top">
<object ID="video2" CLASSID="clsid:CFCDAA03-8BE4-11cf-B84B-0020AFBBCCFA" HEIGHT="340" WIDTH="450">
  <param name="_ExtentX" value="11906">
  <param name="_ExtentY" value="8996">
  <param name="AUTOSTART" value="-1">
  <param name="SHUFFLE" value="0">
  <param name="PREFETCH" value="0">
  <param name="NOLABELS" value="0">
  <param name="SRC" value="<%=url%>">
  <param name="CONTROLS" value="ImageWindow">
  <param name="CONSOLE" value="Clip1">
  <param name="LOOP" value="0">
  <param name="NUMLOOP" value="0">
  <param name="CENTER" value="0">
  <param name="MAINTAINASPECT" value="0">
  <param name="BACKGROUNDCOLOR" value="#000000"><embed SRC="4.rpm" type="audio/x-pn-realaudio-plugin" CONSOLE="Clip1" CONTROLS="ImageWindow" HEIGHT="240" WIDTH="352" AUTOSTART="false"></object>
<object ID="video1" CLASSID="clsid:CFCDAA03-8BE4-11cf-B84B-0020AFBBCCFA" HEIGHT="60" WIDTH="450">
  <param name="_ExtentX" value="11906">
  <param name="_ExtentY" value="1588">
  <param name="AUTOSTART" value="-1">
  <param name="SHUFFLE" value="0">
  <param name="PREFETCH" value="0">
  <param name="NOLABELS" value="0">
  <param name="CONTROLS" value="ControlPanel,StatusBar">
  <param name="CONSOLE" value="Clip1">
  <param name="LOOP" value="0">
  <param name="NUMLOOP" value="0">
  <param name="CENTER" value="0">
  <param name="MAINTAINASPECT" value="0">
  <param name="BACKGROUNDCOLOR" value="#000000"><embed type="audio/x-pn-realaudio-plugin" CONSOLE="Clip1" CONTROLS="ControlPanel,StatusBar" HEIGHT="60" WIDTH="275" AUTOSTART="false"></object>
</td>
    <td width="160" valign="top">

      <table border="0" width="100%" cellpadding="0" height="318">
        <tr>
          <td width="100%" height="17">
            <p align="center"><b>《<%=rs("showname")%>&nbsp;<%=rs("bb")%>》</b></td>
        </tr>
        <tr>
          <td width="100%" height="51">
            <p align="center">
<img src="images/rm.gif" align="absmiddle" width="16" height="16">&nbsp; <%if rs("filename")<>"" then%><a href=playrm.asp?id=<%=rs("id")%>&downid=1><%if request("downid")=1 then%><b><font color="#00FF00"><%end if%>[1]</font></b></a><%end if%>        
<%if rs("filename1")<>"" then%><a href=playrm.asp?id=<%=rs("id")%>&downid=2><%if request("downid")=2 then%><b><font color="#00FF00"><%end if%>[2]</font></b></a><%end if%>           
<%if rs("filename2")<>"" then%><a href=playrm.asp?id=<%=rs("id")%>&downid=3><%if request("downid")=3 then%><b><font color="#00FF00"><%end if%>[3]</font></b></a><%end if%>           
          </td>    
        </tr>    
        <tr>    
          <td width="100%" bgcolor="#808080" height="17"></td>   
        </tr>   
        <tr>   
          <td width="100%" height="119">如果出现这错误信息：“Server has reached its capacity and can serve no more streams. Please try again later.”<br>请多<a href=playrm.asp?id=<%=rs("id")%>&downid=<%=request("downid")%>>刷新</a>几次就可以了。</td>    
        </tr>    
        <tr>    
          <td width="100%" bgcolor="#808080" height="17" align="center"></td>   
        </tr>   
        <tr> 
          <td width="100%" align="center" height="30"></td>     
        </tr> 
        <tr> 
          <td width="100%" align="center" height="17"></td>     
        </tr> 
        <tr> 
          <td width="100%" bgcolor="#808080" height="17" align="center"></td>     
        </tr> 
        <tr> 
          <td width="100%" height="15">播放器下载：<a href="http://vod.kk66.com/mp71cn.exe"><img src="images/win.gif" align="absmiddle" width="18" height="17" border="0"></a> 
           </td>   
        </tr>
      </table>  
      <p align="center"><a target="_blank" href="http://www.k666.com/"> </a>
    </td>      
  </tr>      
</table>      
<%rs.close      
set rs=nothing      
conn.close      
set conn=nothing%>
<%end if%>