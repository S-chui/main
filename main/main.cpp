#include "com.h"
#include "vld.h"

int main()
{
	int i = 0;
	while (i != 6)
	{
		printf("**********************************\n");
		printf("1.¼����Ϣ 2.�鿴��Ϣ   3.�޸���Ϣ \n4.ɾ����Ϣ 5.�鿴תרҵ 6.�˳�ϵͳ\n");
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


