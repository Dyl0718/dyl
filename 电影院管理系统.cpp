///�˳������ĵ�Ӱ�У��̾��ˡ�֩�����������������񡣣� 
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define Max 100 
typedef struct movie 				//�ṹ����											//movie�ṹ���� 
{
	char ticket_number[20];			//Ʊ��		
	char movie_name[20];			//��Ӱ���� 										
	char  phone_number[20];			//�˿͵绰�� 
	int  set_number;				//��λ��	
	char begin_time[10];			//��Ӱ����ʱ��
	int length;	 
}Seqlist;						//������												//�ṹ������ 
                     

void InitList(Seqlist *L);      	//��ʼ�����Ա�    												
void Reload();       		    	//ע�ᡢ��¼����	       										
int Choose();    					//ѡ����																			    
void Menu();						//��ʾ��ʾѡ�� 													
void Quit();						//�˳�ѡ��														
void Creat(Seqlist *L);				//�����µ����ݼ�¼ ,Ҳ����ֱ������ ����µĺ󱣴�. 				
int Add(Seqlist *L);				//�����µ����ݼ�¼,������ѡ�� 									
void Delete(Seqlist *L);			//ɾ��ĳ����Ӱ��Ϣ 												
void Find(Seqlist *L);      		//���ҵ�Ӱ														
int Alter(Seqlist *L);				//�޸���Ϣ														
void List(Seqlist *L);				//��ʾ���м�¼ 													
void Search_movie(Seqlist *L);		//�������ܻ�ӭ�ĵ�Ӱ 	
void Save(Seqlist *L);				//�ļ�����									

int main()
{	
	system("color 0B");						// ���ÿ���̨������ɫ
	//Reload();								//��¼��ע�� 
	Seqlist L[Max];							//�������Ա� 
	InitList (&L[Max]); 					//��ʼ�����Ա�					
	while (1)
	{
		Menu();
		switch (Choose())
		{
		case 1:
			 Creat(L); break;
		case 2:
			Add(L); break;
		case 3:
		   Find(L);break;
		case 4:
			Delete(L); break;
		case 5:
			 Alter(L);break;
		case 6:
			 List(L); break;
		case 7:
			Search_movie(L); break;
		case 8:
			Save(L); break;
		case 0:
			 Quit();break;
		}
	}
	return 0;
} 
void InitList (Seqlist *L) 
{
	L->length=0;
}

void Quit() 
{
	exit(-1);
}

void Menu()														
{

	printf("\n\n");
	
	printf("------------------------------ӰԺ����ϵͳ-------------------------------------------------\n");

	printf("*\t1.�����µĵ�Ӱ��Ϣ		2.��ӵ�Ӱ��Ϣ			3.����ĳ����Ӱ��Ϣ*\n");

	printf("*\t4.ɾ��ĳ����Ӱ��Ϣ   		5.�޸ĵ�Ӱ��Ϣ			6.��ʾ���м�¼	  *\n");

	printf("*\t7.�鿴���ܻ�ӭ�ĵ�Ӱ 		8.���浽�ļ�			0.�˳�ϵͳ	  *\n");

	printf("-------------------------------------------------------------------------------------------\n");
  
}
int Choose()
{
	int number;																		 
	printf("���������:");
	while (scanf("%d", &number) != 1 || number < 0 || number>8) 
	{
		printf("��������,����������:");
		scanf(" %d", &number);
	}
	return number;
}

