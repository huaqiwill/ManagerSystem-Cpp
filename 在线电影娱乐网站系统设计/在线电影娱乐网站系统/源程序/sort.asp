<!--#include file="conn.asp"-->
<!--#include file="inc/const.asp"-->
<%
   	dim totalPut   
   	dim CurrentPage
   	dim TotalPages
   	dim i,j
   	dim keyword
   	dim sql
   	dim rs
	dim updown
	dim order_name
	order_name=Request("Order") '排序的字段
   	if not isempty(request("page")) then
      		currentPage=cint(request("page"))
   	else
      		currentPage=1
   	end if
	if request("updown")<>"" then
		updown="desc"
	else
		updown=""
	end if
	select case order_name
		case "showname"
		order_name="showname"
		case "hot"
		order_name="hot"
		case "dateandtime"
		order_name="dateandtime"
		case "hits"
		order_name="hits"
		case "orders"
		order_name="orders"
		case "size"
		order_name="size"
		case else
		order_name="dateandtime"
		updown="desc"
	end select
 	set rs=server.createobject("adodb.recordset")
	dim classid,Nclassid
	dim classname,Nclassname

	if request("classid")="" then '如果大的电影分类编号为空
		classid="classid=1 and  "    '就取编号为1的电影分类
		sql="select class from class where classid=1"
		rs.open sql,conn,1,1
		if rs.bof and rs.eof then
			response.write "还没有任何栏目，请到管理页面添加"
			response.end
		else
		classname=rs("class")
		end if
		rs.close
	else
		classid="classid="&cstr(request("classid"))&" and  "
		sql="select class from class where classid="&cstr(request("classid"))
		rs.open sql,conn,1,1
		classname=rs("class") '取得大的分类名称
		rs.close
	end if
	if request("Nclassid")="" then '如果小的分类请求为空
		Nclassid=""
		Nclassname="所有影片"
	else
		Nclassid=" Nclassid="&cstr(request("Nclassid"))&" and  "
		sql="select Nclass.Nclass,class.class from Nclass,class where Nclass.classid=class.classid and Nclass.Nclassid="&cstr(request("Nclassid"))
		rs.open sql,conn,1,1
		classname=rs("class") '取得大的分类名称
		Nclassname=rs("Nclass") '取得小的分类名称
		rs.close
	end if
%>
<HTML><HEAD><TITLE><%=classname%><%if Nclassid<>"" then%>：<%=Nclassname%><%end if%></TITLE>
<META content="text/html; charset=gb2312" http-equiv=Content-Type>
<link rel="stylesheet" href="images/style.css">

<SCRIPT language=javascript>
function popwin2(id,path)
{		window.open("openarticle.asp?id="+id+"&ppath="+path,"");
}
</SCRIPT>
</HEAD>
<!--#include file="topMain.asp"-->
<table width="752" border="0" cellpadding="0" cellspacing="1" align="center" bgcolor="#004C90">
  <tr> 
    <td valign="top" bgcolor="#E8F0F8"> 
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
      <table border=0 cellpadding=0 width=100% align="center" bgcolor="#004C90" cellspacing=0>
        <tr> 
          <td height="20" bgcolor="#004C90"> 
            <div align="center"><a class=white href='sort.asp?classid=<%=request("classid")%>'><font color="#FFFFFF"><%=classname%></font></a></div>
          </td>
        </tr>
        <tr align=middle bgcolor="#999999"> 
          <td bgcolor="#999999" valign="top"> 
            <table border=0 cellpadding=0 cellspacing=0 width=100% height="100" align="center">
              <tr> 
                <td bgcolor=#E8F0F8         
                  valign=top width="191"><font style=line-height:150%> 
                  <%        
	if request("classid")="" then        
	sql="select Nclass,Nclassid from Nclass where classid=1"  '如果大的分类编号为空就取其为1     
	else        
	sql="select Nclass,Nclassid from Nclass where classid="&request("classid")        
	end if        
	rs.open sql,conn,1,1%>
                  </font> 
                  <table width="100%" border="0" cellspacing="0">
									<!-- 得到该大分类下所有的小分类并展示出来  //-->
                    <%do while not rs.eof%>
                    <tr> 
                      <td align="right" height="21"><img src="images/into.gif"></td>
                      <td align="left" height="21"> 
                        <%if not Rs.eof then%>
                        <a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=rs("Nclassid")%>"><%=Rs("Nclass")%></a> 
                      </td>
                      <%rs.movenext  
		end if %>
                    </tr>
                    <%loop        
  Rs.Close        
   %>
                  </table>
                </td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
      <table border="0" width="100%" cellspacing="0" cellpadding="0">
        <tr> 
          <td height="20" bgcolor="#004C90"> 
            <p align="center"><font color=#ffffff>本类热门下载</font> 
          </td>
        </tr>
        <tr> 
          <td width="100%" bgcolor="#999999"> 
            <table border="0" width="100%" cellspacing="0" cellpadding="0">
              <tr> 
                <td height="20" bgcolor="#E8F0F8" width="4%"></td>
                <td width="96%" bgcolor="#E8F0F8" height="100" valign="top"> 
                  <%if request("Nclassid")="" then
	sql="select top 10 id,showname,bb from download where download.classid="&request("classid")                   
	sql=sql&" order by download.hits desc"
	else
	sql="select top 10 id,showname,bb from download where download.Nclassid="&request("Nclassid")              
	sql=sql&" order by download.hits desc" 
	end if                  
	rs.open sql,conn,1,1                   
	if rs.eof and rs.bof then
