#include"com.h"
#include "vld.h"

static void show_all(Inf *a)
{
	printf("姓名\t");
	printf("年龄\t");
	printf("性别\t");
	printf("籍贯\t");
	printf("学院\t");
	printf("专业\t");
	printf("学号\t");
	printf("年级\n");
	printf("%s\t", a->name);
	printf("%d\t", a->age);
	printf("%s\t", a->sex);
	printf("%s\t", a->add);
	printf("%s\t", a->col);
	printf("%s\t", a->spe);
	printf("%d\t", a->num);
	printf("%d\t", a->clas);
	printf("\n");
}

static void put(Inf *a)
{

	printf("姓名:");
	scanf_s("%s", a->name, 20);
	printf("年龄:");
	scanf_s("%d", &a->age);
	printf("性别:");
	scanf_s("%s", &a->sex, 4);
	printf("籍贯:");
	scanf_s("%s", &a->add, 20);
	printf("学院:");
	scanf_s("%s", a->col, 20);
	printf("专业:");
	scanf_s("%s", a->spe, 20);
	printf("学号:");
	scanf_s("%d", &a->num);
	printf("年级:");
	scanf_s("%d", &a->clas);
	strcpy_s(a->recol, a->col);
	strcpy_s(a->respe, a->spe);

}

void input()
{
	FILE *fp = NULL;
	fopen_s(&fp, "E:\\inf.txt", "a");
	Inf *a = NULL;
	a = (Inf *)malloc(sizeof(Inf) * 1);
	put(a);
	fwrite(a, sizeof(Inf), 1, fp);
	free(a);
	fclose(fp);
	printf("\n");
}

static void insert(Inf *tmp, Inf *b)
{
	Inf *a = b->next;
	b->next = b->next->next;
	a->next = tmp->next;
	tmp->next = a;
}

static Inf * sort_name(Inf *b)
{

	Inf start;
	start.next = b;
	Inf *tmp = &start;

	while (b->next != NULL)
	{
		bool x = false;
		tmp = &start;
		Inf *p = NULL;
		while (tmp != b)
		{
			if (x == false && strcmp(tmp->next->name, b->next->name) > 0)
			{
				p = tmp;
				x = true;
			}
			tmp = tmp->next;
		}
		if (p != NULL)
		{
			insert(p, b);
		}
		else
			{
				b = b->next;
			}
	}
	b->next = NULL;
	return start.next;
}

static void frd(FILE **fp, Inf ** start)
{
	fopen_s(fp, "E:\\inf.txt", "r");
	if (fp == NULL)
	{
		printf("无文件\n");
		return;
	}

	Inf *a = (Inf *)malloc(sizeof(Inf) * 1);
	*start = a;
	int i = fread_s(a, sizeof(Inf), sizeof(Inf), 1, *fp);
	Inf *m = a;
	while (i > 0)
	{
		m = a;
		a = a->next = (Inf *)malloc(sizeof(Inf) * 1);

		i = fread_s(a, sizeof(Inf), sizeof(Inf), 1, *fp);
	}
	m->next = NULL;

}