void Reload()																	//ע����� 
{
	char user_name[10];
	char password[10];
	printf("\n\n\t\t\t��ӭʹ�õ�ӰԺ����ע��ϵͳ\n\n");
	while(1)
	{
		
		printf("\t\t�������û���[���ܴ���10���ַ�]��");							//�����û���
		scanf("%s",user_name);
		
		
		if(strlen(user_name)<=10)												//�ж��û����Ƿ����Ҫ�� 
		{
			while(1)
			{
				
				printf("\n\t\t���������루���볤��Ϊ��λ����");					//��������
				scanf("%s",password);
				
				
				if(strlen(password)==8)											//�ж������Ƿ����Ҫ�� 
				{	
					printf("\n\n\t\tע��ɹ��������û�����%s,������%s\n\n",user_name,password);
					break;
				}
				else
				{
					printf("\n\t\t����ĳ���Ϊ%d������������\n",strlen(password));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t�û����ĳ���Ϊ%d������������\n\n",strlen(user_name));
		}
	}
	
	char a; 
	printf("�Ƿ��¼��(Y/N)");
	scanf(" %c",&a); 
	if(a=='Y'||a=='y') 
	{
		int i;
		char on_name[10];
		char on_password[10];	 
		printf("\n\n\t\t\t��ӭʹ�õ�ӰԺ�����¼ϵͳ\n\n");
	
		for(i=1;i<=3;i++)															//���ε�¼��֤
		{
			printf("\t\t�������û���:");
			scanf("%s",on_name);
			printf("\n\t\t��������  ��:");
			scanf("%s",on_password);
			if(strcmp(user_name,on_name)==0&&strcmp(password,on_password)==0)
			{
				printf("\n\n\t\t��¼�ɹ�����ӭʹ�õ�ӰԺ����ϵͳ\n\n");
				break;
			}
			else
			{
				printf("\n\n\t\t��¼ʧ�ܣ������µ�¼��������%d�λ���\n\n",3-i);
			}
	}
	}
	else
	{
		exit(-1);
	} 
} 

int Add(Seqlist *L)																//��ӵ�Ӱ��Ϣ 
{
	if(L->length==Max) 											//�������� 
	{
		printf("ϵͳ�ռ��������޷����");
		return 0; 
	}
	char a;
	do
	{
		printf("�������Ӱ����  ");						
		scanf("%s",L[L->length].movie_name);						
		printf("�������Ӱ����ʱ�䣺��24Сʱ�ƣ� ");	
		scanf("%s",L[L->length].begin_time);					
		printf("����˿��ֻ��ţ�  ");					
		scanf("%s",L[L->length].phone_number);				
		printf("������Ʊ�ţ�  ");						
		scanf("%s",L[L->length].ticket_number);				
		printf("������˿���λ�ţ�");					
		scanf("%d",&L[L->length].set_number);
		L->length++; 																	
		printf("�Ƿ�������룿��Y/N��");
		scanf(" %s",&a);
	}while(a=='y'||a=='Y');
		
		printf("2��󷵻�ѡ��˵�");						
		Sleep(2000) ;				
		system("cls");
}
void Creat(Seqlist *L)															//������Ӱ��Ϣ			
{
	
		printf("�������Ӱ����  ");						
		scanf("%s",L[L->length].movie_name);						
		printf("�������Ӱ����ʱ�䣺��24Сʱ�ƣ� ");	
		scanf("%s",L[L->length].begin_time);					
		printf("����˿��ֻ��ţ�  ");					
		scanf("%s",L[L->length].phone_number);				
		printf("������Ʊ�ţ�  ");						
		scanf("%s",L[L->length].ticket_number);				
		printf("������˿���λ�ţ�");					
		scanf("%d",&L[L->length].set_number);
		L->length++; 					
		printf("\n");
		printf("2��󷵻�ѡ��˵�");						
		Sleep(2000) ;															//˯�߲��� 
		system("cls");															//�������� 
}
void Find(Seqlist *L)															//���ҵ�Ӱ��Ϣ 
{
	if(L->length==0)
	{
		printf("������ӵ�Ӱ��Ϣ��"); 
		return ; 
	}
    int a; 
    int i=0;
A:	printf("\t\t\t\t----------1�����ݵ�Ӱ���Ʋ���---------------\n"); 			//AΪgotoָ��. �ص���Ҫ��λ�� 
	printf("\t\t\t\t----------2�����ݿ���ʱ�����---------------\n");   
	printf("\t\t\t\t----------3�����ݹ˿��ֻ��Ų���-------------\n");
	printf("\t\t\t\t----------4������Ʊ�Ų���-------------------\n");
	printf("\t\t\t\t----------5�����ݹ˿���λ�Ų���-------------\n");
	printf("����������ѡ��1��2��3��4��5��\n");
	scanf(" %d",&a);									//aΪ������ѡ�� 
    char b[20];
    
    switch(a)						
   {
   	case 1:
	   printf("��������ҵĵ�Ӱ����\n"); 
	     scanf(" %s",b);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].movie_name, b) == 0)				//bΪ����ĵ�Ӱ���ơ�strcmp�ַ����ȽϺ�����������0Ϊ��� 
	   	   {
			printf("�ҵ���\n");
	   	   	break;
		   }
	   } 
	   break;
	case 2:
	printf("�����뿪��ʱ��\n"); 
	     scanf(" %s",b);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].begin_time, b) == 0)
	   	   {
	   	   	printf("�ҵ���\n");
	   	   	break;
		   }
	   } 
		break;
		 int c;
	case 3:
		 printf("������˿��ֻ���\n"); 
	     scanf(" %d",c);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].phone_number, b) == 0)
	   	   {
	   	   	printf("�ҵ���\n");
	   	   	break;
		   }
	   } 
	   break;
	case 4:
   	   printf("������Ʊ��\n"); 
	     scanf(" %s",b);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].ticket_number, b) == 0)
	   	   {
	   	   	printf("�ҵ���\n");
	   	   	break;
		   }
	   } 
	   break;
	   case 5:  
   	   	printf("������˿���λ��\n"); 
	     scanf(" %d",&c);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(L[i].set_number==c )
	   	   {
	   	   	printf("�ҵ���\n");
	   	   	break;
		   }
	   } 
	   break;
	default:printf("�����д������������룺\n");
	goto A;			
   }
   
   if(i>=L->length)
   {
   	printf("û���ҵ�����Ϣ��\n");
   }
   else
   {
   	    printf("��Ӱ���ƣ� %s\n",L[i].movie_name);
    	printf("��Ӱ����ʱ�䣺%s\n",L[i].begin_time);
    	printf("�˿��ֻ��ţ� %s\n",L[i].phone_number);
    	printf("�˿�Ʊ��  �� %s\n",L[i].ticket_number);
    	printf("�˿���λ�ţ� %d\n",L[i].set_number);
    	printf("\n");
   }            
	return;
}
void List(Seqlist *L)															//��ʾ���м�¼	
{	
	if(L->length==0)				//�п� 
	{
		printf("������ӵ�Ӱ��Ϣ��"); 
		return ; 
	}
	
	printf("��Ӱ��\t\t����ʱ��\t\t�˿��ֻ���\t\t�˿�Ʊ��\t\t�˿���λ��\n");
	printf("---------------------------------------------------------");
	printf("---------------------------------------------------\n");
	int i;
    for(i=0;i<L->length;i++)
    {
	printf("%s\t\t%s\t\t\t%s\t\t%s\t\t%d\n",L[i].movie_name,L[i].begin_time,L[i].phone_number,L[i].ticket_number,L[i].set_number);
	}
	return; 
}
void Delete(Seqlist *L)															//ɾ����Ӱ��Ϣ 
{
	if(L->length==0)			//�п� 
	{
		printf("������ӵ�Ӱ��Ϣ��"); 
		return ; 
	}
	char choose;
	char name[20];				//����ĵ�Ӱ���� 
	int i,j; 
	printf("����Ҫɾ���ĵ�Ӱ���� ");
	scanf(" %s",name);
	
	for(i=0;i<=L->length;i++)
	   {
	   	   if(strcmp(L[i].movie_name, name) == 0)									//�ַ����ȽϺ���������0Ϊ��� 
	   	   {
			printf("��Ӱ���ڣ�\n");
			break;
		   }
			if(i==L->length) 
			{
			printf("����ĵ�Ӱû�ҵ���\n"); 
			return;
			}
		}	
	
		printf("ȷ��ɾ����Ӱ %s (y/n)",L[i].movie_name);
		scanf(" %c",&choose);
		if(choose=='y')
		{
			for(j=0;j<L->length;j++)												//���ǲ���			
	 	 	{
		 		strcpy(L[i+j].movie_name,L[j+i+1].movie_name);					 
			 	strcpy(L[i+j].begin_time,L[j+i+1].begin_time);
			 	strcpy(L[i+j].phone_number,L[j+i+1].phone_number);
		   		strcpy(L[i+j].ticket_number,L[j+i+1].ticket_number);
				L[i+j].set_number=L[j+i+1].set_number;
				L->length--;
	  		}
	  		printf("����ɾ��"); 
	  		for(int i=0;i<3;i++)
	  		{
	  			Sleep(500);
	  			printf(".");
	  		}
	  		printf("ɾ���ɹ���\n"); 
	
		}
		else
		{
			printf("ɾ��ʧ�ܣ�\n");
		}
		printf("2��󷵻�ѡ��˵�");
		Sleep(2000) ;
		system("cls");
}



