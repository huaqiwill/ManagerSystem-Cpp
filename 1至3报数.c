/***********************************************************
�ҵ���Ϣ:                                                  *
  ����: ������		����:1985��2��26��                     *
  ��ҵѧУ: 2007���ڳɶ�����ѧ                           *
  �����ַ: �Ĵ�������Ϫ���ɽ��5��                        *
  ��ϵQQ1: 287307421  QQ2: 254540457  QQ3:344245001        *
  ��ϵEmail: wangjianlin1985@126.com 13908064703           *
  �Ա��µ��ַ�� http://taochengxu.taobao.com              *
  ˫���ֳ�������ר����: http://287307421.paipai.com        *
  ��վ: http://www.shuangyulin.com ��������Ч��            *
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
