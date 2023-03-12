/*
İki Sayının EBOB ve EKOK'unu Bulan Program


En Büyük Ortak Bölenini (Ebob) Bulma
(Her ikisini de tam bölen tam sayıların en büyüğüdür)
C program to find GCD (HCF) of two numbers using recursion


En Küçük Ortak Kat (EKOK)Bulma
C program to find LCM of two numbers using recursion


// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  


int ebob(int sayi1, int sayi2)
{
	if (sayi2 != 0)
	{
		return ebob(sayi2, sayi1 % sayi2);
	}

	else
	{
		return sayi1;
	}

}

int ekok(int sayi1, int sayi2)
{

	return (sayi1 * sayi2) / ebob(sayi1, sayi2);

}



int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi1, sayi2;
	int EBOB, EKOK;


	printf("İki Sayı Giriniz: \n");
	scanf("%d  %d", &sayi1, &sayi2);

	if (sayi1 > sayi2)
	{
		EBOB = ebob(sayi1, sayi2);
		EKOK = ekok(sayi1, sayi2);
	}
	else

		EBOB = ebob(sayi2, sayi1);
		EKOK = ekok(sayi2, sayi1);


	printf("EBOB(%d,%d)= %d", sayi1, sayi2, EBOB);
	printf("\nEKOK(%d,%d)= %d", sayi1, sayi2, EKOK);


	return 0;

}