int Alter(Seqlist *L)		    												//�޸ĵ�Ӱ��Ϣ 
{
	if(L->length==0)
	{
		printf("������ӵ�Ӱ��Ϣ��"); 
		return 0; 
	}
	
	int flag = 0,i=0;
	char name[10],choose;
	getchar();
	printf("����Ҫ�޸ĵĵ�Ӱ���� ");
	scanf("%s", name);
	getchar();
	while(i<L->length)
	{
		if (strcmp(L[i].movie_name, name) == 0)		//strcmp��m1,m2)��m1=m2�򷵻�0		
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag)
	{
		printf("��Ӱ��Ϊ %s �Ƿ��޸�(y/n)", L[i].movie_name);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", L[i].movie_name);
		}

		printf("��Ӱ����ʱ�� %s �Ƿ��޸�(y/n)", L[i].begin_time);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", L[i].begin_time);
		}

		printf("�˿��ֻ���Ϊ %s �Ƿ��޸�(y/n)", L[i].phone_number);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", L[i].phone_number);
		}

		printf("�˿�Ʊ��Ϊ %s �Ƿ��޸�(y/n)", L[i].ticket_number);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%s", L[i].ticket_number);
		}

		printf("��λ��Ϊ %d �Ƿ��޸�(y/n)", L[i].set_number);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("�޸�Ϊ��");
			scanf("%d", &L[i].set_number);
		}

		printf("�����޸�");
		for(i=0;i<3;i++)
		{
		Sleep(1000);
		printf(".");
		} 
		printf("�޸����");
		printf("3��󷵻�ѡ��˵�");
		Sleep(3000) ;
	}
	else
		printf("δ�ҵ�\n\n");
	system("cls");
}
void Search_movie(Seqlist *L)													//�������ܻ�ӭ�ĵ�Ӱ 

