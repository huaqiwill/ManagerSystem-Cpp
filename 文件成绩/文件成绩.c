/** File KTVSystem.cpp KTV����ϵͳ
 * ��Ŀ��ַ��
 * CSDN���ͣ�https://blog.csdn.net/HuaQi666
 * �����ߣ�http://bingbingfuhao.cn
 * ���䣺3173484026@qq.com
 * ����ʱ��: 2023/8/21
 */
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int num;
	char name[20];
	char sex;
	float score[3];
	float ave;
};
void save (struct student stu[],int n)
{
  FILE *fp;
  int i,j;
  if((fp=fopen("stu.txt","w"))==NULL)
  {
    printf("cannot open file\n");
	return;
  }
 for(i=0;i<n;i++)
	{
		fprintf(fp,"%d ",stu[i].num);
		fprintf(fp,"%s ",stu[i].name);
		fprintf(fp,"%c",stu[i].sex);
		for(j=0;j<3;j++)
			fprintf(fp,"%6.2f ",stu[i].score[j]);
		fprintf(fp,"%6.2f",stu[i].ave);
		fprintf(fp,"\n");
	}
  for(i=0;i<n;i++)
	{
		printf("%d ",stu[i].num);
		printf("%s ",stu[i].name);
		printf("%c",stu[i].sex);
		for(j=0;j<3;j++)
			printf("%6.2f ",stu[i].score[j]);
		printf("%6.2f",stu[i].ave);
		printf("\n");
	}
  fclose(fp);
}
void scan(struct student stu[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&stu[i].num);
		scanf("%s",stu[i].name);
		scanf(" %c",&stu[i].sex);
		for(j=0;j<3;j++)
			scanf("%f",&stu[i].score[j]);
	}
}
void aveage(struct student stu[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{	stu[i].ave=0;
		for(j=0;j<3;j++)
			stu[i].ave=stu[i].ave+stu[i].score[j];
		stu[i].ave=stu[i].ave/3;
	}
}
void main ()
{
  struct student stu[5];
  scan(stu,5);
  aveage(stu,5);
  save(stu,5);
}
