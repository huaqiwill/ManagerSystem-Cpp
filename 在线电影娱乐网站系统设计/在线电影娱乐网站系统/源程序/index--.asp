<!--#include file="conn.asp"-->
<%
  dim rs
  set rs = server.createobject("adodb.recordset")
%>
<HTML><HEAD><TITLE>在线宽带点播</TITLE>
<META content="text/html; charset=gb2312" http-equiv=Content-Type>
<link rel="stylesheet" href="images/style.css">
</HEAD>
<BODY>
<!--#include file="topMain.asp"-->
<table width="752" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#004C90" >
  <tr> 
    <td width="24%" valign="top" bgcolor="#E8F0F8" > 
      <table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#004C90">
        <tr> 
          <td bgcolor="#004C90" height="9" colspan="2"> 
            <table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#004C90" height="40">
              <form method="post" name="myform" action="search.asp">
                <tr> 
                  <td bgcolor="#E8F0F8" valign="middle" align="center"> 搜索： 
                    <input type="text" name="keyword" class=textfield size=10  maxlength="50"  style="font-family: Arial">
                    <input type="submit" name="Submit22" value="搜索" style="height='21'" class="botton">
                  </td>
                </tr>
              </form>
            </table>
          </td>
        </tr>
        <tr> 
          <td bgcolor="#004C90" height="20" colspan="2"> 
            <div align="center"><font color="#FFFFFF">站 内 公 告</font></div>
          </td>
        </tr>
        <tr> 
          <td height="20" bgcolor="#E8F0F8" colspan="2"> 
            <table border=0 cellpadding=0 width="100%" cellspacing="0">
              <%
	sql="select top 3 "
	sql=sql&"news.id,news.newsname,news.addtime,news.newsnote "
	sql=sql&" from news  "
	sql=sql&" order by news.id desc"
	rs.open sql,conn,1,1
	if rs.eof and rs.bof then
%>
              没有任何公告 
              <%else%>
              <%do while not rs.eof%>
              <tr> <td height="20" bgcolor="#E8F0F8" width="4%"></td>
                <td valign="top" width="96%"><img src="images/dot.gif" width="11" height="13"><%=rs("newsnote")%> 
                  <%if rs("addtime")>=date() then%>
                  <font color="#ff0000">[<%=rs("addtime")%>]</font> 
                  <%else%>
                  [<%=rs("addtime")%>] 
                  <%end if%>
                  <%
	rs.movenext
	loop
	end if
	rs.close
%>
                </td>
              </tr>
            </table>
          </td>
        </tr>
    
 
        <tr> 
          <td height="20" bgcolor="#004C90" colspan="2"> 
            <div align="center"><font color="#FFFFFF">累计下载TOP30</font></div>
          </td>
        </tr>
        <tr> 
          <td height="20" bgcolor="#E8F0F8" width="4%"></td>
          <td height="20" bgcolor="#E8F0F8" width="96%"> 
            <%                   
	sql="select top 30 id,showname,bb from download "                   
	sql=sql&" order by hits desc"                   
	rs.open sql,conn,1,1                   
	if rs.eof and rs.bof then
response.write ("没有下载")
else
do while not rs.eof
response.write ("<li><A href=list.asp?id="&rs("id")&">"&rs("showname")&" "&rs("bb")&"</A></li>")
	rs.movenext                                     
	loop                                     
	end if                                     
	rs.close                                     
%>
          </td>
        </tr>

      </table>
    </td>
    <td width="76%" bgcolor="#FFFFFF" valign="top" rowspan="2" >
      <table width="560" border="0" cellspacing="0" cellpadding="0" align="center">
        <tr> 
          <td background="images/bj4.gif" height="1"> <img src="images/spacer.gif" width="1" height="1"></td>
        </tr>
        <tr> 
          <td background="images/bg15.gif"> 
            <table width="560" border="0" cellspacing="0" cellpadding="0" height="27">
              <form method="post" action="Chkadmin1.asp">
                <tr> 
                  <td bgcolor="#E8F0F8"> 
                    <div align="center"> 
                      <%
