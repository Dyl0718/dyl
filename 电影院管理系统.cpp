///此程序管理的电影有：绿巨人、蜘蛛侠、钢铁侠、雷神。） 
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define Max 100 
typedef struct movie 				//结构体名											//movie结构体名 
{
	char ticket_number[20];			//票号		
	char movie_name[20];			//电影名称 										
	char  phone_number[20];			//顾客电话号 
	int  set_number;				//座位号	
	char begin_time[10];			//电影开场时间
	int length;	 
}Seqlist;						//类型名												//结构体类型 
                     

void InitList(Seqlist *L);      	//初始化线性表    												
void Reload();       		    	//注册、登录操作	       										
int Choose();    					//选择功能																			    
void Menu();						//显示提示选单 													
void Quit();						//退出选单														
void Creat(Seqlist *L);				//创建新的数据记录 ,也可以直接载入 添加新的后保存. 				
int Add(Seqlist *L);				//增加新的数据记录,并返回选单 									
void Delete(Seqlist *L);			//删除某场电影信息 												
void Find(Seqlist *L);      		//查找电影														
int Alter(Seqlist *L);				//修改信息														
void List(Seqlist *L);				//显示所有记录 													
void Search_movie(Seqlist *L);		//查找最受欢迎的电影 	
void Save(Seqlist *L);				//文件保存									

int main()
{	
	system("color 0B");						// 设置控制台字体颜色
	//Reload();								//登录、注册 
	Seqlist L[Max];							//定义线性表 
	InitList (&L[Max]); 					//初始化线性表					
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
	
	printf("------------------------------影院管理系统-------------------------------------------------\n");

	printf("*\t1.创建新的电影信息		2.添加电影信息			3.查找某个电影信息*\n");

	printf("*\t4.删除某个电影信息   		5.修改电影信息			6.显示所有记录	  *\n");

	printf("*\t7.查看最受欢迎的电影 		8.保存到文件			0.退出系统	  *\n");

	printf("-------------------------------------------------------------------------------------------\n");
  
}
int Choose()
{
	int number;																		 
	printf("请输入序号:");
	while (scanf("%d", &number) != 1 || number < 0 || number>8) 
	{
		printf("输入有误,请重新输入:");
		scanf(" %d", &number);
	}
	return number;
}

