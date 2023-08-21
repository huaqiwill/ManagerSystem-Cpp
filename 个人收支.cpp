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
 #include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define N 30
#define FILENAME1 "personal.txt"
#define FILENAME2 "money.txt"
 struct personal
{
    char name[10];         /*����*/
    char sex;              /*�Ա�*/
    float age;             /*����*/
	char add[40];             /*��ַ*/
	char tel[20];           /*�绰*/
	float yue;          /*���*/
	
};
 struct record
 {
	 int year;
	 int month;
	 int day;
	 char shouzhi;
	 float money;
	 char reason[50];
};


/*******************************************************       
����:��ʾ�˵�
 *******************************************************/
 void displayMenu()
 {

        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+               ������֧����ϵͳMAX                     +\n");
		printf("+                                                       +\n");
        printf("+                 1. ���������Ϣ(��һ�ν�����ѡ��)     +\n");
        printf("+                 2. ��֧��¼����                       +\n");
        printf("+                 3. ��֧�嵥��ӡ                       +\n");
        printf("+                 4. ���������֧��ͳ��                 +\n");
        printf("+                 5. ��ѯ��ǰ������Ϣ�����             +\n");
        printf("+                 6. ���浽�ļ�                         +\n");
        printf("+                 7. �������                           +\n");
        printf("+                                                       +\n");
		printf("+                                                       +\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

 }

/*******************************************************       
����:��½��������֤����
 *******************************************************/
 int login(char password[])
 {
     static char key[30]="123";
     if(strcmp(password,key)==0)
       return 1;
     else
       return 0;
  }
  /*******************************************************       
����:���ļ�����Ϣ���ṹ��������
 *******************************************************/
 
void readFromFile1(struct personal pe)
 {
	FILE *fp=NULL;

	fp=fopen(FILENAME1,"rb");  

	if(fp!=NULL)
	{

		if(!feof(fp))    
		{
     
		
			fread(&pe,sizeof(struct personal),1,fp);
		}

		fclose(fp);
	}
}
void readFromFile2( struct record re[],int length)
 {
	FILE *fp=NULL;
	int i=0;
	fp=fopen(FILENAME1,"rb");  /*���ļ�*/

	if(fp!=NULL)
	{

		while(!feof(fp))    /*���ļ��ж���ѧ��*/
		{
     
			if(i>=N)
				break;
			if(fread(re+i,sizeof(record),1,fp)==1)
				i++;
		}

		fclose(fp);
	}
}



 /*******************************************************       
����:������Ϣ���ṹ��������

 *******************************************************/
int inputInfo(struct personal &pe,struct record re[])
{
    int i;
	char p;
	printf("\n��������������(ֻ��Ӣ����)\n");
	scanf("%s",pe.name);
	printf("�����������Ա�(mΪ����,wΪŮ��)\n");
	scanf("%s",&pe.sex);
	printf("��������������\n");
	scanf("%f",&pe.age);
	printf("���������ĵ�ַ(����ƴ����Ӣ��,�м�ӿո�)\n");
	scanf("%s",pe.add);
	printf("���������ĵ绰(ֻ��Ҫһ��)\n");
	scanf("%s",pe.tel);
    printf("�������������");
	scanf("%f",&pe.yue);
	printf("���ĸ�����Ϣ�Ѿ��������,����������������֧��¼\n");
	for(i=0;p!='n'&&i<N;i++)
	{
		printf("��");
		scanf("%d",&re[i].year);
		printf("��");
		scanf("%d",&re[i].month);
		printf("��");
		scanf("%d",&re[i].day);
		printf("�������֧��(����Ϊ+,֧��Ϊ-)\n");
		getchar();
		scanf("%c",&re[i].shouzhi);
		printf("�������֧��������\n");
		scanf("%f",&re[i].money);
		printf("������ԭ��(ֻ��ƴ������Ӣ��)\n");
		scanf("%s",re[i].reason);
		
		if(i<N)
		{
			printf("�Ƿ�Ҫ��������y/n");
			scanf("%s",&p);
		}	
	}
    return i;
}
/***************************************************
��֧��¼����
****************************************************/
void guanli(struct record re[],int length)
{
	int i,xuanze2,xuanze3;
	char p;
	int xuanze=0;
	printf("��ѡ��������еĲ���");
	printf("1.����µ���֧��Ϣ");
	printf("2.ɾ��������Ϣ");
	printf("3.�޸�������Ϣ");
	scanf("%d",&xuanze);
    switch(xuanze)
	{
	case 1:
		for(i=length;p!='n'&&i<N;i++)
	{
		printf("��");
		scanf("%d",&re[i].year);
		printf("��");
		scanf("%d",&re[i].month);
		printf("��");
		scanf("%d",&re[i].day);
		printf("�������֧��(����Ϊ+,֧��Ϊ-)\n");
		getchar();
		scanf("%c",&re[i].shouzhi);
		printf("�������֧��������\n");
		scanf("%f",&re[i].money);
		printf("������ԭ��(ֻ��ƴ������Ӣ��)\n");
		scanf("%s",re[i].reason);	
		if(i<N)
		{
			printf("�Ƿ�Ҫ��������y/n");
			scanf("%s",&p);
		}	
	}
		break;
	case 2:
		printf("����ɾ���ڼ�����¼?");
        scanf("%d",&xuanze2);
		for(i=xuanze2;i<=length;i++)
            re[i]=re[i+1];
        break;
	case 3:
		printf("�����޸���һ����¼");
        scanf("%d",&xuanze3);
		i=xuanze3; 
		printf("��������������һ����¼");
		printf("��");
		scanf("%d",&re[i].year);
		printf("��");
		scanf("%d",&re[i].month);
		printf("��");
		scanf("%d",&re[i].day);
		printf("�������֧��(����Ϊ+,֧��Ϊ-)\n");
		getchar();
		scanf("%c",&re[i].shouzhi);
		printf("�������֧��������\n");
		scanf("%f",&re[i].money);
		printf("������ԭ��(ֻ��ƴ������Ӣ��)\n");
		scanf("%s",re[i].reason);	
		break;
	}
	

}

 /*******************************************************       
����:��ӡ��֧�嵥
 *******************************************************/
void outputInfo(struct record re[],int length)
{
	int i;
	printf("************************��֧�嵥****************************\n");
	printf("����                                                    ��֧\n");
	for(i=0;i<length;i++)
		printf("%d.%d.%d                                              %c%f\n",re[i].year,re[i].month,re[i].day,re[i].shouzhi,re[i].money);

	
}
/************************************
�������֧��ͳ��
************************************/
void tongji(struct record re[],int length)
{
	float s,z;
	int i;
	s=0,z=0;
	for(i=0;i<length;i++) 
	{  
		if(re[i].shouzhi=='+')
	         s=s+re[i].money;
		else
			 z=z+re[i].money;
	}
	printf("������=%f\n",s);
	printf("��֧��=%f\n",z);
	
}
/****************************************************
��ѯ������Ϣ�Լ����
****************************************************/
void chaxun(struct personal pe,struct record re[],int length)
{
	float total=0,ye;
	int i;
	for(i=0;i<length;i++) 
	{
		if(re[i].shouzhi=='+')
	         total=total+re[i].money;
		else
	         total=total-re[i].money;
	}
	ye=pe.yue+total;
	printf("\n����)\n");
	printf("%c\n",pe.name);
	printf("�Ա�\n");
	printf("%c\n",pe.sex);
	printf("����\n");
	printf("%d\n",pe.age);
	printf("��ַ)\n");
	printf("%s\n",pe.add);
	printf("�绰\n");
	printf("%s\n",pe.tel);
	printf("���\n");
    printf("%f\n",ye);
}	





/*******************************************************       
����:�ṹ�������е�ѧ����Ϣ������ļ�
 *******************************************************/
void writeToFile1(struct personal pe)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME1,"wb");

	if(fp==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}

	
		fwrite(&pe,sizeof(personal),1,fp);

	fclose(fp);

}
int writeToFile2(struct record re[],int length)
{
	FILE *fp=NULL;
	int i=0;

	fp=fopen(FILENAME2,"wb");

	if(fp==NULL)
	{
		printf("���ļ�����\n");
		exit(0);
	}

	for(i=0;i<length;i++)
		fwrite(re+i,sizeof(record),1,fp);

	fclose(fp);
	return i;

}

 /*******************************************************       
  ����:������
  ��������   
  ����ֵ����
 *******************************************************/

void main()
{
	struct personal pe;
	struct record re[N];
    int length=0;
    int choice = 0; /*select and store menu item  */
    int s=0,arrayLength=0;
    char password[10];

    /*====��֤�û��Ŀ��ֱ����ȷΪֹ====*/
	do{
		printf("�������װ���ϵ���Կ��");
		scanf("%s",password);

		s=login(password);
     }while(s==0);
	length=writeToFile2(re,length);


    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
    while(1)
    {

		displayMenu();

		printf("\n ��ѡ�����Ĳ���(1,2,3,4,5,6,7,8)��\n");
        scanf("%d",&choice);

		switch(choice)
        {

			case 1:
				length=inputInfo(pe,re);
				printf("\n������Ϣ����ɹ�\n");
				break;

			case 2:
			    guanli(re,length);
				break;
  
			case 3:
				outputInfo(re,length);
				break;
 
			case 4:
				tongji(re,length);
				break;
            case 5:
				chaxun(pe,re,length);
				break;
            case 6:
				writeToFile1(pe);
				writeToFile2(re,length);

				break;
            case 7:
				exit(0);
				break;
        }
    }

}
