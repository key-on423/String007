#include <stdio.h>
#include <string.h>

//12.设计一个函数，接受一个只想字符串的指针，返回只想该字符串第一个空格字符的指针，或如果为找到空格字符，则返回空指针
//#define max 30
//char* findkong(char* st);
//char* s_gets(char* st, int n);
//int main()
//{
//
//	char* arr1;
//	char arr2[max];
//	char* find;
//	printf("请输入一串字符：\n");
//	arr1=s_gets(arr2,max);
//	find=findkong(arr1);
//	if (find != NULL)
//		printf("可以找到空格字符，位置为%p\n", find);
//	return 0;
//}
//char* findkong(char* st)
//{
//	while (*st != ' '&&*st!='\n'&&*st!='\0')
//		st++;
//	if (*st == ' ')
//		return st;
//	else
//		return NULL;
//}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (*st != '\n' && *st != '\0')
//			st++;
//		if (*st == '\n')
//			*st = '\0';
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}


//13.使用ctype.h头文件中的函数，以便无论用户选择大写还是小写，该程序都能正确识别答案
#define ANSWER "GRANT"
#define SIZE 40
#include <ctype.h>
void Toupper(char* st);
char* s_gets(char* st, int n);
int main()
{
	char try[SIZE];
	puts("Who is buried in Grant's tomb?");
	s_gets(try, SIZE);
	Toupper(try);
	while (strcmp(try, ANSWER) != 0)
	{
		puts("No,that's wrong. Try again.");
		s_gets(try, SIZE);
		Toupper(try);
	}
	puts("That's right!");
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	char* find;
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
void Toupper(char* st)
{
	
	while (*st != '\0')
	{
		*st = toupper(*st);
		st++;
	}
}