response.write ("没有影片")
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
        </tr>
        <tr> 
          <td width="180" height="100%" bgcolor="#E8F0F8"></td>
        </tr>
      </table>
    </td>
    <td width="76%" valign="top" bgcolor="#FFFFFF"> 
      <table width="98%" border="0" align="center" cellpadding="0" cellspacing="0">
        <tr> 
          <td height="5"></td>
        </tr>
        <tr>
          <td background="images/bj4.gif" height="1"><img src="images/spacer.gif" width="1" height="1"></td>
        </tr>
      </table>
      <table width="98%" border="0" align="center">
        <tr> 
          <td bgcolor="#efefef">您的位置：<a href="index.asp">首页</a> >> <a href="sort.asp?classid=<%=request("classid")%>"><%=classname%></a> 
            >> <%=Nclassname%></td>
        </tr>
      </table>
      
      <table border=0 cellpadding=0 cellspacing=2 width=100%>
        <tbody> 
        <tr> 
          <td valign=top width=582> 
            <%                           
	if request("Nclassid")="" then '如果小分类信息编号为空                      
		sql="select id,showname,bb,note,dayhits,weekhits,lasthits,hits,dateandtime,hot,system,size,orders from download where download.classid="&request("classid")                           
		sql=sql&" order by "&order_name&" "&updown                          
	else                          
		sql="select id,showname,bb,note,dayhits,weekhits,lasthits,hits,dateandtime,hot,system,size,orders from download where download.Nclassid="&request("Nclassid")                          
		sql=sql&" order by "&order_name&" "&updown                          
	end if                          
	rs.open sql,conn,1,1                           
                          
  	if rs.eof and rs.bof then                           
       		response.write "<table border=0 width=100% height=100 cellpadding=0><tr><td width='100%'><p align=center>没有或没有找到任何信息</td></tr></table>"                           
   	else                           
       		totalPut=rs.recordcount                           
      		if currentpage<1 then                           
          		currentpage=1                           
      		end if                           
                          
      		if (currentpage-1)*MaxPerPage>totalput then                           
	   		if (totalPut mod MaxPerPage)=0 then                           
	     			currentpage= totalPut \ MaxPerPage                           
	   		else                           
	      			currentpage= totalPut \ MaxPerPage + 1                           
	   		end if                           
      		end if                           
       		if currentPage=1 then                           
            		showContent                           
            		showpage totalput,MaxPerPage,"sort.asp"                           
       		else                           
          		if (currentPage-1)*MaxPerPage<totalPut then                           
            			rs.move  (currentPage-1)*MaxPerPage                           
            			dim bookmark                           
            			bookmark=rs.bookmark                           
            			showContent                           
             			showpage totalput,MaxPerPage,"sort.asp"                           
        		else                           
	        		currentPage=1                           
           			showContent                           
           			showpage totalput,MaxPerPage,"sort.asp"                           
	      		end if                           
	   	end if                           
   	rs.close                           
   	end if                           
	                                   
   	sub showContent                           
       	dim i                           
	   	i=0                           
