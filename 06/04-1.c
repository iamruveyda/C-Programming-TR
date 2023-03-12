/*

İki Sayı Arasındaki Tam Sayıları Yazdırma

Program to print integers in a given range using recursion

// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  


int fonk(int sayi1,int sayi2)
{
	
	if (sayi2 >= sayi1)
	{
		printf("%d ", sayi1);

		fonk(sayi1 + 1, sayi2);
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

	printf("\n%d ve %d arasındaki tam sayılar: \n", sayi1, sayi2);
	
	printf("\n");

    fonk(sayi1, sayi2);
	
	return 0;

}
