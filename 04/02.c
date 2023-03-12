/* Tam Sayının Üssünü Almak

C program to find power of a number using function

Write a C program to input a number from user and find power of given number.

// Fonksiyon Kullanımı

*/

#include <stdio.h>    
#include <locale.h>  


int fonk(int x, int y)
{
	int i;

	int sonuc = 1;

	for (i = 0; i < y; i++)
	{
		sonuc *= x;
	}

	return sonuc;
}

int main()
{

	setlocale(LC_ALL, "Turkish");

	int x, y;

	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &x);

	printf("\n");

	printf("Lütfen üssünü giriniz: ");
	scanf("%d", &y);

	printf("\nSonuç: %d\n", fonk(x, y));

}
