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
		printf("���ݳɹ�\n");
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
		printf("ͨѶ¼����\n");
	}
	else
	{
		if(Expand(p) == 0)
		{
			return;
		}
		printf("������Ҫ��ӵ�����\n");
		scanf("%s",p->num[p->sz].name);
		printf("������Ҫ��ӵ��Ա�\n");
		scanf("%s",p->num[p->sz].sex);
		printf("������Ҫ��ӵ�����\n");
		scanf("%d",&(p->num[p->sz].age));
		printf("������Ҫ��ӵ��ֻ�����\n");
		scanf("%s",p->num[p->sz].phone);
		printf("������Ҫ��ӵ�סַ\n");
		scanf("%s",p->num[p->sz].address);
		printf("��ӳɹ�\n");
		p->sz++;
	}
}
void Show_address(Point *p)
{
	int i = 0;
	printf("%-10s%-5s%-5s%-13s%-8s\n","����","�Ա�","����","�ֻ���","��ַ");
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
		printf("û�п�ɾ������Ϣ,ɾ��ʧ��\n");
	}
	else
	{
		printf("������Ҫɾ���˵�����\n");
		scanf("%s",name);
		ret = Find(p,name);
		if(ret == -1)
		{
			printf("û�д��˵���Ϣ,ɾ��ʧ��\n");
		}
		else
		{
			p->num[ret] = p->num[ret+1];
			p->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}
void Search_address(Point *p)
{
	char name[20] = {0};
	int ret = 0;
	printf("����������˵�����\n");
	scanf("%s",name);
	ret = Find(p,name);
	if(ret == -1)
	{
		printf("û�д��˵���Ϣ\n");
	}
	else 
	{
		printf("������%s\n",p->num[ret].name);
		printf("�Ա�%s\n",p->num[ret].sex);
		printf("���䣺%d\n",p->num[ret].age);
		printf("��ϵ��ʽ��%s\n",p->num[ret].phone);
		printf("��ַ��%s\n",p->num[ret].address);
	}
}
void Mod_address(Point *p)
{
	int input = 0;
	char name[20] = {0};
	int ret = 0;
	printf("��ѡ��Ҫ�޸���Ϣ���˵�����\n");
	scanf("%s",name);
	ret = Find(p,name);
	if(ret == -1)
	{
		printf("û�д��˵���Ϣ\n");
	}
	else
	{
		printf("������%s\n",p->num[ret].name);
		printf("�Ա�%s\n",p->num[ret].sex);
		printf("���䣺%d\n",p->num[ret].age);
		printf("��ϵ��ʽ��%s\n",p->num[ret].phone);
		printf("��ַ��%s\n",p->num[ret].address);
		printf("\n");
		do
		{
			menu2();
			printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
			scanf("%d",&input);
			switch(input)
			{
			case EXIT2:
				break;
			case NAME:
				printf("�����޸�Ϊ��\n");
				scanf("%s",p->num[ret].name);
				break;
			case SEX:
				printf("�Ա��޸�Ϊ��\n");
				scanf("%s",p->num[ret].sex);
				break;
			case AGE:
				printf("�����޸�Ϊ��\n");
				scanf("%d",p->num[ret].age);
				break;
			case PHONE:
				printf("��ϵ��ʽ�޸�Ϊ��\n");
				scanf("%s",p->num[ret].phone);
				break;
			case ADDRESS:
				printf("��ַ�޸�Ϊ��\n");
				scanf("%s",p->num[ret].address);
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;
			}

		}while(input);
	}
}
void menu2()
{
	printf("*********��ѡ��Ҫ�޸ĵ�*******\n");
	printf("******1.name      2.sex*******\n");
	printf("******3.age       4.phone*****\n");
	printf("******5.address   0.exit******\n");
	printf("******************************\n");
}
void Empty_address(Point *p)
{
	if(p->sz ==0 )
	{
		printf("û����ϵ�˿������\n");
	}
	else
	{
	    p->sz = 0;
		printf("��ճɹ�\n");
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
	printf("����ɹ�\n");
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