 
<link rel="shortcut icon" href="favicon.ico">
<style type="text/css">
body {font-family:"verdana", "arial", "helvetica", "Tahoma"; font-size: 9pt; color:#000000;
scrollbar-face-color:'CCCCCC'; 
scrollbar-shadow-color:'CCCCCC'; 
scrollbar-highlight-color:'CCCCCC'; 
scrollbar-3dlight-color:'D9D9D9'; 
scrollbar-darkshadow-color: '808080'; 
scrollbar-track-color:'F8F8F8'; 
scrollbar-arrow-color:'808080' }
td {font-family:verdana,arial,helvetica,Tahoma; font-size: 9pt}
div {font-family:verdana,arial,helvetica,Tahoma; font-size: 9pt}
form{font-family:verdana,arial,helvetica,Tahoma; font-size: 9pt}
select{font-size: 9pt}
OPTION{font-size: 9pt}
p{font-family:verdana,arial,helvetica,Tahoma; font-size: 9pt}
br{font-family:verdana,arial,helvetica,Tahoma; font-size: 9pt}
A {font-family:verdana,arial,helvetica,Tahoma; text-decoration: none; color:'000000'; font-size: 9pt}
A:hover {font-family:"verdana", "arial", "helvetica", "Tahoma"; text-decoration: none; color:#FF0000;  font-size: 9pt}
.informat01{font-family:verdana,arial,helvetica,Tahoma; font-size:9pt; background-color:'EFEFEF'}
.i02{font-family:"verdana", "arial", "helvetica", "Tahoma"; font-size:9pt; background-color: 'EFEFEF'; color: #000000; border: 000000px solid; }
.i03{ background-color:'EFEFEF'; 
BORDER-TOP-WIDTH: 1px; 
PADDING-RIGHT: 1px; PADDING-LEFT: 1px; 
BORDER-LEFT-WIDTH: 1px; FONT-SIZE: 9pt; 
BORDER-LEFT-COLOR:'FFFFFF'; BORDER-BOTTOM-WIDTH: 1px; 
BORDER-BOTTOM-COLOR:'C0C0C0'; PADDING-BOTTOM: 1px; 
BORDER-TOP-COLOR:'FFFFFF'; PADDING-TOP: 1px; 
HEIGHT: 20px; BORDER-RIGHT-WIDTH: 1px; 
BORDER-RIGHT-COLOR:'C0C0C0'}
.i04{font-family:"verdana", "arial", "helvetica", "Tahoma"; font-size:9pt; 
background-color: 'ffffff'; color: #000000; 
border: 000000px solid; background=ffffff; } 
.i05{font-family:"verdana", "arial", "helvetica", "Tahoma"; font-size:9pt; 
background-color: 'D9D9D9'; color: #000000; 
border: 808080px solid;}
.botton    {border-bottom:#000000 1px solid; background-color:#F1F1F1; border-left:#FFFFFF 1px solid; border-right:#333333 1px solid; border-top:#FFFFFF 1px solid; font-size: 9pt; font-family:"??"; height:20px; color: #000000; padding-bottom: 1px; padding-left: 1px; padding-right: 1px; padding-top: 1px; border-style: ridge}
.textfield {border-bottom:#000000 1px solid; background-color:#FFFFFF; border-left:#000000 1px solid; border-right:#000000 1px solid; border-top:#000000 1px solid; font-size: 9pt; font-family:"ËÎÌו";}
</style>

<BODY background="images/bgbg.gif" topmargin="0" text="#000000" leftmargin="14">
<div align="center">
  <center>
    <table width="751" border="0" cellpadding="0" cellspacing="0" style="border-collapse: collapse">
      <tr>
        <td height="2" valign="top"><img src="images/top.jpg" width="750" height="182"></td>
      </tr>
      <tr>
        <td bgcolor="#004c90"> 
          <div align="center">
            <center> 
          <table border="0" cellspacing="0" cellpadding="0" style="border-collapse: collapse">
            <tr> 
              <%             
	set rs=conn.execute("SELECT * FROM class order by classid")            
	do while not rs.eof           
%><a href="sort.asp?classid=<%=rs("classid")%>">
<%if rs("classid")=cint(request("classid")) then%>
              <td width="68.2" height="23" onmouseover="this.bgColor='#3399ff';" onmouseout="this.bgColor='#3399ff';" bgcolor="#0004c90" align="center">
			  <%else%><font color="#004C90"> </font>
			  <td width="68.2" height="23" onmouseover="this.bgColor='#3399ff';" onmouseout="this.bgColor='#004c90';" bgcolor="#004c90" align="center"  >
			  <%end if%><font color="#004C90"> </font> 
                <p align="center"> 
                  <font color="#ffffff"> 
                  <%if not Rs.eof then%> <%=Rs("class")%> </font> </p>
              </td></a>
              <%rs.movenext               
	end if            
	loop              
	rs.close            
%>
            </tr>
          </table>
            </center>
          </div>
        </td>
      </tr>
    </table>
          
    </center>
</div>