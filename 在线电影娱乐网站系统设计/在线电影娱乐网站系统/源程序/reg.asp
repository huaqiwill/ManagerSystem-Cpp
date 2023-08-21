<%
'---------------------检查用户名密码-------------------------------
function Checkin(s) 
s=trim(s) 
s=replace(s," ","&amp;nbsp;") 
s=replace(s,"'","&amp;#39;") 
s=replace(s,"""","&amp;quot;") 
s=replace(s,"&lt;","&amp;lt;") 
s=replace(s,"&gt;","&amp;gt;") 
Checkin=s 
end function 

'---------------------检查用户Email-------------------------------
function IsValidEmail(email)
IsValidEmail = true
names = Split(email, "@")
if UBound(names) <> 1 then
   IsValidEmail = false
   exit function
end if
for each name in names
   if Len(name) <= 0 then
     IsValidEmail = false
     exit function
   end if
   for i = 1 to Len(name)
     c = Lcase(Mid(name, i, 1))
     if InStr("abcdefghijklmnopqrstuvwxyz_-.", c) <= 0 and not IsNumeric(c) then
       IsValidEmail = false
       exit function
     end if
   next
   if Left(name, 1) = "." or Right(name, 1) = "." then
      IsValidEmail = false
      exit function
   end if
next
if InStr(names(1), ".") <= 0 then
   IsValidEmail = false
   exit function
end if
i = Len(names(1)) - InStrRev(names(1), ".")
if i <> 2 and i <> 3 then
   IsValidEmail = false
   exit function
end if
if InStr(email, "..") > 0 then
   IsValidEmail = false
end if

end function

'---------------------错误输出-------------------------------
sub error()
%>
<!--#include file="dbpath.asp"-->


<html>
<head><title>错误信息提示==<%=WebTitle%></title></head>
<body bgcolor="<%=bgcolor%>">
<div align="center">
  <table cellpadding=0 cellspacing=0 border=0 width=99% align=center>
    <tr>
      <td>
        <table cellpadding=3 cellspacing=1 border=0 width=100% bgcolor="<%=MainCColor%>">
          <tr align="center"> 
            <td width="100%">错误信息：</td>
          </tr>
          <tr> 
            <td width="100%"><b>产生错误的可能原因：<br><%=errmsg%></td>
          </tr>
          <tr align="center">
            <td width="100%"><a target="_blank" href="index.asp"> << 会员登录</a> ××<a href="Reg.asp">注册会员</a><input type="button" name="close" value="关闭窗口" onclick="javascript:window.close()"></td>
          </tr>  
        </table>
      </td>
    </tr>
  </table>
</div>
</html>
<%
end sub

sub sendemail
	topic=FromUser&"在"&WebName&"给你点了一首歌"
	mailbody=mailbody &"<style>A:visited {	TEXT-DECORATION: none	}"
	mailbody=mailbody &"A:active  {	TEXT-DECORATION: none	}"
	mailbody=mailbody &"A:hover   {	TEXT-DECORATION: underline overline	}"
	mailbody=mailbody &"A:link 	  {	text-decoration: none;}"
	mailbody=mailbody &"A:visited {	text-decoration: none;}"
	mailbody=mailbody &"A:active  {	TEXT-DECORATION: none;}"
	mailbody=mailbody &"A:hover   {	TEXT-DECORATION: underline overline}"
	mailbody=mailbody &"BODY   {	FONT-FAMILY: 宋体; FONT-SIZE: 9pt;}"
	mailbody=mailbody &"TD	   {	FONT-FAMILY: 宋体; FONT-SIZE: 9pt	}</style>"
	mailbody=mailbody &"<TABLE border=0 width='95%' align=center><TR><TD>"
	mailbody=mailbody &"你好！这是来至<a href="&WebUrl&" target=_blank>"&WebName&"</a>的祝福！<br>"
	mailbody=mailbody &FromUser&"在本站给你点了一首歌曲。请<a href="&WebUrl&" target=_blank>查收</a>！<br>"
	mailbody=mailbody &"</TD></TR></TABLE>"
	on error resume next
Dim objCDO
Set objCDO = Server.CreateObject("CDONTS.NewMail")
objcdo.MailFormat = 0
objcdo.BodyFormat = 1
objCDO.To         = ForUserEmail 
objCDO.Importance = 1
objCDO.From       = FromUserEmail
objCDO.Subject    = topic
objCDO.Body       = mailbody 
objCDO.Send
Set objCDO = Nothing
if err then 
	err.clear
else
	Response.Write "<center><b> 信件已经发出！</b>"
end if


'MailFormat 邮件的格式（0：Html 1：纯文本）
'BodyFormat 链接的格式（1、所有链接自动变为可点击，0、当mailformat=0时链接不变，否则变为可点击）
'To         邮件接收方的电子信箱地址
'Importance 邮件的重要性（0：低 1：中 2：高）
'From       邮件发送方的电子信箱地址
'Subject    邮件的主题
'Body       邮件的内容
'Send       完成发送邮件的动作
'	topic=FromUser&"在"&WebName&"给你点了一首歌"
'	mailbody=mailbody &"<style>A:visited {	TEXT-DECORATION: none	}"
'	mailbody=mailbody &"A:active  {	TEXT-DECORATION: none	}"
'	mailbody=mailbody &"A:hover   {	TEXT-DECORATION: underline overline	}"
'	mailbody=mailbody &"A:link 	  {	text-decoration: none;}"
'	mailbody=mailbody &"A:visited {	text-decoration: none;}"
'	mailbody=mailbody &"A:active  {	TEXT-DECORATION: none;}"
'	mailbody=mailbody &"A:hover   {	TEXT-DECORATION: underline overline}"
'	mailbody=mailbody &"BODY   {	FONT-FAMILY: 宋体; FONT-SIZE: 9pt;}"
'	mailbody=mailbody &"TD	   {	FONT-FAMILY: 宋体; FONT-SIZE: 9pt	}</style>"
'	mailbody=mailbody &"<TABLE border=0 width='95%' align=center><TR><TD>"
'	mailbody=mailbody &"你好！这是来至<a href="&WebUrl&" target=_blank>"&WebName&"</a>的祝福！<br>"
'	mailbody=mailbody &FromUser&"在本站给你点了一首歌曲。请<a href="&WebUrl&" target=_blank>查收</a>！<br>"
'	mailbody=mailbody &"</TD></TR></TABLE>"
'	on error resume next
'    if EmailFlag=1 then 
'    	email = ForUserEmail
'		Dim JMail,SendMail
'		Set JMail=Server.CreateObject("JMail.SMTPMail")
'		JMail.Logging=True
'		JMail.Charset="gb2312"
'		JMail.ContentType = "text/html"
'		JMail.ServerAddress=SMTPServer
'		JMail.Sender=SystemEmail
'		JMail.Subject=topic
'		JMail.Body=mailbody
'		JMail.AddRecipient=email
'		JMail.Priority=3
'		JMail.Execute 
'		Set JMail=nothing 
'		if err then 
'			Response.Write "但因服务器没有安装Jmail发信组件或没有信箱地址或其他原因导致无法发信"
'			err.clear
'		else
'			SendMail="OK"
'		    Response.Write "<center><b> 信件已经发出！</b>"
'		end if
'	elseif EmailFlag=2 then
'    	email = useremail
'		dim  objCDOMail
'		Set objCDOMail = Server.CreateObject("CDONTS.NewMail")
'		objCDOMail.From =SystemEmail
'		objCDOMail.To =email
'		objCDOMail.Subject =topic
'		objCDOMail.Body =mailbody
'		objCDOMail.Send
'		Set objCDOMail = Nothing
'		if err then 
'			Response.Write "但因服务器没有安装cdonts发信组件或没有信箱地址或其他原因导致无法发信"
'			err.clear
'		else
'		    Response.Write "<center><b> 信件已经发出！</b>"
'		end if
'    elseif EmailFlag=3 then
'    	email = useremail
'		Set mailer=Server.CreateObject("ASPMAIL.ASPMailCtrl.1")  
'		recipient=email
'		sender=SystemEmail
'		subject=topic
'		message=mailbody
'		mailserver=SMTPServer
'		result=mailer.SendMail(mailserver, recipient, sender, subject, message)
'		if err then 
'			Response.Write "但因服务器没有安装aspmail发信组件或没有信箱地址或其他原因导致无法发信"
'			err.clear
'		else
'		    Response.Write "<center><b> 信件已经发出！</b>"
'		end if
'    end if
end sub
%>