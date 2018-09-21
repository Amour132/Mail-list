#include "address.h"

int Expand(Point *p)
{
	if(p->sz == p->count)
	{
		Point *temp;
		temp = realloc(p->num,(2+p->count)*sizeof(Message));
		if(temp == NULL)
		{
			printf("%s",strerror(errno));
		    return 1;
		}
		p->num = temp;
		p->count += 2;
		printf("增容成功\n");
		return 0;
	}
	return 1;
}
void Load_address(Point *p)
{
	FILE *pread;
	Message temp;
	pread = fopen("address.txt","r");
	if(pread == NULL)
	{
		perror("open for the read");
		exit(EXIT_FAILURE);
	}
	while(fread(&temp,sizeof(Message),1,pread))
	{
		Expand(p);
		p->num[p->sz] = temp;
		p->sz++;
        
	}
	fclose(pread);
	pread = NULL;
}
void init_address(Point *p)
{
	Point *p2 = NULL;
	p->sz = 0;
	p->count = 3;
	p->num = (Point*)calloc(p->count,sizeof(Message));
	p2 = p->num;
	if(p2 == NULL)
	{
		perror("the calloc");
		exit(EXIT_FAILURE);
	}
	Load_address(p);
}
void Add_address(Point *p)
{
	
	if(p->sz>1000)
	{
		printf("通讯录已满\n");
	}
	else
	{
		if(Expand(p) == 0)
		{
			return;
		}
		printf("请输入要添加的名字\n");
		scanf("%s",p->num[p->sz].name);
		printf("请输入要添加的性别\n");
		scanf("%s",p->num[p->sz].sex);
		printf("请输入要添加的年龄\n");
		scanf("%d",&(p->num[p->sz].age));
		printf("请输入要添加的手机号码\n");
		scanf("%s",p->num[p->sz].phone);
		printf("请输入要添加的住址\n");
		scanf("%s",p->num[p->sz].address);
		printf("添加成功\n");
		p->sz++;
	}
}
void Show_address(Point *p)
{
	int i = 0;
	printf("%-10s%-5s%-5s%-13s%-8s\n","姓名","性别","年龄","手机号","地址");
	for(i=0; i<p->sz; i++)
	{
		printf("%-10s",p->num[i].name);
		printf("%-5s",p->num[i].sex);
		printf("%-5d",p->num[i].age);
		printf("%-13s",p->num[i].phone);
		printf("%-8s",p->num[i].address);
		printf("\n");
	}
	printf("\n");
}
int Find(Point *p,char *name)
{
	int i = 0;
	for(i=0; i<p->sz; i++)
	{
		if(strcmp(p->num[i].name,name) == 0)
		{
			return i;
		}
	}
	return-1;
}
void Del_address(Point *p)
{
	char *name = {0};
	int ret = 0;
	int i = 0;
	if(p->sz == 0)
	{
		printf("没有可删除的信息,删除失败\n");
	}
	else
	{
		printf("请输入要删除人的姓名\n");
		scanf("%s",name);
		ret = Find(p,name);
		if(ret == -1)
		{
			printf("没有此人的信息,删除失败\n");
		}
		else
		{
			p->num[ret] = p->num[ret+1];
			p->sz--;
			printf("删除成功\n");
		}
	}
}
void Search_address(Point *p)
{
	char name[20] = {0};
	int ret = 0;
	printf("请输入查找人的姓名\n");
	scanf("%s",name);
	ret = Find(p,name);
	if(ret == -1)
	{
		printf("没有此人的信息\n");
	}
	else 
	{
		printf("姓名：%s\n",p->num[ret].name);
		printf("性别：%s\n",p->num[ret].sex);
		printf("年龄：%d\n",p->num[ret].age);
		printf("联系方式：%s\n",p->num[ret].phone);
		printf("地址：%s\n",p->num[ret].address);
	}
}
void Mod_address(Point *p)
{
	int input = 0;
	char name[20] = {0};
	int ret = 0;
	printf("请选择要修改信息的人的姓名\n");
	scanf("%s",name);
	ret = Find(p,name);
	if(ret == -1)
	{
		printf("没有此人的信息\n");
	}
	else
	{
		printf("姓名：%s\n",p->num[ret].name);
		printf("性别：%s\n",p->num[ret].sex);
		printf("年龄：%d\n",p->num[ret].age);
		printf("联系方式：%s\n",p->num[ret].phone);
		printf("地址：%s\n",p->num[ret].address);
		printf("\n");
		do
		{
			menu2();
			printf("请选择要修改的信息\n");
			scanf("%d",&input);
			switch(input)
			{
			case EXIT2:
				break;
			case NAME:
				printf("姓名修改为：\n");
				scanf("%s",p->num[ret].name);
				break;
			case SEX:
				printf("性别修改为：\n");
				scanf("%s",p->num[ret].sex);
				break;
			case AGE:
				printf("年龄修改为：\n");
				scanf("%d",p->num[ret].age);
				break;
			case PHONE:
				printf("联系方式修改为：\n");
				scanf("%s",p->num[ret].phone);
				break;
			case ADDRESS:
				printf("地址修改为：\n");
				scanf("%s",p->num[ret].address);
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
			}

		}while(input);
	}
}
void menu2()
{
	printf("*********请选择要修改的*******\n");
	printf("******1.name      2.sex*******\n");
	printf("******3.age       4.phone*****\n");
	printf("******5.address   0.exit******\n");
	printf("******************************\n");
}
void Empty_address(Point *p)
{
	if(p->sz ==0 )
	{
		printf("没有联系人可以清空\n");
	}
	else
	{
	    p->sz = 0;
		printf("清空成功\n");
	}
}
void Sort_address(Point *p)
{
	int i = 0;
	int j = 0;
	for(i=0; i<p->sz - 1; i++)
	{
		for(j=0; j<p->sz - 1 - i; j++)
		{
			if(strcmp(p->num[j].name,p->num[j+1].name)>0)
			{
				Message temp;
				temp = p->num[j];
				p->num[j] = p->num[j+1];
				p->num[j+1] = temp;
			}
		}
	}
	printf("排序成功\n");
}
void Save_address(Point *p)
{
	FILE *pwrite;
    int i = 0;
	pwrite = fopen("address.txt","w");
	if(pwrite == NULL)
	{
		perror("open for the write");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<p->sz; i++)
	{
		fwrite(p->num+i,sizeof(Message),1,pwrite);	
	}
	fclose(pwrite);
	pwrite = NULL;
}
void Destory(Point *p)
{
	Save_address(p);
	free(p->num);
	p->num = NULL;
	p->count = 0;
	p->sz = 0;
}