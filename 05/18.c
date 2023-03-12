/* Örüntü Bulma

//String (Karakter Tutan Diziler)

Klavyeden girilen bir karakter dizisinde kaç tane “ak” örüntüsünün olduğunu bulma

*/

#include <stdio.h>
#include <locale.h>



int uzunlukbulma(char metin[])
{
	int i = 0;

	while (metin[i] != '\0')  //Null görene kadar dönmeye devam eder.
	{
		i++;
	}
	return i;

}

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[100];

	int sayac = 0,i;

	printf("Metin Giriniz: ");
	gets(metin);

	int uzunluk = uzunlukbulma(metin);

	for (i = 0; i < uzunluk; i++)
	{
		if (metin[i] == 'a' && metin[i + 1] == 'k')
		{
			sayac++;
		}
	}

	printf("\n%d tane 'ak' vardır.\n", sayac);

	return 0;

}
