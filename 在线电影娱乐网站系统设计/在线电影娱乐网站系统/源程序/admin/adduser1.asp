<%@language=vbscript%>
<%
  if session("admin")="" then
  response.redirect "admin.asp"
  else
	if session("flag")>1 then
		response.write "<br><p align=center>您没有操作的权限</p>"
		response.end
	end if
  end if
  
%>
<HTML>
<HEAD>
<TITLE></TITLE>
<META http-equiv="Content-Type" content="text/html; charset=gb2312">
<LINK href="style.css" rel="stylesheet" type="text/css">
<SCRIPT language=javascript>

function check()

{
  if(document.form1.username.value=="")
    {
      alert("用户名为空");
      return false;
    }
    
  if(document.form1.newpin.value=="")
    {
      alert("密码不能为空");
      return false;
    }
    
  if((document.form1.newpin.value)!=(document.form1.re_newpin.value))
    {
      alert("密码不匹配");
      return false;
    }

}

</SCRIPT>
</HEAD>

<BODY bgcolor="#468ea3" leftmargin="0" topmargin="0">
<DIV align="center">
  <P>&nbsp;</P>
  <FORM method="post" action="saveuser3.asp" name="form1" onsubmit="javascript:return check();">
    
		
<TABLE width="40%" border="0" cellspacing="1" cellpadding="0" >
			<TR bgcolor="#CCCCCC"> 
        
<TD height="25" bgcolor="#145f74"> 
          
<DIV align="center"><FONT size="2" color="#FFFFFF">新增会员</FONT></DIV>
        </TD>
      </TR>
      <TR> 
        
				
<TD height="30" bgcolor="#a5d0dc"> 
					<DIV align="center"><FONT size="2">会 员 名　 
            <INPUT type="text" name="user">
            </FONT></DIV>
        </TD>
      </TR>
      <TR> 
        
				
<TD height="30" bgcolor="#cce6ed"> 
					
<DIV align="center"><FONT size="2">初始密码　 
            <INPUT type="password" name="newpin">
            </FONT> </DIV>
        </TD>
      </TR>
      <TR> 
        
				
<TD height="30" bgcolor="#a5d0dc"> 
					
<DIV align="center"><FONT size="2">确认密码　 
            <INPUT type="password" name="re_newpin">
            </FONT></DIV>
        </TD>
      </TR>
      <TR> 
        
				
<TD height="30" bgcolor="#cce6ed"> 
					
          <DIV align="center"></DIV>
        </TD>
      </TR>
      <TR>
        
				
<TD height="30" bgcolor="#a5d0dc"> 
					
          <DIV align="center"></DIV>
        </TD>
      </TR>
    </TABLE>
    <P>
      <INPUT type="submit" name="Submit" value="确定">
    </P>
  </FORM>
  <P>&nbsp;</P>
  <P align=center></P> </DIV>
</BODY>
</HTML>