%>
            <table width="98%" >
              <tr>
                <td  width="100%" > 
                  <table border="0" cellspacing="1" cellpadding="0" width="98%" align="center" bgcolor="#3399ff">
                    <%if request("updown")="" then%>
                    <tr> 
                      <td width="37%" align="right" height="22" bgcolor="#E8F0F8"> 
                        <div align="center"><font color="#000000"><b>影片名称：</b></font></div>
                      </td>
                      <td width="11%" align="right" height="22" bgcolor="#E8F0F8"> 
                        <div align="center"><font color="#000000">影片性质</font></div>
                      </td>
                      <td width="12%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=dateandtime&updown=desc" title="点击按升序排列"><font color="#000000">整理日期</font></a></td>
                      <td width="11%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=hits&updown=desc"  title="点击按升序排列"><font color="#000000">下载次数</font></a></td>
                      <td width="11%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=size&updown=desc"  title="点击按升序排列"><font color="#000000">文件大小</font></a></td>
                      <td width="18%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=hot&updown=desc"  title="点击按升序排列"><font color="#000000">评分</font></a></td>
                    </tr>
                    <%else%>
                    <tr> 
                      <td width="37%" align="right" height="22" background="images/bg.gif"> 
                        <div align="center"><font color="#000000"><b>影片名称：</b></font></div>
                      </td>
                      <td width="11%" align="right" height="22" bgcolor="#E8F0F8"> 
                        <div align="center"><font color="#000000">影片性质</font></div>
                      </td>
                      <td width="12%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=dateandtime" title="点击按降序排列"><font color="#000000">整理日期</font></a></td>
                      <td width="11%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=hits"  title="点击按降序排列"><font color="#000000">下载次数</font></a></td>
                      <td width="11%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=size"  title="点击按降序排列"><font color="#000000">文件大小</font></a></td>
                      <td width="18%" align=center height="22" bgcolor="#E8F0F8"><a href="sort.asp?classid=<%=request("classid")%>&Nclassid=<%=request("Nclassid")%>&order=hot"  title="点击按降序排列"><font color="#000000">评分</font></a></td>
                    </tr>
                    <%end if%>
                    <%do while not rs.eof%>
                    <tr bgcolor="#FFFFFF" onMouseOver="this.style.backgroundColor='#f8f8f8';" onMouseOut="this.style.backgroundColor='#ffffff';"> 
                      <td width="37%" height="22" bgcolor="#f8f8f8"> <a class="date" href="list.asp?id=<%=rs("id")%>" title="点击查看详细介绍"><%=rs("showname")%>&nbsp;<%=rs("bb")%></a></td>
                      <td height="22" width="11%"> 
                        <div align="center"><%=rs("orders")%></div>
                      </td>
                      <td width="12%" align=center height="22"><%=month(rs("dateandtime"))%>月<%=day(rs("dateandtime"))%>日</td>
                      <td width="11%" align=center height="22"><%=rs("hits")%></td>
                      <td width="11%" align=center height="22"><%=rs("size")%></td>
                      <td width="18%" align=center height="22"> 
                        <%for imghot=1 to rs("hot")%><img src="images/grade1.gif"><%next%>
                      </td>
                    </tr>
                    <%     
	 i=i+1     
	 if i>=MaxPerPage then exit do     
	 	rs.movenext     
	 loop     
%>
                    <tr bgcolor="#FFFFFF"> 
                      <td colspan="6">&nbsp; </td>
                    </tr>
                    <tr bgcolor="#FFFFFF"> 
                      <td colspan="6"> 
                        <p align="center"> 
                          <% end sub      
     
	function showpage(totalnumber,maxperpage,filename)     
  	dim n     
     
  	if totalnumber mod maxperpage=0 then     
     		n= totalnumber \ maxperpage     
  	else     
     		n= totalnumber \ maxperpage+1     
  	end if     
  	response.write "<form method=Post action="&filename&"?classid="&request("classid")&"&Nclassid="&request("Nclassid")&"&order="&request("order")&"&updown="&request("updown")&">"     
  	response.write "<font color='red'>"&Nclassname&"</font>"     
     
  	if CurrentPage<2 then     
    		response.write ""&totalnumber&"个&nbsp;首页 上一页&nbsp;"     
  	else     
    		response.write ""&totalnumber&"个&nbsp;<a href="&filename&"?page=1&classid="&request("classid")&"&Nclassid="&request("Nclassid")&"&order="&request("order")&"&updown="&request("updown")&">首页</a>&nbsp;"     
    		response.write "<a href="&filename&"?page="&CurrentPage-1&"&classid="&request("classid")&"&Nclassid="&request("Nclassid")&"&order="&request("order")&"&updown="&request("updown")&">上一页</a>&nbsp;"     
  	end if     
     
  	if n-currentpage<1 then     
    		response.write "下一页 尾页"     
  	else     
    		response.write "<a href="&filename&"?page="&(CurrentPage+1)&"&classid="&request("classid")&"&Nclassid="&request("Nclassid")&"&order="&request("order")&"&updown="&request("updown")&">"     
    		response.write "下一页</a> <a href="&filename&"?page="&n&"&classid="&request("classid")&"&Nclassid="&request("Nclassid")&"&order="&request("order")&"&updown="&request("updown")&">尾页</a>"     
  	end if     
   	response.write "&nbsp;页次：<strong><font color=red>"&CurrentPage&"</font>/"&n&"</strong>页 "     
    	response.write "&nbsp;<b>"&maxperpage&"</b>个影片/页 "     
%>
<%            
end function       
%>
                        </p>
                      </td>
                    </tr>
                  </table>
                </td>
              </tr>
            </table>
          </td>
        </tr>
        </tbody> 
      </table><br>
     </td>
  </tr>
</table>
<!--#include file="CopyRight.asp"--> 
</BODY></HTML>