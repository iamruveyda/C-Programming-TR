/* Metnin Her Kelimesinin Harf Sayısını Bulma

//String (Karakter Tutan Diziler)

*/

#include <stdio.h>
#include <locale.h>
#define SIZE 256



int uzunlukbulma(char metin[])
{
	int i = 0;

	while(metin[i] != '\0')  //Null görene kadar dönmeye devam eder.
		{
			i++;
		}
			return i;

}


int main()
{
	setlocale(LC_ALL, "Turkish");


	char metin[SIZE];
	char ifade[SIZE] = { 0 };

	int i, sayac = 0;

	printf("Metin giriniz: ");
	gets(metin);    // alternatif: scanf("%s", metin);

	int uzunluk = uzunlukbulma(metin);


	for (i = 0; i < uzunluk; i++)
	{
		if (metin[i] == ' ')
		{
			sayac++;
		}

		else
		{
			ifade[sayac]++;
		}
	}

	for (i = 0; i <= sayac; i++)
	{
		printf("\n%d. Kelime: %d harf var.\n", i+1, ifade[i]);
	}

	return 0;
}
