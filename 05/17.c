/* Her Satırda Bir Harf Ekleyerek Kelimeyi Yazma

//String (Karakter Tutan Diziler)

//While ile

Klavyeden girilen bir kelimenin harflerini her bir satıda bir harf ekleyerek ekrana yazdıran C Kodu

ÖRNEK:

Kelimeyi Giriniz: Hello

H
He
Hel
Hell
Hello

*/

#include <stdio.h>
#include <locale.h> 
#define SIZE 150

int main()
{
	setlocale(LC_ALL, "Turkish");

	char kelime[SIZE];

	int i = 0, j;
		  
	printf("Kelimeyi Giriniz: ");
	gets(kelime);

	while (kelime[i] != NULL)
	{
		for(j = 0; j <= i; j++)
		{
			putchar(kelime[j]);
		}

		printf("\n");

		i++;
	}

	getch();
}
