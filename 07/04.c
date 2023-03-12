/*
Dizideki Metnin Tüm Permütasyonlarını Yazma

//Pointer Kullanımı


*/



#include <stdio.h>  
#include <locale.h>  
#define SIZE 100



int uzunlukbulma(char metin[])
{
/*

strlen() fonksiyonun işlevini yapar.
(strlen fonksiyonu başlangıç adresini aldığı yazının uzunluğu ile geri döner.)

*/
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

int yerdegistirme(char *metin1, char *metin2)
{
	char k;

	k = *metin1;
	*metin1 = *metin2;
	*metin2 = k;

	return k;

}



void permutasyon(char* ptr,int x, int y)
{
	int i;

	if (x == y)
	{
		printf("%s\n", ptr);
	}
	else
	{
		for (i = x; i < y; i++)
		{
			yerdegistirme((ptr + x), (ptr + i));

			permutasyon(ptr, x + 1, y);

			yerdegistirme((ptr + x), (ptr + i));
		}
	}


}



int main()
	{
		setlocale(LC_ALL, "Turkish");


		char metin[SIZE];

		printf("Metin giriniz: ");
		gets(metin);    // alternatif: scanf("%s", metin);


		int uzunluk = uzunlukbulma(metin);


		permutasyon(metin, 0, uzunluk);


}