void Reload()																	//注册操作 
{
	char user_name[10];
	char password[10];
	printf("\n\n\t\t\t欢迎使用电影院管理注册系统\n\n");
	while(1)
	{
		
		printf("\t\t请输入用户名[不能大于10个字符]：");							//输入用户名
		scanf("%s",user_name);
		
		
		if(strlen(user_name)<=10)												//判断用户名是否符合要求 
		{
			while(1)
			{
				
				printf("\n\t\t请输入密码（密码长度为八位）：");					//输入密码
				scanf("%s",password);
				
				
				if(strlen(password)==8)											//判断密码是否符合要求 
				{	
					printf("\n\n\t\t注册成功，您的用户名是%s,密码是%s\n\n",user_name,password);
					break;
				}
				else
				{
					printf("\n\t\t密码的长度为%d，请重新输入\n",strlen(password));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t用户名的长度为%d，请重新输入\n\n",strlen(user_name));
		}
	}
	
	char a; 
	printf("是否登录？(Y/N)");
	scanf(" %c",&a); 
	if(a=='Y'||a=='y') 
	{
		int i;
		char on_name[10];
		char on_password[10];	 
		printf("\n\n\t\t\t欢迎使用电影院管理登录系统\n\n");
	
		for(i=1;i<=3;i++)															//三次登录验证
		{
			printf("\t\t请输入用户名:");
			scanf("%s",on_name);
			printf("\n\t\t请输入密  码:");
			scanf("%s",on_password);
			if(strcmp(user_name,on_name)==0&&strcmp(password,on_password)==0)
			{
				printf("\n\n\t\t登录成功，欢迎使用电影院管理系统\n\n");
				break;
			}
			else
			{
				printf("\n\n\t\t登录失败，请重新登录，您还有%d次机会\n\n",3-i);
			}
	}
	}
	else
	{
		exit(-1);
	} 
} 

int Add(Seqlist *L)																//添加电影信息 
{
	if(L->length==Max) 											//判满操作 
	{
		printf("系统空间已满！无法添加");
		return 0; 
	}
	char a;
	do
	{
		printf("请输入电影名：  ");						
		scanf("%s",L[L->length].movie_name);						
		printf("请输入电影开场时间：（24小时制） ");	
		scanf("%s",L[L->length].begin_time);					
		printf("请输顾客手机号：  ");					
		scanf("%s",L[L->length].phone_number);				
		printf("请输入票号：  ");						
		scanf("%s",L[L->length].ticket_number);				
		printf("请输入顾客座位号：");					
		scanf("%d",&L[L->length].set_number);
		L->length++; 																	
		printf("是否继续输入？（Y/N）");
		scanf(" %s",&a);
	}while(a=='y'||a=='Y');
		
		printf("2秒后返回选择菜单");						
		Sleep(2000) ;				
		system("cls");
}
void Creat(Seqlist *L)															//创建电影信息			
{
	
		printf("请输入电影名：  ");						
		scanf("%s",L[L->length].movie_name);						
		printf("请输入电影开场时间：（24小时制） ");	
		scanf("%s",L[L->length].begin_time);					
		printf("请输顾客手机号：  ");					
		scanf("%s",L[L->length].phone_number);				
		printf("请输入票号：  ");						
		scanf("%s",L[L->length].ticket_number);				
		printf("请输入顾客座位号：");					
		scanf("%d",&L[L->length].set_number);
		L->length++; 					
		printf("\n");
		printf("2秒后返回选择菜单");						
		Sleep(2000) ;															//睡眠操作 
		system("cls");															//清屏操作 
}
void Find(Seqlist *L)															//查找电影信息 
{
	if(L->length==0)
	{
		printf("请先添加电影信息！"); 
		return ; 
	}
    int a; 
    int i=0;
A:	printf("\t\t\t\t----------1、根据电影名称查找---------------\n"); 			//A为goto指针. 回到想要的位置 
	printf("\t\t\t\t----------2、根据开场时间查找---------------\n");   
	printf("\t\t\t\t----------3、根据顾客手机号查找-------------\n");
	printf("\t\t\t\t----------4、根据票号查找-------------------\n");
	printf("\t\t\t\t----------5、根据顾客座位号查找-------------\n");
	printf("请做出您的选择（1，2，3，4，5）\n");
	scanf(" %d",&a);									//a为做出的选择 
    char b[20];
    
    switch(a)						
   {
   	case 1:
	   printf("请输入查找的电影名称\n"); 
	     scanf(" %s",b);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].movie_name, b) == 0)				//b为输入的电影名称。strcmp字符串比较函数，若等于0为相等 
	   	   {
			printf("找到了\n");
	   	   	break;
		   }
	   } 
	   break;
	case 2:
	printf("请输入开场时间\n"); 
	     scanf(" %s",b);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].begin_time, b) == 0)
	   	   {
	   	   	printf("找到了\n");
	   	   	break;
		   }
	   } 
		break;
		 int c;
	case 3:
		 printf("请输入顾客手机号\n"); 
	     scanf(" %d",c);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].phone_number, b) == 0)
	   	   {
	   	   	printf("找到了\n");
	   	   	break;
		   }
	   } 
	   break;
	case 4:
   	   printf("请输入票号\n"); 
	     scanf(" %s",b);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(strcmp(L[i].ticket_number, b) == 0)
	   	   {
	   	   	printf("找到了\n");
	   	   	break;
		   }
	   } 
	   break;
	   case 5:  
   	   	printf("请输入顾客座位号\n"); 
	     scanf(" %d",&c);
	   for(i=0;i<L->length;i++)
	   {
	   	   if(L[i].set_number==c )
	   	   {
	   	   	printf("找到了\n");
	   	   	break;
		   }
	   } 
	   break;
	default:printf("输入有错误！请重新输入：\n");
	goto A;			
   }
   
   if(i>=L->length)
   {
   	printf("没有找到该信息！\n");
   }
   else
   {
   	    printf("电影名称： %s\n",L[i].movie_name);
    	printf("电影开场时间：%s\n",L[i].begin_time);
    	printf("顾客手机号： %s\n",L[i].phone_number);
    	printf("顾客票号  ： %s\n",L[i].ticket_number);
    	printf("顾客座位号： %d\n",L[i].set_number);
    	printf("\n");
   }            
	return;
}
void List(Seqlist *L)															//显示所有记录	
{	
	if(L->length==0)				//判空 
	{
		printf("请先添加电影信息！"); 
		return ; 
	}
	
	printf("电影名\t\t开场时间\t\t顾客手机号\t\t顾客票号\t\t顾客座位号\n");
	printf("---------------------------------------------------------");
	printf("---------------------------------------------------\n");
	int i;
    for(i=0;i<L->length;i++)
    {
	printf("%s\t\t%s\t\t\t%s\t\t%s\t\t%d\n",L[i].movie_name,L[i].begin_time,L[i].phone_number,L[i].ticket_number,L[i].set_number);
	}
	return; 
}
void Delete(Seqlist *L)															//删除电影信息 
{
	if(L->length==0)			//判空 
	{
		printf("请先添加电影信息！"); 
		return ; 
	}
	char choose;
	char name[20];				//输入的电影名字 
	int i,j; 
	printf("输入要删除的电影名： ");
	scanf(" %s",name);
	
	for(i=0;i<=L->length;i++)
	   {
	   	   if(strcmp(L[i].movie_name, name) == 0)									//字符串比较函数，等于0为相等 
	   	   {
			printf("电影存在！\n");
			break;
		   }
			if(i==L->length) 
			{
			printf("输入的电影没找到！\n"); 
			return;
			}
		}	
	
		printf("确认删除电影 %s (y/n)",L[i].movie_name);
		scanf(" %c",&choose);
		if(choose=='y')
		{
			for(j=0;j<L->length;j++)												//覆盖操作			
	 	 	{
		 		strcpy(L[i+j].movie_name,L[j+i+1].movie_name);					 
			 	strcpy(L[i+j].begin_time,L[j+i+1].begin_time);
			 	strcpy(L[i+j].phone_number,L[j+i+1].phone_number);
		   		strcpy(L[i+j].ticket_number,L[j+i+1].ticket_number);
				L[i+j].set_number=L[j+i+1].set_number;
				L->length--;
	  		}
	  		printf("正在删除"); 
	  		for(int i=0;i<3;i++)
	  		{
	  			Sleep(500);
	  			printf(".");
	  		}
	  		printf("删除成功！\n"); 
	
		}
		else
		{
			printf("删除失败！\n");
		}
		printf("2秒后返回选择菜单");
		Sleep(2000) ;
		system("cls");
}



