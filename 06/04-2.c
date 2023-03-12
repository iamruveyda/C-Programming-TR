/*
İki Sayı Arasındaki Tam Sayıları Toplama 


C program to find sum of natural numbers in a given range using recursion

// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  


int topla(int sayi1, int sayi2)
{

	if (sayi1 == sayi2)
	{
		return sayi1;
	}

	else
		return sayi1 + topla(sayi1 + 1, sayi2);


}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi1, sayi2;

	printf("Lütfen bir tam sayı giriniz (AltSınır): ");
	scanf("%d", &sayi1);

	printf("\nLütfen bir tam sayı giriniz (Üst Sınır): ");
	scanf("%d", &sayi2);

	printf("\n%d ve %d arasındaki tam sayıların toplamı: %d", sayi1, sayi2, topla(sayi1, sayi2));

	return 0;

}
