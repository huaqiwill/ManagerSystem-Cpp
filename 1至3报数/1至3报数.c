/** File KTVSystem.cpp KTV����ϵͳ
 * ��Ŀ��ַ��
 * CSDN���ͣ�https://blog.csdn.net/HuaQi666
 * �����ߣ�http://bingbingfuhao.cn
 * ���䣺3173484026@qq.com
 * ����ʱ��: 2023/8/21
 */
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
