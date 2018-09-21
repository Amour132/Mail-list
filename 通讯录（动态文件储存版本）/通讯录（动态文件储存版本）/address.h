#ifndef _ADDRESS_H
#define _ADDRESS_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#pragma warning(disable:4996)

enum Select
{
	EXIT,
	Add,
	Del,
	Search,
    Mod,
	Show,
	Empty,
	Sort
};

enum Mod
{
	EXIT2,
	NAME,
	SEX,
	AGE,
	PHONE,
	ADDRESS
};

typedef struct Message
{
	char name[20];
	char sex[10];
	int age;
	int phone[15];
	char address[50];

}Message;
typedef struct Point
{
	int count;
	int sz;
	Message *num;
}Point;

void init_address(Point *p);//��ʼ����Ϣ
void Show_address(Point *p);//��ʾ��ǰͨѶ¼��Ϣ
void Add_address(Point *p);//������Ϣ
void Del_address(Point *p);//ɾ����Ϣ
int Fine(Point *p,char *pname);//�����Ƿ���ڣ�ɾ�������ң��޸Ķ������õ�
void Search_address(Point *p);//������ϵ��
void Mod_address(Point *p);//�޸���Ϣ
void Empty_address(Point *p);//�����ϵ��
void Sort_address(Point *p);//����������
void menu2();//�޸ĵ�ѡ��˵�
int Expand(Point *p);//�ж��Ƿ���Ҫ����
void Destory(Point *p);//����ͨѶ¼ 
void Load_address(Point *p);//�����ϴε���Ϣ
void Save_address(Point *p);//����ͨѶ¼


#endif //_ADDRESS_H