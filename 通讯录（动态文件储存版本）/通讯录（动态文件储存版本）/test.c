#include "address.h"

Point stu;

void menu()
{
	printf("*************************\n");
	printf("*****1.add     2.del*****\n");
	printf("*****3.search  4.mod*****\n");
	printf("*****5.show    6.empty***\n");
	printf("*****7.sort    0.exit****\n");
	printf("*************************\n");
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch(input)
		{
		case EXIT:
			Destory(&stu);
			printf("�˳�����\n");
			break;
		case Add:
			Add_address(&stu);
			break;
		case Del:
			Del_address(&stu);
			break;
		case Search:
			Search_address(&stu);
			break;
		case Mod:
			Mod_address(&stu);
			break;
		case Show:
			Show_address(&stu);
			break;
		case Empty:
			Empty_address(&stu);
			break;
		case Sort:
			Sort_address(&stu);
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}

	}while(input);
}
int main()
{
	init_address(&stu);
	test();
	return 0;
}