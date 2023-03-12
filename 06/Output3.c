#include<stdio.h> 

void fun(int x)
{
	if (x < 1)
	{
		return;
	}

	fun(x - 1);

	fun(x - 3);

	printf("%d\t", x);

}

int main()
{
	int a = 4;

	fun(a);

	getchar();
	
	return 0;
}