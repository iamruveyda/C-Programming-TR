/*
Sayının Tersini Yazma

Girilen Sayı Değerinini tersten yazan program
C program to find reverse of a number using recursion

// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  


int ters = 0;
int basamak;



int tersinialma(int sayi)
{

	if (sayi)
	{
		basamak = sayi % 10;
		ters = ters * 10 + basamak;
		tersinialma(sayi /10);
	}

	else
		return ters;

}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;


	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &sayi);


	printf("\nSayının Tersi: %d", tersinialma(sayi));

	return 0;

}
