#include <stdio.h>

int fun(int x, int y)
{
	if (x == y)
		return x;

	if (x > y)
	{
		printf("\n%d, %d\n", x, y);

		return fun(x - y, y);
	}

	return fun(x, y - x);
}

int main()
{
	int sayilar[] = { 132,48,55,47,-6 };

	int* ptr = &sayilar[3]; //ptr[0]=*(ptr+0)=sayilar[3] 


	/*  int* ptr;

	ptr= &sayilar[3];   */

	int sonuc = fun(sayilar[0], (*ptr) + 1);

	printf("\nfun(%d,%d) = %d\n", ptr[-3], *(ptr)+1, sonuc);

	return 0;
}