{		
		if(L->length==0)
		{
		printf("����Ϊ�����κε�Ӱ��Ϣ��");
		return ;
		}
		printf("���ڲ���");
		for(int i=0;i<3;i++)
		{
			Sleep(1000);
			printf("."); 
		}
	
	int i,a=0,b=0,c=0,d=0;							//(����a��b��c��d�ֱ�Ϊ�ۿ��̾��ˡ�֩����������������������� 
	char name1[10]="�̾���" ,name2[10]="֩����", name3[10]="������", name4[10]="����"; 
	for(i=0;i<L->length;i++)
	{
		if (strcmp(L[i].movie_name, name1) == 0)
		{
			a++; 
		}
		if (strcmp(L[i].movie_name, name2) == 0)
		{
			b++; 
		}
		if (strcmp(L[i].movie_name, name3) == 0)
		{
			c++; 
		}
		if (strcmp(L[i].movie_name, name4) == 0)
		{
			d++; 
		}
	}
		if(a>b&&a>c&&a>d)
		{
			printf("���ܻ�ӭ�ĵ�ӰΪ �̾���");
		}
		if(b>a&&b>c&&b>d)
		{
			printf("���ܻ�ӭ�ĵ�ӰΪ ֩����");
		}
		if(c>a&&c>b&&c>d)
		{
			printf("���ܻ�ӭ�ĵ�ӰΪ ������");
		}
		if(d>a&&d>b&&d>c)
		{
			printf("���ܻ�ӭ�ĵ�ӰΪ ����");
		}
}
void Save(Seqlist *L)															//���浽�ļ� 
{
																				//fp ͨ������Ϊ�ļ�ָ�롣
																				//a+�ȿ��Զ�ȡҲ����д�룬Ҳ������������ļ���
																				//fopen ���ļ� 
		FILE *fp;
		fp=fopen("data1.txt", "w");												
		if(fp!=NULL)
		{
				for(int i=0;i<L->length;i++)	
			{	
				fputs("��Ӱ���ƣ�",fp); 
				fputs(L[i].movie_name,fp);
				fputs("��Ӱ����ʱ�����ƣ�",fp);
				fputs(L[i].begin_time,fp);
				fputs("Ʊ�ţ�",fp);
				fputs(L[i].ticket_number,fp);
				fputs("�ֻ��ţ�",fp);
				fputs(L[i].phone_number,fp);
				fputs("��λ�ţ�",fp);		 														
				fprintf(fp,"%d",L[i].set_number);
				fputs("\n",fp);
			}
		
		}			
			fclose(fp);
		printf("���ڱ���");
		for(int i=0;i<3;i++)
		{
			Sleep(500);
			printf(".");
		} 
		printf("�ѱ���");
		return ;
}
