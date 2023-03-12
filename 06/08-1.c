/*

Girilen Sayının Palindromik Olup Olmadığını Bulmak
(Palindrom, tersten okunuşu da aynı olan cümle, sözcük ve sayılara denilmektedir.)

C program to check palindrome number using recursion

// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  

int palindrome(int sayi);
int tersinialma(int sayi);

int ters = 0;
int basamak;


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;


	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &sayi);


	if (palindrome(sayi) == 1)
	{
		printf("%d sayısı palindromik bir sayıdır.\n", sayi);
	}
	else
	{
		printf("%d sayısı palindromik bir sayı değildir.\n", sayi);
	}

	return 0;


}


int palindrome(int sayi)
{
	if (sayi == tersinialma(sayi))
	{
		return 1;
	}

	return 0;

}


int tersinialma(int sayi)
{

	if (sayi)
	{
		basamak = sayi % 10;
		ters = ters * 10 + basamak;
		tersinialma(sayi / 10);
	}

	else
		return ters;

}
