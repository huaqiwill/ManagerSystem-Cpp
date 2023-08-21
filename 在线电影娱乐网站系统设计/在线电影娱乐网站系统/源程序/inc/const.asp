<%
	Rem ----------系统定义---------
	const MaxPerPage=20	'每页显示程序最大数量
	Const ScriptTimeOut	= 900	'服务器ASP脚本超时时间值，建议不要使用 
	const makejs=0		'是否自动生成更新js文件，必须有Fso支持，请确认(1)，默认为否(0)
	const downdir="f:\usr\cw37035\down\file\"	'指定上传目录，相对于download目录，必须安装lyfupload组件，必须有Fso支持
	const downdir1=""	'虚拟目录 添加影片时预设的URL
%>