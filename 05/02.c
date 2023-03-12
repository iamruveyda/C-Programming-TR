/* Metni Tersten Yazdırma Programı

//String (Karakter Tutan Diziler)
//For ile
//Fonksiyonla yazımı

Klavyeden girilen metni tersten ekrana yazdıran C programı */

#include <stdio.h>
#include <locale.h> 
#define SIZE 100

int uzunlukbulma(char metin[])
{

	int i = 0; // karakter sayısını alacak


	while (1) // Sonsuz Döngü
	{
		if (metin[i] == '\0') // '\0' simgesi NULL(bos) karakter
		{
			break; //NULL gelince sonsuz döngüden çıkıyoruz
		}

		i++;

	}

	return i; //Metnin uzunluğunu verir.

	/* Alternatif
	while(metin[i] != '\0')  //Null görene kadar dönmeye devam eder.
		{
			i++;
		}
			return i;
	*/

}


int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[SIZE];

	printf("Metin giriniz: ");
	gets(metin);    // alternatif: scanf("%s", metin);

	int uzunluk = uzunlukbulma(metin);

	int sayac = 0;


	printf("\nMetnin Tersi: ");
	
	for (sayac = uzunluk - 1; sayac >= 0; sayac--)
	{
		putchar(metin[sayac]); // printf("%c", metin[sayac]) //Belirtilen karakteri ekrana yazar.
	}

	printf("\n");

}
