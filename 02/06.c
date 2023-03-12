/* İki Sayının EBOB'unu Bulan Program */

#include <stdio.h>
#include <locale.h>

int main()

{

	setlocale(LC_ALL, "Turkish");

	int x, y, min;

	int i, ebob = 1;

	printf("Birinci Sayıyı Giriniz:");
	scanf("%d", &x);

	printf("Ikinci Sayıyı Giriniz:");
	scanf("%d", &y);

	if (x < y)
		min = x;
	min = y;

	for (i = 2; i <= min; i++)

	{
		if (x % i == 0 && y % i == 0)
			ebob = i;
	}

	printf("EBOB(%d,%d) = %d", x, y, ebob);


	return 0;
}