if session("user")<>"" then%>
                      <%sql="select * from [user] where [user]='"&session("user")&"'"
        rs.open sql,conn,3,3
        %>
                      <script language="JavaScript">
<!--
var enabled = 0; today = new Date();
var day; var date;
if(today.getDay()==0) day = "星期日"
if(today.getDay()==1) day = "星期一"
if(today.getDay()==2) day = "星期二"
if(today.getDay()==3) day = "星期三"
if(today.getDay()==4) day = "星期四"
if(today.getDay()==5) day = "星期五"
if(today.getDay()==6) day = "星期六"
date = "" + (today.getYear()) + "年" + (today.getMonth() + 1 ) + "月" + today.getDate() + "日  " + day +"";
document.write("" + date + "");
-->
                      </script>
                      &nbsp;&nbsp;&nbsp;欢迎&nbsp;<font color="#DC1515"><%=rs("user")%></font>&nbsp;进入 
                      宽带影院，您现在可以完全浏览本站所有内容！ 
                      <%rs.close%>
                      <%else%>
                      <img src="images/home1.gif" width="19" height="16"><img src="images/home2.gif" width="49" height="13">： 
                      <input type="text" name="user" size="12" class="textfield" style="font-family: Arial">
                      <img src="images/mm.gif" width="25" height="13">： 
                      <input type="password" name="password" size="12" class="textfield" style="font-family: Arial">
                      <input type="submit" value="确定" name="B3" class="botton">
                      <input type="button" name="reg" value="注册成会员" class="botton" onclick="javascript:document.location='reg1.asp'">
                      <%end if%>
                    </div>
                  </td>
                </tr>
              </form>
            </table>
          </td>
        </tr>
        <tr> 
          <td background="images/bj4.gif" height="1"> <img src="images/spacer.gif" width="1" height="1"></td>
        </tr>
      </table>
      <table width="98%" border="0" align="center">
        <tr> 
          <td width="62%" height="1" > 
            <table width="100%" border="0" cellpadding="0" cellspacing="0" height="1" background="images/bj4.gif">
              <tr> 
                <td><img src="images/spacer.gif" width="1" height="1"></td>
              </tr>
            </table>
          </td>
          <td width="8%" height="46" rowspan="2" valign="top"> 
            <div align="right">　</div>
          </td>
          <td width="30%" height="46" rowspan="2" valign="top"> 
            <table border="0" width="100%" cellspacing="0" cellpadding="0">
              <tr> 
                <td></td>
              </tr>
              <tr> 
                <td> 
                  <table border="0" width="100%" cellspacing="0" cellpadding="0" height="42">
                    <tr> 
                      <td width="100%" bgcolor="#FFFFFF" valign="top"> 
                        <table border="0" width="100%" cellpadding="0" cellspacing="1">
                          <%    
	sql="select top 10"    
	sql=sql&"download.id,download.showname,bb,download.dateandtime,download.images,download.hits,download.classid,download.Nclassid,Nclass.Nclass "    
	sql=sql&" from download,Nclass where download.stop=1 and download.Nclassid=Nclass.Nclassid "    
	sql=sql&" order by download.dateandtime desc"    
	rs.open sql,conn,1,1    
	if rs.eof and rs.bof then    
%>
                          <tr> 
                            <td>还没有任何资料</td>
                          </tr>
                          <%else%>
                          <%do while not rs.eof%>
                          <tr> 
                            <td width="100%" > 
                              <div align="center"><a href="list.asp?id=<%=rs("id")%>"> 
                                <%
if not isnull(rs("images")) and rs("images")<> "" then
			response.write "<img src=" + rs("images") + " border=0  width=120 height=80>"
		end if
%>
                                </a> </div>
                            </td>
                          </tr>
                          <tr> 
                            <td width="100%" onMouseOver="this.bgColor='#F8F8F8';" onMouseOut="this.bgColor='#ffffff';" height="5"> 
                              <div align="center"><a href="list.asp?id=<%=rs("id")%>"><%=rs("showname")%><%=rs("bb")%></a></div>
                            </td>
                          </tr>
                          <tr> 
                            <td width="100%" height="10">&nbsp;</td>
                            <%      
	rs.movenext          
	loop                     
	end if                    
	rs.close                     
