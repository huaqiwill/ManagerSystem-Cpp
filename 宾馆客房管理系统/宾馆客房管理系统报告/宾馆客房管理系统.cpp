#include<iostream.h> 
#include<string.h>
//***********************************************************************************
void initial_room();	//��ʼ��80��������Ϣ
void welcome();			//��֤�û���½,��½�ɹ���ʾ��ӭ��Ϣ
void enter();
void book_room();
void check_in();
void check_out();
void inquire();
int i=0;
//***********************************************************************************
struct Room  
{
 int number;
 int dank;
 int price;
 int state; 
};

class Customer  
{
public:
 Customer();
 
 void set_name(char *n){strcpy(name,n);}
 void set_ID(char *p){strcpy(ID,p);}
 void set_room_number(int n){room_number=n;}
 void set_day(int d){day=d;}
 void set_prepaid(int p){prepaid=p;}
 char *get_name(){return name;}
 char *get_ID(){return ID;}
 int  get_room_number(){return room_number;}
 int  get_day(){return day;}
 int  get_prepaid(){return prepaid;} 
 
 virtual ~Customer();
private: 
 char name[10],ID[19]; 
 int  room_number;
 int  prepaid;
 int  change;
 int  day;
};
Customer::Customer()
{
 cout<<"��������˿͵�����\n";
 cin>>name;
 cout<<"��������˿͵����֤����\n"; 
 cin>>ID; 
 prepaid=change=day=0;
}
Customer::~Customer()
{
 cout<<"�ù˿��˷��ɹ�!"<<endl;
}
//***********************************************************************************
Room room[80];
Customer *customer[80];

void main()			//������ڴ����￪ʼ����
{
 char choice='1';
 initial_room();	//��ʼ��80���������Ϣ,���ĸ��ȼ�
 welcome();			//��֤�û���½,��½�ɹ���ʾ��ӭ��Ϣ
 
 while(choice=='1')
 {
  enter();   //�����û���ѡ��ִ�в�ͬ�Ĺ���
  cout<<endl;
  cout<<"����ʹ�ñ�ϵͳ�밴\"1\",�˳��밴\"2\"!  ";
  cin>>choice;
  cout<<endl;
 }
}
//ϵͳ��½����***********************************************************************
void welcome()		//��֤�û���½,��½�ɹ���ʾ��ӭ��Ϣ
{
 char name[4],code[7];
 cout<<"�������û���������(�Կո����):\n"; 
 cin>>name>>code;
 while((strcmp(name,"000")!=0)||(strcmp(code,"666666")!=0))
 {
  cout<<"�û�����������������,����������!\n";
  cin>>name>>code;
 }
 cout<<endl;
 cout<<endl;
 cout<<"                      ��***************************��\n"; 
 cout<<"                           �� ��ӭʹ��***ϵͳ!��\n"; 
 cout<<"                      ��***************************��\n"; 
 cout<<endl;
}
//ϵͳ���***************************************************************************
void enter()
{
 int kind_of_service;
 cout<<"��ѡ��������:��������ס���˷����ǲ�ѯ? \n"; 
 cout<<" 1->����  2->��ס  3->�˷�  4->��ѯ:  ";
 cin>>kind_of_service; 
 if((kind_of_service>4) || (kind_of_service<1)) 
 {
  cout<<"������������������!\n"; 
  cin>>kind_of_service;
 } 
 else 
  switch(kind_of_service) 
 {
case 1: book_room();
 break;
case 2: check_in();
 break;
case 3: check_out();
 break;
case 4: inquire();
 break;
 } 
}


