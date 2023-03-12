/*

İki Sayı Arasındaki Çift ve Tek Sayıları Yazdırma

Verilen aralıkta çift ve tek sayıların yazdırılması için C programı
C program to print even and odd numbers in given range using recursion

// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  


int fonk(int sayi1,int sayi2)
{
	

	if (sayi2 >= sayi1)
	{
		if (sayi1 % 2 != 0)
		{
			
			printf("Tek : %d\n", sayi1);
			return fonk(sayi1 + 1, sayi2);



		}

		else if (sayi1 % 2 == 0)
		{
			
			printf("Çift: %d\n", sayi1);
			return fonk(sayi1 + 1, sayi2);
	
		}
	}

	else
		return 0;

}



int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi1, sayi2;

	printf("Lütfen bir tam sayı giriniz (AltSınır): ");
	scanf("%d", &sayi1);

	printf("\nLütfen bir tam sayı giriniz (Üst Sınır): ");
	scanf("%d", &sayi2);

	fonk(sayi1 + 1, sayi2);

	return 0;

}