%>
                          </tr>
                        </table>
                      </td>
                    </tr>
                  </table>
                </td>
              </tr>
              <tr> 
                <td height="5"></td>
              </tr>
            </table>
            <div align="center"> </div>
          </td>
        </tr>
        <tr> 
          <td width="62%" height="22"  valign="top"> 
            <table border="0" width="100%" cellspacing="0" cellpadding="0" bgcolor="#ECECDB">
              <tr> 
                <td height="20"  valign="top" background="images/bg1.jpg"> 
                  <p align="center">&nbsp; <font     
            color=#ff0000>新进影片</font> 
                  </td>
              </tr>
              <tr> 
                <td></td>
              </tr>
              <tr> 
                <td bgcolor="#0066ff"> 
                  <table border="0" width="100%" cellspacing="1" cellpadding="0">
                    <tr> 
                      <td width="100%" bgcolor="#FFFFFF" valign="top"> 
                        <table border="0" width="100%" cellpadding="0" cellspacing="1">
                          <%    
	sql="select top 10 "    
	sql=sql&"download.id,download.showname,bb,download.dateandtime,download.hits,download.classid,download.Nclassid,Nclass.Nclass "    
	sql=sql&" from download,Nclass where download.Nclassid=Nclass.Nclassid "    
	sql=sql&" order by download.dateandtime desc"    
	rs.open sql,conn,1,1    
	if rs.eof and rs.bof then    
%>
                          <tr> 
                            <td>没有任何影片</td>
                          </tr>
                          <%else%>
                          <%do while not rs.eof%>
                          <tr> 
                            <td width="100%" onMouseOver="this.bgColor='#F8F8F8';" onMouseOut="this.bgColor='#ffffff';" height="23">&nbsp; 
                              <img src="images/RedArrow.gif" width="4" height="7">&nbsp;<a href='sort.asp?classid=<%=rs("classid")%>&Nclassid=<%=rs("Nclassid")%>'><%=rs("Nclass")%></a>&nbsp;-&nbsp;<a href="list.asp?id=<%=rs("id")%>"><%=rs("showname")%>&nbsp;<%=rs("bb")%></a><font color='#999999'>( 
                              <%if (month(rs("dateandtime"))&day(rs("dateandtime")))=(month(date())&day(date())) then%>
                              <font color=red> 
                              <%else%>
                              <font color='#999999'> 
                              <%end if%>
                              <%=month(rs("dateandtime"))%>月<%=day(rs("dateandtime"))%>日</font>,<font color=green><%=rs("hits")%></font>)</font></font></td>
                            <%      
	rs.movenext          
	loop                     
	end if                    
	rs.close                     
%>
                          </tr>
                        </table>
                        <table border="0" width="100%" cellpadding="0" cellspacing="0">
                          <tr> 
                            <td width="100%" height="20">　</td>
                          </tr>
                        </table>
                      </td>
                    </tr>
                  </table>
                </td>
              </tr>
              <tr> 
                <td height="5"></td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
      <table width="98%" border="0" align="center" height="234">
        <tr> 
          <td width="50%" valign="top"> 
            <table border="0" width="100%" cellspacing="0" cellpadding="0" bgcolor="#ECECDB">
              <tr> 
                <td height="19"  valign="top" background="images/bg1.jpg"> 
                  <p align="center"><font     
            color=#ff0000>推荐影片</font> 
                  </td>
              </tr>
              <tr> 
                <td></td>
              </tr>
              <tr> 
                <td bgcolor="#0066ff"> 
                  <table border="0" width="100%" cellspacing="1" cellpadding="0">
                    <tr> 
                      <td width="100%" bgcolor="#FFFFFF" valign="top"> 
                        <table border="0" width="100%" cellpadding="0" cellspacing="1" height="250">
                          <%    
	sql="select top 8 "    
	sql=sql&"download.id,download.showname,bb,download.dateandtime,download.hits,download.classid,download.Nclassid,Nclass.Nclass "    
	sql=sql&" from download,Nclass where download.hots=1 and download.Nclassid=Nclass.Nclassid "    
	sql=sql&" order by download.dateandtime desc"    
	rs.open sql,conn,1,1    
	if rs.eof and rs.bof then    
