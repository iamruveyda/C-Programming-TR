/* Metin de Aranan Kelimenin Olup Olmadığına Bakma

//String (Karakter Tutan Diziler)

*/

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[256];

	char arama[256];

	int sayac_1 = 0, sayac_2 = 0;

	int durum = 0;

	printf("Metin Giriniz: ");
	gets(metin); //alternatif: scanf("%s", metin);

	printf("\nMetinde Aranması Gereken Kelime: ");
	gets(arama);

	while (metin[sayac_1] != 0)
	{
		sayac_2 = 0;

		if (metin[sayac_1] == arama[sayac_2])
		{
			while (metin[sayac_1 + sayac_2] == arama[sayac_2])
				sayac_2++;

			if (arama[sayac_2] == '\0')
				durum = 1;
		}

		if (durum == 1) 
			break;
		
		sayac_1++;
	}
	
	if (durum)
		
		printf("\nAranan kelime, metin içerisinde bulunuyor.\n");
	else
		
		printf("\nAranan kelime, metin içerisinde bulunmuyor.\n");
	
	return 0;
}
