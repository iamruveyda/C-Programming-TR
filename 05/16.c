/* Her Harfin Tekrar Sayısını Bulma (2)

//String (Karakter Tutan Diziler)

//Fonksiyon ile yazımı

//While ile

Klavyeden girilen bir metnin içerisinde her harfin tekrar sayısını bularak ekrana yazdıran C kodu

ASCII Değerleri A=65,a=97,enter=13
*/

#include <stdio.h>
#include <locale.h> 
#define SIZE 150


void fonksiyon(char x[], int sayac[])
{
	int i = 0;
	
	while (x[i] != '\0')
	{
		if (x[i] >= 'a' && x[i] <= 'z')
			
			sayac[x[i] - 'a']++;

		else if (x[i] >= 'A' && x[i] <= 'Z')
			
			sayac[x[i] - 'A']++;
		
		i++;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[256];
	int i;
	int sayac[SIZE] = { 0 };

	printf("Metin Giriniz: ");
	gets(metin);

	fonksiyon(metin, sayac);

	for (i = 0; i < SIZE; i++)
	{
		if (sayac[i] != 0)
			printf("%d tane %c harfi vardir.\n", sayac[i], i + 65);
	}
	
	getch();
		
	return 0;
}
