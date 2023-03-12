/*

Faktöriyel Hesaplama
// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  


int faktoriyel(int sayi)
{
	if (sayi >= 1)
	{

		return sayi * faktoriyel(sayi - 1);
	
	/*
		ÖRNEK= 5!

				5 * faktoriyel(5)
					4 * faktoriyel(3)
						3*faktoriyel(2)
							2 * faktoriyel(1)
								1 *faktoriyel(0)
										1
	*/
	}

	else
		return 1;
}





int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;


	printf("Bir tam sayı giriniz: ");
	scanf("%d", &sayi);

	printf("%d!= %d\n", sayi, faktoriyel(sayi));


	return 0;

	/*
	while (1) //Sonsuz Döngü de olsun. Program bitmesin.
	{
		printf("Bir tam sayı giriniz: ");
		scanf("%d", &sayi);
		printf("%d!= %d\n", sayi, faktoriyel(sayi));
	}
	return 0;
	*/


}
