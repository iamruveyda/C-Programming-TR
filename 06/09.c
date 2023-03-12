/*

Basamak Değerlerinin Toplamı

C program to find sum of digits using recursion

// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  




int basamakdegerleritoplamı(int sayi)
{
	if (sayi == 0)
		return 0;
	else
		return (sayi % 10) + basamakdegerleritoplamı(sayi / 10);

	/*
	
	Örnek= 125 Sayısı

		5+basamakdegerleritoplamı(12)
			2+basamakdegerleritoplamı(1)
				1+basamakdegerleritoplamı(0)
	
	
	*/

}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;


	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &sayi);


	printf("\nBasamak Değerleri Toplamı = %d\n", basamakdegerleritoplamı(sayi));

	return 0;

}