//����ʵ��***************************************************************************
void book_room()
{
 customer[i]=new Customer;
 int room_standard,day;
 cout<<"����ѡ��Ԥ������ı�׼:\n"; 
 cout<<"1.���˼�/��150Ԫ\n2.˫�˼�/��200Ԫ\n3.��׼��/��300Ԫ\n4.��ͳ�׷�/��600Ԫ\n"; 
 cin>>room_standard; 
 cout<<"������Ԥ������\n"; 
 cin>>day; 
 customer[i]->set_day(day);
 switch(room_standard) 
 { 
  int n;
 case 1:
  cout<<"ס�������ܹ�Ϊ: "<<day*150<<"Ԫ\n";		//����ס������
  for(n=0;n<20;n++)									//�ӵ�һ������ķ����в���һ�����еķ���
  {
   if(room[n].state==0)								//state=0��ʾ��ס��û�б�Ԥ����
   {
    cout<<"Ԥ���ɹ��﷿�����Ϊ: "<<room[n].number<<endl;
                room[n].state=1;
    customer[i]->set_room_number(room[n].number);
    break;
   }
  }
  break; 
 case 2:
  cout<<"ס�������ܹ�Ϊ: "<<day*200<<" Ԫ\n"; 
  for(n=20;n<40;n++)
  {
   if(room[n].state==0)
   {
    cout<<"Ԥ���ɹ��﷿�����Ϊ: "<<room[n].number<<endl;
                room[n].state=1;
    customer[i]->set_room_number(room[n].number);
    break;
   }
  }
  break; 
 case 3:
  cout<<"ס�������ܹ�Ϊ: "<<day*300<<" Ԫ\n"; 
  for(n=40;n<60;n++)
  {
   if(room[n].state==0)
   {
    cout<<"Ԥ���ɹ��﷿�����Ϊ: "<<room[n].number<<endl;
                room[n].state=1;
    customer[i]->set_room_number(room[n].number);
    break;
   }
  }
  break; 
 case 4:
  cout<<"ס�������ܹ�Ϊ: "<<day*600<<"Ԫ\n"; 
  for(n=60;n<80;n++)
  {
   if(room[n].state==0)
   {
    cout<<"Ԥ���ɹ��﷿�����Ϊ: "<<room[n].number<<endl;
                room[n].state=1;
    customer[i]->set_room_number(room[n].number);
    break;
   }
  }
  break;   
 }  
 i++;  //ס���Ĺ˿�����1
}
//��ס�Ǽ�***************************************************************************
void check_in()
{
    char name1[10],id1[19];
 int ding_or_no,prepaid;
 cout<<"�ù˿Ͷ�������? (1->����  2->û��) ";
 cin>>ding_or_no;
 if(ding_or_no==1)
 {
  cout<<"������˿͵�����:"<<endl;
  cin>>name1;
  cout<<"������˿͵����֤����:"<<endl;
  cin>>id1;
  for(int j=0;j<=i;j++)
  {
   if((strcmp(customer[j]->get_name(),name1)==0)&&(strcmp(customer[j]->get_ID(),id1)==0))  //���Ҹù˿͵Ķ�����Ϣ
   {
    int num=customer[j]->get_room_number();  //ȡ�ö����ķ����
    cout<<"�˿�"<<name1<<"������ס������! �������Ϊ: "<<num<<endl;
    switch(num/100)
    {
    case 6:
     prepaid=customer[j]->get_day()*150;
     customer[j]->set_prepaid(prepaid);
     cout<<"���շ��� "<<prepaid<<"Ԫ��!"<<endl; //��ʼ�շ�
     room[num%100-1].state=2;                  //�޸ķ���״̬Ϊ��ס״̬
     break;
    case 7:
     prepaid=customer[j]->get_day()*200;
     customer[j]->set_prepaid(prepaid);
     cout<<"���շ��� "<<prepaid<<"Ԫ��!"<<endl;
     room[19+num%100].state=2;
     break;
    case 8:
     prepaid=customer[j]->get_day()*300;
     customer[j]->set_prepaid(prepaid);
     cout<<"���շ��� "<<prepaid<<"Ԫ��!"<<endl;
     room[39+num%100].state=2;
     break;
    case 9:
     prepaid=customer[j]->get_day()*600;
     customer[j]->set_prepaid(prepaid);
     cout<<"���շ��� "<<prepaid<<"Ԫ��!"<<endl;
     room[59+num%100].state=2;
     break;
     
    }
    break;
   } 
  }
  
  
 } 
 else
 {
  customer[i]=new Customer;
  int room_standard,day;
  cout<<"����ѡ��Ԥ������ı�׼:\n"; 
  cout<<"1.���˼�/��150Ԫ\n2.˫�˼�/��200Ԫ\n3.��׼��/��300Ԫ\n4.��ͳ�׷�/��600Ԫ\n"; 
  cin>>room_standard; 
  cout<<"������ס������\n"; 
  cin>>day; 
  customer[i]->set_day(day);
  switch(room_standard) 
  { 
   int n;
  case 1:
   prepaid=day*150;
   customer[i]->set_prepaid(prepaid);
   cout<<"���շ��� "<<prepaid<<"Ԫ��!\n"; 
   for(n=0;n<20;n++)
   {
    if(room[n].state==0)
    {
     cout<<"��ס�������Ϊ: "<<room[n].number<<endl;
     room[n].state=2;
     customer[i]->set_room_number(room[n].number);
     break;
    }
   }
   break; 
  case 2:
   prepaid=day*200;
   customer[i]->set_prepaid(prepaid);
   cout<<"���շ��� "<<prepaid<<"Ԫ��!\n"; 
   for(n=20;n<40;n++)
   {
    if(room[n].state==0)
    {
     cout<<"��ס�������Ϊ: "<<room[n].number<<endl;
     room[n].state=2;
     customer[i]->set_room_number(room[n].number);
     break;
    }
   }
   break; 
  case 3:
   prepaid=day*300;
   customer[i]->set_prepaid(prepaid);
   cout<<"���շ��� "<<prepaid<<"Ԫ��!\n"; 
   for(n=40;n<60;n++)
   {
    if(room[n].state==0)
    {
     cout<<"��ס�������Ϊ: "<<room[n].number<<endl;
     room[n].state=2;
     customer[i]->set_room_number(room[n].number);
     break;
    }
   }
   break; 
  case 4:
   prepaid=day*600;
   customer[i]->set_prepaid(prepaid);
   cout<<"���շ��� "<<prepaid<<"Ԫ��!\n"; 
   for(n=60;n<80;n++)
   {
    if(room[n].state==0)
    {
     cout<<"��ס�������Ϊ: "<<room[n].number<<endl;
     room[n].state=2;
     customer[i]->set_room_number(room[n].number);
     break;
    }
   }
   break;   
  }  
  i++;
 }
}
//�˷�����***************************************************************************
void check_out()
{
 char name2[10],id2[19];
 int standard,j,room_number,day1,day2,day;
 cout<<"������Ҫ�˷��Ĺ˿����������֤����:\n";
 cin>>name2>>id2; 
 cout<<"������ù˿�ʵס����:\n"; 
 cin>>day2; 
 for(j=0;j<i;j++)
 {
  if((strcmp(customer[j]->get_name(),name2)==0)&&(strcmp(customer[j]->get_ID(),id2)==0))
  {
   room_number=customer[j]->get_room_number();
   standard=room_number/100; 
   day1=customer[j]->get_day();
   day=day1-day2;
   switch(standard) 
   {
   case 6: 
    cout<<"�˿͵ķ������"<<room_number<<" :Ϊ���˼�,ÿ��150Ԫ\n";
    cout<<"�ù˿�Ԥ���˷��� "<<customer[j]->get_prepaid()<<"Ԫ, ʵ������ "<<day2*150<<"Ԫ��!\n";
    cout<<endl;
    if(day>0)
     cout<<"���˸��ù˿� "<<day*150<<" Ԫ��!\n"; 
    if(day<0)
     cout<<"�벹�ոù˿�ס���� "<<-day*150<<" Ԫ��!\n";
    break; 
   case 7:
    cout<<"�˿͵ķ������"<<room_number<<" :Ϊ���˼�,ÿ��200Ԫ\n";
    cout<<"�ù˿�Ԥ���˷��� "<<customer[j]->get_prepaid()<<"Ԫ, ʵ������ "<<day2*200<<"Ԫ��!\n";
    cout<<endl;
    if(day>0)
     cout<<"���˸��ù˿� "<<day*200<<" Ԫ��!\n"; 
    if(day<0)
     cout<<"�벹�ոù˿�ס���� "<<-day*200<<" Ԫ��!\n";
    break; 
   case 8:
    cout<<"�˿͵ķ������"<<room_number<<" :Ϊ���˼�,ÿ��300Ԫ\n";
    cout<<"�ù˿�Ԥ���˷��� "<<customer[j]->get_prepaid()<<"Ԫ, ʵ������ "<<day2*300<<"Ԫ��!\n";
    cout<<endl;
    if(day>0)
     cout<<"���˸��ù˿� "<<day*300<<" Ԫ��!\n"; 
    if(day<0)
     cout<<"�벹�ոù˿�ס���� "<<-day*300<<" Ԫ��!\n";
    break; 
   case 9:
    cout<<"�˿͵ķ������"<<room_number<<" :Ϊ���˼�,ÿ��600Ԫ\n";
    cout<<"�ù˿�Ԥ���˷��� "<<customer[j]->get_prepaid()<<"Ԫ, ʵ������ "<<day2*600<<"Ԫ��!\n";
    cout<<endl;
    if(day>0)
     cout<<"���˸��ù˿� "<<day*600<<" Ԫ��!\n"; 
    if(day<0)
     cout<<"�벹�ոù˿�ס���� "<<-day*600<<" Ԫ��!\n";
    break; 
   }
   cout<<endl;
   cout<<"�˷��������,�밴1: ";
   char account;
   cin>>account;
   if(account=='1')
   {
    for(int k=0;k<80;k++)
    {
     if(room[k].number==customer[j]->get_room_number()) 
      room[k].state=0;
    }
    i--;
    for(;j<i;j++)
    {
     customer[j]=customer[j+1];
    }
    delete customer[i];
   }
  }
 } 
}
//��Ϣ��ѯ***************************************************************************
void inquire()
{
 char inquire_choice;
 cout<<"������Ϣ��ѯ�밴1, �˿���Ϣ��ѯ�밴2: "<<endl;
 cin>>inquire_choice;
    if(inquire_choice=='1')
 {
  int j,k=0;
  cout<<endl;
  cout<<"���з��仹û��Ԥ����Ҳû����ס��"<<endl;
  for(j=0;j<80;j++)
  {
   if(room[j].state==0)
   {
    if(k%10==0) cout<<endl;
    cout<<room[j].number<<'\t';
    k++;
   }
  }
  cout<<endl;
  cout<<endl;
  k=0;
  cout<<"���з�����Ԥ����"<<endl;
  for(j=0;j<80;j++)
  {
   if(room[j].state==1)
   {
    if(k%10==0) cout<<endl;
    cout<<room[j].number<<'\t';
    k++;
   }
  }
  k=0;
  cout<<endl;
  cout<<endl;
  cout<<"���з���������ס��"<<endl;
  for(j=0;j<80;j++)
  {
   if(room[j].state==2)
   {
    if(k%10==0) cout<<endl;
    cout<<room[j].number<<'\t';
    k++;
   }
  }
  cout<<endl;
  cout<<endl;
 }
 else if(inquire_choice=='2')
 {
  cout<<"��������ѯ�밴1, �����֤��ѯ�밴2: "<<endl;
  char inquire_choice;
  cin>>inquire_choice;
  if(inquire_choice=='1')
  {
   char name3[10];
   cout<<"������˿͵�����: "<<endl;
   cin>>name3;
   for(int j=0;j<=i;j++)
   {
    if(strcmp(customer[j]->get_name(),name3)==0)
    {
     cout<<name3<<"��ס����Ϣ����:\n";
     cout<<'\t'<<"�����Ϊ: "<<customer[j]->get_room_number()<<endl;
     cout<<"\t"<<"Ԥ������Ϊ: "<<customer[j]->get_prepaid()<<endl;
    }
   }
  }
  if(inquire_choice=='2')
  {
   char id3[10];
   cout<<"������˿͵�����: "<<endl;
   cin>>id3;
   for(int j=0;j<=i;j++)
   {
    if(strcmp(customer[j]->get_ID(),id3)==0)
    {
     cout<<customer[j]->get_name()<<"��ס����Ϣ����:\n";
     cout<<'\t'<<"�����Ϊ: "<<customer[j]->get_room_number()<<endl;
     cout<<"\t"<<"Ԥ������Ϊ: "<<customer[j]->get_prepaid()<<endl;
    }
   }
  }
 }
}
//������Ϣ��ʼ��*********************************************************************
void initial_room()  //��80��������г�ʼ��,��4���ȼ�
{
 int j,k=601;
 for(j=0;j<20;j++)
 {
  room[j].number=k++;
  room[j].dank=1;
  room[j].price=150;
  room[j].state=0;
 }
 k=701;
 for(j=20;j<40;j++)
 {
  room[j].number=k++;
  room[j].dank=2;
  room[j].price=200;
  room[j].state=0;
 }
 k=801;
 for(j=40;j<60;j++)
 {
  room[j].number=k++;
  room[j].dank=3;
  room[j].price=300;
  room[j].state=0;
 }
 k=901;
 for(j=60;j<80;j++)
 {
  room[j].number=k++;
  room[j].dank=4;
  room[j].price=600;
  room[j].state=0;
 }
}