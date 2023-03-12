/*

Girilen Sayının Asal Sayı Olup Olmadığını Kontrol Etmek

// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  


int asal(int sayi, int x)
{
	if (x == 1)
	{
		return 1;
	}
	else
	{
		if (sayi % x == 0)
		{
			return 0;
		}
		else
		{
			return asal(sayi, x - 1);
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;

	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &sayi);

	int kontrol = asal(sayi,sayi/ 2);


	if (kontrol == 1)
	{
		printf("\nASAL SAYIDIR");
		printf("\n");
	}
	else
	{
		printf("\nASAL SAYI DEĞİLDİR");
		printf("\n");
	}
	return 0;

}