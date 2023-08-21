/***********************************************************
我的信息:                                                  *
  姓名: 汪建林		生日:1985年2月26日                     *
  毕业学校: 2007年于成都理工大学                           *
  家乡地址: 四川渠县望溪乡包山村5组                        *
  联系QQ1: 287307421  QQ2: 254540457  QQ3:344245001        *
  联系Email: wangjianlin1985@126.com 13908064703           *
  淘宝新店地址： http://taochengxu.taobao.com              *
  双鱼林程序拍拍专卖店: http://287307421.paipai.com        *
  网站: http://www.shuangyulin.com 【长期有效】            *
***********************************************************/
#include <stdio.h>
void main()
{
	void string(int array[], int n);
	int a[20];
	string(a, 10);
}
void string(int array[], int n)
{
	int i, *p;
	int s = 0;
	int t = n;
	p = array;
	for (i = 0; i < n; i++)
		*p++ = i + 1;
	p = array;
	while (t > 0)
	{
		if (*p != 0)
		{
			s++;
			if (s == 3)
			{

				printf("%d ", *p);
				*p = 0;
				t--;
				s = 0;
			}
		}
		p++;
		if (p == array + n)
			p = array;
	}
}
