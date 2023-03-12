/* Harf/Rakam/Özel Karakter Sayılarını Bulma

//String (Karakter Tutan Diziler)

Klavyeden girilen metin içerisinde harf, rakam ve özel karakterlerin sayısını bulan C Programı

 >ASCII KOD<
 48  = 0
 57  = 9 
 65  = A
 90  = Z
 97  = a
 122 = z

 */

#include <stdio.h>
#include <locale.h>
#define SIZE 256

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[SIZE];

	int i = 0;

	int harf = 0, rakam = 0, ozel = 0;

	printf("Metin giriniz: ");
	gets(metin);

	while (metin[i] != 0)
	{
		char karakter = metin[i];

		if ((karakter >= 'a' && karakter <= 'z') || (karakter >= 'A' && karakter <= 'Z'))
			harf++;

		else if (karakter >= '0' && karakter <= '9')
			rakam++;

		else
			ozel++;

		i++;
	}

	printf("\nHarf Sayısı= %d \nRakamların Sayısı= %d \nÖzel Karakterlerin Sayısı= %d\n", harf, rakam, ozel);

	return 0;
}
