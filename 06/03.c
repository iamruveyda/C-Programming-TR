/*

Tam Sayının Üssünü Almak

C program to find power of a number using recursion

// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  


int fonk(int sayi1, int sayi2)
{
	if (sayi2 != 0)
	{
		return sayi1 * fonk(sayi1, sayi2 - 1);


	/*
		ÖRNEK= 2^3

		2*fonk(2,2)
			2*fonk(2,1)
				2*fonk(2,0)
					   1	
		
	*/

	}

	else

		return 1;


}



int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi1, sayi2;

	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &sayi1);

	printf("Lütfen üssünü giriniz: ");
	scanf("%d", &sayi2);

	int sonuc = fonk(sayi1, sayi2);

	printf("%d ^ %d = %d", sayi1, sayi2, sonuc);


	return 0;

}
