<html>
<head>
</head>
<link rel="stylesheet" href="html.css">
<%
if session("admin") = "" and session("flag") = "" then
    response.write "   <br><br><br>"
    response.write "    <table align='center' width='300' border='1' cellpadding='0' cellspacing='0' bordercolor='#999999'>"
    response.write "      <tr bgcolor='#999999'> "
    response.write "        <td colspan='2' height='15'> "
    response.write "          <div align='center'><font color='#FFFFFF'>操作: 确认身份失败!</font></div>"
    response.write "        </td>"
    response.write "      </tr>"
    response.write "      <tr> "
    response.write "        <td colspan='2' height='23'> "
    response.write "          <div align='center'><br><br>"
    response.write "      非法登陆,您的操作已经被记录!!! <br><br>"
    response.write "        <a href='javascript:onclick=history.go(-1)'>返回</a>"        
    response.write "        <br><br></div></td>"
    response.write "      </tr>   </table>" 
    response.end
end if    
%>
<title>管理专区</title>
<frameset framespacing="0" border="false" cols="110,*" frameborder="0">
<frame name="left"  scrolling="auto" marginwidth="0" marginheight="0" src="left.asp">
<frame name="right" scrolling="auto" marginwidth="0" marginheight="0" src="main.asp">
  </frameset>
  <noframes>
  <body>
  <p>This page uses frames, but your browser doesn't support them.</p>
  </body>
  </noframes>
</html>