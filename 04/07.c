/*
Rastgele sırada sunum yapılması için bir program yazılması gerekmektedir. 
Sunum listesi bir dizide saklanmalıdır. rastgeleSıralamaOlustur isimli bir fonksiyonu diziyi ve 
dizinin boyutunu parametre olarak alacak şekilde yazınız. Lütfen programın tamamını kodlayınız.


In order to make a presentation in random order, a program must be written. 
The presentation list should be stored in an array. Write a function called generateRandomOrder 
which takes an array and size of the array as a parameter. Please write the entire program.


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define SIZE 100


int rastgeleSiralamaOlustur(int dizi[], int x)

{
	int i, j = 0, random;

	for (i = 0; i < x; i++)
	{
		random = 1 + rand() % x;

		for (j = 0; j <= i; j++)
		{
			if (i == j) //Eğer üretilen sayı önceki değerlerden farklıysa
			{
				dizi[i] = random;
			}
			else if (random == dizi[j]) // Eğer üretilen sayı dizide ise
			{
				i--;
				break;
			}

		}

	}

}


int main()
{
	setlocale(LC_ALL, "Turkish");

	srand(time(NULL)); ////Rastgele Sayı Üretimi

	int ogrenci_sayisi;

	printf("Öğrenci Sayısını Giriniz: ");
	scanf("%d", &ogrenci_sayisi);

	int dizi[SIZE];

	rastgeleSiralamaOlustur(dizi, ogrenci_sayisi);

	int i = 0;

	for (i = 0; i < ogrenci_sayisi; i++)
		printf("%d. Sırada Sunacak Kişi - Listedeki %d. Öğrenci\n", i + 1, dizi[i]);

	return 0;

}
