<!--#include file="conn.asp"-->
<%
set rs=server.createobject("adodb.recordset")
sql="select * from download where id="&request("id")         
rs.open sql,conn,1,1
%>
<%
if session("user")="" and rs("club")<>"" then
%>
<script>
alert('对不起！此为会员影片，请在首页注册成我们的会员并登录！');
//document.location="reg1.asp"
window.close();
</script>
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
<table border="0" width="610" cellspacing="0" cellpadding="0" bgcolor="#3F3F3F">
  <tr>
    <td width="450" valign="top">
<object classid="clsid:22D6F312-B0F6-11D0-94AB-0080C74C7E95" id="MediaPlayer1" width="450" height="400">
                            <param name="AudioStream" value="-1">
        <param name="AutoSize" value="0">
        <param name="AutoStart" value="-1">
        <param name="AnimationAtStart" value="-1">
        <param name="AllowScan" value="-1">
        <param name="AllowChangeDisplaySize" value="-1">
        <param name="AutoRewind" value="0">
        <param name="Balance" value="0">
        <param name="BaseURL" value>
        <param name="BufferingTime" value="5">
        <param name="CaptioningID" value>
        <param name="ClickToPlay" value="-1">
        <param name="CursorType" value="0">
        <param name="CurrentPosition" value="-1">
        <param name="CurrentMarker" value="0">
        <param name="DefaultFrame" value>
        <param name="DisplayBackColor" value="0">
        <param name="DisplayForeColor" value="16777215">
        <param name="DisplayMode" value="0">
        <param name="DisplaySize" value="2">
        <param name="Enabled" value="-1">
        <param name="EnableContextMenu" value="-1">
        <param name="EnablePositionControls" value="-1">
        <param name="EnableFullScreenControls" value="0">
        <param name="EnableTracker" value="-1">
        
        <param name="Filename" value="<%=url%>">
        
        
        
        <param name="InvokeURLs" value="-1">
        <param name="Language" value="-1">
        <param name="Mute" value="0">
        <param name="PlayCount" value="1">
        <param name="PreviewMode" value="0">
        <param name="Rate" value="1">
        <param name="SAMILang" value>
        <param name="SAMIStyle" value>
        <param name="SAMIFileName" value>
        <param name="SelectionStart" value="-1">
        <param name="SelectionEnd" value="-1">
        <param name="SendOpenStateChangeEvents" value="-1">
        <param name="SendWarningEvents" value="-1">
        <param name="SendErrorEvents" value="-1">
        <param name="SendKeyboardEvents" value="0">
        <param name="SendMouseClickEvents" value="0">
        <param name="SendMouseMoveEvents" value="0">
        <param name="SendPlayStateChangeEvents" value="-1">
        <param name="ShowCaptioning" value="0">
        <param name="ShowControls" value="-1">
        <param name="ShowAudioControls" value="-1">
        <param name="ShowDisplay" value="0">
        <param name="ShowGotoBar" value="0">
        <param name="ShowPositionControls" value="-1">
        <param name="ShowStatusBar" value="-1">
        <param name="ShowTracker" value="-1">
        <param name="TransparentAtStart" value="0">
        <param name="VideoBorderWidth" value="0">
        <param name="VideoBorderColor" value="0">
        <param name="VideoBorder3D" value="0">
        <param name="Volume" value="-40">
        <param name="WindowlessVideo" value="0">
            </object>
</td>
    <td width="160" valign="top">

      <table border="0" width="100%" cellpadding="2">
        <tr>
          <td width="100%">
            <p align="center"><b>《<%=rs("showname")%>&nbsp;<%=rs("bb")%>》</b></td>
        </tr>
        <tr>
          <td width="100%">
            <p align="center">
<img src="images/win.gif" align="absmiddle" width="18" height="17">&nbsp; <%if rs("filename")<>"" then%><a href="playwin.asp?id=<%=rs("id")%>&amp;downid=1"><%if request("downid")=1 then%><b><font color="#00FF00"><%end if%>[1]</font></b></a><%end if%>            
<%if rs("filename1")<>"" then%><a href="playwin.asp?id=<%=rs("id")%>&amp;downid=2"><%if request("downid")=2 then%><b><font color="#00FF00"><%end if%>[2]</font></b></a><%end if%>               
<%if rs("filename2")<>"" then%><a href="playwin.asp?id=<%=rs("id")%>&amp;downid=3"><%if request("downid")=3 then%><b><font color="#00FF00"><%end if%>[3]</font></b></a><%end if%>              
          </td>       
        </tr>       
        <tr>       
          <td width="100%" bgcolor="#808080" height="2"></td>      
        </tr>      
        <tr>      
          <td width="100%">
          <p align="center">如果不能播放<br>请多<a href="playwin.asp?id=<%=rs("id")%>&amp;downid=<%=request("downid")%>">刷新</a>几次就可以了。</td>      
        </tr>      
        <tr>      
          <td width="100%" bgcolor="#808080" height="2"></td>     
        </tr>     
        <tr>     
          <td width="100%"></td>     
        </tr>     
        <tr>   
          <td width="100%"></td>     
        </tr>   
        <tr>   
          <td width="100%" bgcolor="#808080" height="2"></td>     
        </tr>   
        <tr>   
          <td width="100%">播放器下载：<a href="search.asp?action=title&amp;keyword=Windows Media Player" target="_blank"><img src="images/win.gif" align="absmiddle" width="18" height="17" border="0"></a> 
             <a href="search.asp?action=title&amp;keyword=RealPlayer" target="_blank"> 
<img src="images/rm.gif" align="absmiddle" width="18" height="17" border="0"></a></td>   
        </tr> 
      </table>   
      <p align="center">
    </td>       
  </tr>       
</table>       
<%rs.close       
set rs=nothing       
conn.close       
set conn=nothing%>
<%end if%>