int Alter(Seqlist *L)		    												//修改电影信息 
{
	if(L->length==0)
	{
		printf("请先添加电影信息！"); 
		return 0; 
	}
	
	int flag = 0,i=0;
	char name[10],choose;
	getchar();
	printf("输入要修改的电影名： ");
	scanf("%s", name);
	getchar();
	while(i<L->length)
	{
		if (strcmp(L[i].movie_name, name) == 0)		//strcmp（m1,m2)若m1=m2则返回0		
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag)
	{
		printf("电影名为 %s 是否修改(y/n)", L[i].movie_name);
		scanf("%c", &choose);
		getchar();
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%s", L[i].movie_name);
		}

		printf("电影开场时间 %s 是否修改(y/n)", L[i].begin_time);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%s", L[i].begin_time);
		}

		printf("顾客手机号为 %s 是否修改(y/n)", L[i].phone_number);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%s", L[i].phone_number);
		}

		printf("顾客票号为 %s 是否修改(y/n)", L[i].ticket_number);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%s", L[i].ticket_number);
		}

		printf("座位号为 %d 是否修改(y/n)", L[i].set_number);
		scanf(" %c", &choose);
		
		if (choose == 'y')
		{
			printf("修改为：");
			scanf("%d", &L[i].set_number);
		}

		printf("正在修改");
		for(i=0;i<3;i++)
		{
		Sleep(1000);
		printf(".");
		} 
		printf("修改完成");
		printf("3秒后返回选择菜单");
		Sleep(3000) ;
	}
	else
		printf("未找到\n\n");
	system("cls");
}
void Search_movie(Seqlist *L)													//查找最受欢迎的电影 

{		
		if(L->length==0)
		{
		printf("您还为输入任何电影信息！");
		return ;
		}
		printf("正在查找");
		for(int i=0;i<3;i++)
		{
			Sleep(1000);
			printf("."); 
		}
	
	int i,a=0,b=0,c=0,d=0;							//(其中a，b，c，d分别为观看绿巨人、蜘蛛侠、钢铁侠、雷神的人数 
	char name1[10]="绿巨人" ,name2[10]="蜘蛛侠", name3[10]="钢铁侠", name4[10]="雷神"; 
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
			printf("最受欢迎的电影为 绿巨人");
		}
		if(b>a&&b>c&&b>d)
		{
			printf("最受欢迎的电影为 蜘蛛侠");
		}
		if(c>a&&c>b&&c>d)
		{
			printf("最受欢迎的电影为 钢铁侠");
		}
		if(d>a&&d>b&&d>c)
		{
			printf("最受欢迎的电影为 雷神");
		}
}
void Save(Seqlist *L)															//保存到文件 
{
																				//fp 通常被称为文件指针。
																				//a+既可以读取也可以写入，也就是随意更新文件。
																				//fopen 打开文件 
		FILE *fp;
		fp=fopen("data1.txt", "w");												
		if(fp!=NULL)
		{
				for(int i=0;i<L->length;i++)	
			{	
				fputs("电影名称：",fp); 
				fputs(L[i].movie_name,fp);
				fputs("电影开场时间名称：",fp);
				fputs(L[i].begin_time,fp);
				fputs("票号：",fp);
				fputs(L[i].ticket_number,fp);
				fputs("手机号：",fp);
				fputs(L[i].phone_number,fp);
				fputs("座位号：",fp);		 														
				fprintf(fp,"%d",L[i].set_number);
				fputs("\n",fp);
			}
		
		}			
			fclose(fp);
		printf("正在保存");
		for(int i=0;i<3;i++)
		{
			Sleep(500);
			printf(".");
		} 
		printf("已保存");
		return ;
}
