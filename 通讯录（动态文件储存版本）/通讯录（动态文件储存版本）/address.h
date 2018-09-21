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

void init_address(Point *p);//初始化信息
void Show_address(Point *p);//显示当前通讯录信息
void Add_address(Point *p);//增加信息
void Del_address(Point *p);//删除信息
int Fine(Point *p,char *pname);//查找是否存在，删除，查找，修改都可以用到
void Search_address(Point *p);//查找联系人
void Mod_address(Point *p);//修改信息
void Empty_address(Point *p);//清空联系人
void Sort_address(Point *p);//以名字排序
void menu2();//修改的选择菜单
int Expand(Point *p);//判断是否需要扩容
void Destory(Point *p);//销毁通讯录 
void Load_address(Point *p);//加载上次的信息
void Save_address(Point *p);//保存通讯录


#endif //_ADDRESS_H