static void show_name()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);

	printf("姓名:\t");
	char arr[20];
	scanf_s("%s", arr, sizeof(arr));

	while (start->next != NULL)
	{
		a = start;
		if (strcmp(arr, a->name) == 0)
		{
			show_all(a);
		}
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_age()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("年龄:\t");
	int arr;
	scanf_s("%d", &arr);

	while (start->next != NULL)
	{
		a = start;
		if (arr == a->age)
		{
			show_all(a);
		}

		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_sex()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("性别:\t");
	char arr[20];
	scanf_s("%s", arr, sizeof(arr));

	while (start->next != NULL)
	{
		a = start;
		if (strcmp(arr, a->sex) == 0)
		{
			show_all(a);
		}
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_add()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("籍贯:\t");
	char arr[20];
	scanf_s("%s", arr, sizeof(arr));

	while (start->next != NULL)
	{
		a = start;
		if (strcmp(arr, a->add) == 0)
		{
			show_all(a);
		}
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_col()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("学院:\t");
	char arr[20];
	scanf_s("%s", arr, sizeof(arr));

	while (start->next != NULL)
	{
		a = start;
		if (strcmp(arr, a->col) == 0)
		{
			show_all(a);
		}
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_spe()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("专业:\t");
	char arr[20];
	scanf_s("%s", arr, sizeof(arr));

	while (start->next != NULL)
	{
		a = start;
		if (strcmp(arr, a->spe) == 0)
		{
			show_all(a);
		}
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_num()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("学号:\t");
	int arr;
	scanf_s("%d", &arr);

	while (start->next != NULL)
	{
		a = start;
		if (a->num == arr)
		{
			show_all(a);
		}

		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show_clas()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("年级:\t");
	int arr;
	scanf_s("%d", &arr);

	while (start->next != NULL)
	{
		a = start;
		if (arr == a->clas)
		{
			show_all(a);
		}
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

void show_cs()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	frd(&fp, &start);
	printf("姓名\t");
	printf("原学院\t");
	printf("原专业\t");
	printf("现学院\t");
	printf("现专业\n");

	while (start->next != NULL)
	{
		a = start;
		printf("%s\t", a->name);
		printf("%s\t", a->recol);
		printf("%s\t", a->respe);
		printf("%s\t", a->col);
		printf("%s\t", a->spe);
		if (strcmp(a->respe, a->spe) == 0)
		{
			printf("未转专业\t");
		}
		printf("\n");
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

static void show()
{
	FILE *fp = NULL;
	Inf * start = NULL;
	frd(&fp, &start);
	Inf * a = start;

	printf("所有信息:\n");
	printf("姓名\t");
	printf("年龄\t");
	printf("性别\t");
	printf("籍贯\t");
	printf("学院\t");
	printf("专业\t");
	printf("学号\t");
	printf("年级\n");

	start = sort_name(start);
	while (start->next != NULL)
	{
		a = start;
		printf("%s\t", a->name);
		printf("%d\t", a->age);
		printf("%s\t", a->sex);
		printf("%s\t", a->add);
		printf("%s\t", a->col);
		printf("%s\t", a->spe);
		printf("%d\t", a->num);
		printf("%d\t", a->clas);
		printf("\n");
		start = start->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);

}

void choice_show()
{
	printf("a.姓名\t");
	printf("b.年龄\t");
	printf("c.性别\t");
	printf("d.籍贯\t");
	printf("e.学院\t");
	printf("f.专业\t");
	printf("g.学号\t");
	printf("h.年级\t");
	printf("i.all\n");
	getchar();
	char ch;
	scanf_s("%c", &ch, 1);
	switch (ch)
	{
	case 'a': show_name(); break;
	case 'b': show_age(); break;
	case 'c': show_sex(); break;
	case 'd': show_add(); break;
	case 'e': show_col(); break;
	case 'f': show_spe(); break;
	case 'g': show_num(); break;
	case 'h': show_clas(); break;
	case 'i': show();
	default:
		break;

	}
}

void Dele()
{
	int arr = -1;
	char brr[20] = { '\0' };
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	Inf * b = NULL;
	char ch = 'o';

	printf("a.姓名\t");
	printf("b.年龄\t");
	printf("c.性别\t");
	printf("d.籍贯\t");
	printf("e.学院\t");
	printf("f.专业\t");
	printf("g.学号\t");
	printf("h.年级\n");
	getchar();
	scanf_s("%c", &ch, 1);

	switch (ch)
	{
	case 'a': printf("姓名:"); scanf_s("%s", brr, 20); break;
	case 'b': printf("年龄:"); scanf_s("%d", &arr);  break;
	case 'c': printf("性别:"); scanf_s("%s", brr, 20);  break;
	case 'd': printf("籍贯:"); scanf_s("%s", brr, 20);  break;
	case 'e': printf("学院:"); scanf_s("%s", brr, 20); break;
	case 'f': printf("专业:"); scanf_s("%s", brr, 20);  break;
	case 'g': printf("学号:"); scanf_s("%d", &arr); break;
	case 'h': printf("年级:"); scanf_s("%d", &arr); break;
	default:
		break;
	}

	frd(&fp, &start);

	Inf c;
	c.next = start;
	a = &c;
	while (a->next != NULL)
	{
		b = a->next;
		switch (ch)
		{
		case 'a': if (strcmp(brr, a->next->name) == 0)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'b': if (arr == a->next->age)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'c': if (strcmp(brr, a->next->sex) == 0)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'd': if (strcmp(brr, a->next->add) == 0)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'e': if (strcmp(brr, a->next->col) == 0)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'f': if (strcmp(brr, a->next->spe) == 0)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'g': if (arr == a->next->num)
		{
			a->next = a->next->next; free(b); b = NULL;
		}
				  break;
		case 'h': if (arr == a->next->clas)
		{
			a->next = a->next->next;	 free(b); b = NULL;
		}
				  break;
		default:
			break;
		}
		if (b != NULL)
		{
			a = a->next;
		}

	}
	b = c.next;
	fclose(fp);
	fopen_s(&fp, "E:\\inf.txt", "w");
	if (fp == NULL)
	{
		printf("无文件\n");
		return;
	}
	while (b != NULL)
	{
		fwrite(b, sizeof(Inf), 1, fp);
		a = b;
		b = b->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}

void chge()
{

	int arr = -1;
	char brr[20] = {'\0'};
	FILE *fp = NULL;
	Inf * start = NULL;
	Inf * a = NULL;
	Inf * b = NULL;
	char ch = 'o';

	printf("a.姓名\t");
	printf("b.年龄\t");
	printf("c.性别\t");
	printf("d.籍贯\t");
	printf("e.学院\t");
	printf("f.专业\t");
	printf("g.学号\t");
	printf("h.年级\n");
	getchar();
	scanf_s("%c", &ch, 1);

	switch (ch)
	{
	case 'a': printf("姓名:"); scanf_s("%s", brr, 20); break;
	case 'b': printf("年龄:"); scanf_s("%d", &arr);  break;
	case 'c': printf("性别:"); scanf_s("%s", brr, 20);  break;
	case 'd': printf("籍贯:"); scanf_s("%s", brr, 20);  break;
	case 'e': printf("学院:"); scanf_s("%s", brr, 20); break;
	case 'f': printf("专业:"); scanf_s("%s", brr, 20);  break;
	case 'g': printf("学号:"); scanf_s("%d", &arr); break;
	case 'h': printf("年级:"); scanf_s("%d", &arr); break;
	default:
		break;
	}

	frd(&fp, &start);
	b = start;

	while (start->next != NULL)
	{
		a = start;
		switch (ch)
		{
		case 'a': if (strcmp(brr, a->name) == 0)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'b': if (arr == a->age)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'c': if (strcmp(brr, a->sex) == 0)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'd': if (strcmp(brr, a->add) == 0)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'e': if (strcmp(brr, a->col) == 0)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'f': if (strcmp(brr, a->spe) == 0)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'g': if (arr == a->num)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		case 'h': if (arr == a->clas)
		{
			put(a);
			a->next = start->next;
		}
				  break;
		default:
			break;
		}
		start = start->next;
	}
	fclose(fp);
	fopen_s(&fp, "E:\\inf.txt", "w");
	if (fp == NULL)
	{
		printf("无文件\n");
		return;
	}
	while (b != NULL)
	{
		fwrite(b, sizeof(Inf), 1, fp);
		a = b;
		b = b->next;
		free(a);
	}
	rewind(fp);
	fclose(fp);
}
