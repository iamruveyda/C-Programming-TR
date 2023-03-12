/* Her Harfin Tekrar Sayısını Bulma (1)

//String (Karakter Tutan Diziler)

//While ile

Klavyeden girilen bir metnin içerisinde her harfin tekrar sayısını bularak ekrana yazdıran C kodu

ASCII Değerleri A=65,a=97,enter=13

*/

#include <stdio.h>
#include <locale.h> 
#define SIZE 150

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[256];
	int i=0,j;
	int sayac[SIZE] = { 0 };

	printf("Metin Giriniz: ");
	gets(metin);

	while (metin[i] != NULL)
	{
		sayac[metin[i] - 65]++;
		i++;
	}

	for (j = 0; j < SIZE; j++)
	{
		if (sayac[j] != 0)
			printf("%d tane %c harfi vardir.\n", sayac[j], j + 65);
	}

	getch();

	return 0;
}