%>
                          <tr> 
                            <td>没有任何影片</td>
                          </tr>
                          <%else%>
                          <%do while not rs.eof%>
                          <tr> 
                            <td width="100%" onMouseOver="this.bgColor='#F8F8F8';" onMouseOut="this.bgColor='#ffffff';" height="23">&nbsp; 
                              <img src="images/RedArrow.gif" width="4" height="7">&nbsp;<a href='sort.asp?classid=<%=rs("classid")%>&Nclassid=<%=rs("Nclassid")%>'><%=rs("Nclass")%></a>&nbsp;-&nbsp;<a href="list.asp?id=<%=rs("id")%>"><%=rs("showname")%>&nbsp;<%=rs("bb")%></a><font color='#999999'></font></td>
                            <%      
	rs.movenext          
	loop                     
	end if                    
	rs.close                     
%>
                          </tr>
                        </table>
                        <table border="0" width="100%" cellpadding="0" cellspacing="0">
                          <tr> 
                            <td width="100%" height="20">　</td>
                          </tr>
                        </table>
                      </td>
                    </tr>
                  </table>
                </td>
              </tr>
              <tr> 
                <td height="5"></td>
              </tr>
            </table>
          </td>
          <td width="50%" valign="top">
            <table border="0" width="100%" cellspacing="0" cellpadding="0" bgcolor="#ECECDB">
              <tr> 
                <td colspan="2"></td>
              </tr>
              <tr> 
                <td bgcolor="#0066ff" colspan="2"> 
                  <table border="0" width="100%" cellspacing="1" cellpadding="0">
                    <tr> 
                      <td width="100%" bgcolor="#FFFFFF" valign="top"> 
                        <table border="0" width="100%" cellpadding="0" cellspacing="1" height="250">
                          <%    
		sql="select top 8 "    
	sql=sql&"download.id,download.showname,bb,download.dateandtime,download.hits,download.classid,download.Nclassid,Nclass.Nclass "    
	sql=sql&" from download,Nclass where download.hots=1 and download.Nclassid=Nclass.Nclassid "    
	sql=sql&" order by download.dateandtime desc"    
	rs.open sql,conn,1,1    
	if rs.eof and rs.bof then    
%>
                          <tr> 
                            <td height="19" background="images/bg1.jpg"> 
                              <div align="center"><font     
            color=#ff0000>会员影片</font> </div>
                            </td>
                          </tr>
                          <tr> 
                            <td height="224">没有任何影片</td>
                          </tr>
                          <%else%>
                          <%do while not rs.eof%>
                          <tr> 
                            <td width="100%" onMouseOver="this.bgColor='#F8F8F8';" onMouseOut="this.bgColor='#ffffff';" height="23">&nbsp; 
                              <img src="images/star.gif" width="11" height="14">&nbsp;<a href='sort.asp?classid=<%=rs("classid")%>&Nclassid=<%=rs("Nclassid")%>'><%=rs("Nclass")%></a>&nbsp;-&nbsp;<a href="list.asp?id=<%=rs("id")%>"><%=rs("showname")%>&nbsp;<%=rs("bb")%></a><font color='#999999'></font></td>
                            <%      
	rs.movenext          
	loop                     
	end if                    
	rs.close                     
%>
                          </tr>
                        </table>
                        <table border="0" width="100%" cellpadding="0" cellspacing="0">
                          <tr> 
                            <td width="100%" height="20">　</td>
                          </tr>
                        </table>
                      </td>
                    </tr>
                  </table>
                </td>
              </tr>
              <tr> 
                <td height="5" colspan="2"></td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
      <table width="98%" border="0" align="center" cellpadding="0" cellspacing="0">
        <tr> 
          <td background="images/bj4.gif" height="1"><img src="images/spacer.gif" width="1" height="1"></td>
        </tr>
      </table>
      <br>
    </td>
  </tr>
  <tr> 
    <td valign="top" bgcolor="#004C90" >　</td>
  </tr>
</table>
<!--#include file="CopyRight.asp"-->
<%   
set rs=nothing    
conn.close    
set conn=nothing%>