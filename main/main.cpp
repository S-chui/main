#include "com.h"
#include "vld.h"

int main()
{
	int i = 0;
	while (i != 6)
	{
		printf("**********************************\n");
		printf("1.录入信息 2.查看信息   3.修改信息 \n4.删除信息 5.查看转专业 6.退出系统\n");
		printf("**********************************\n");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			input(); break;
		case 2:
			choice_show(); break;
		case 3:
			chge(); break;
		case 4:
			Dele(); break;
		case 5:
			show_cs(); break;
		case 6:
		default:
			break;
		}
	}

	return 0;
}


