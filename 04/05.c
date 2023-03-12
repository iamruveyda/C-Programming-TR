#include <stdio.h>
#include <locale.h>

/* İki Sayı Arasındaki Asal Sayıları Bulma


C Program to Display Prime Numbers Between Intervals Using Function
Example to print all prime numbers between two numbers (entered by the user) by making a user-defined function.

//Fonksiyon Kullanımı


*/

int func(int sayi);


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi1, sayi2;
	int i, j;

	printf("İki pozitif tam sayı giriniz: \n");
	scanf("%d %d", &sayi1, &sayi2);

	printf("\n");
	printf("İki sayı arasındaki asal sayılar: \n");

	for (i = sayi1 + 1; i < sayi2; ++i)
	{
		j = func(i);
		if (j == 1)
			printf("%d\n", i);
	}

	return 0;
}

int func(int sayi)
{
	int k, j = 1;

	for (k = 2; k <= sayi / 2; ++k)
	{
		if (sayi % k == 0)
		{
			j = 0;
			break;
		}
	}
	return j;
}
