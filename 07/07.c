/*
Rastgele Oluşan Dizideki Rakamları Tek Ve Çift Olarak Ayırma
Dinamik bellek ayırma yöntemi kullanılarak 20 elemanlı bir dizi oluşturulacak.
Bu dizinin elemanları 1 ile 9 arasındaki sayıları rastgele değerlerle program dolduracak.
Oluşturulan dizideki rakamların tekleri bir diziye çiftleri ayrı bir diziye yerleştirerek çıktı oluşturulacak.
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <time.h>


int main(void)
{
	setlocale(LC_ALL, "Turkish");

	srand(time(NULL)); //Rastgele Sayı Üretimi

	int i;

	int cift_sayac = 0;

	int tek_sayac = 0;

	int* dizi;  //Ana dizi için bir pointer

	int* cift;  //Çift sayılar için bir dizi

	int* tek;   //Tek Sayılar için bir dizi


	if ((dizi = malloc(20 * sizeof (int))) == NULL)
	{
		printf("YETERLI HAFIZA YOK");
	}

	cift = realloc(dizi, 20 * sizeof(int));


	if ((tek = malloc(20 * sizeof ( int))) == NULL)
	{
		printf("YETERLI HAFIZA YOK");
	}


	dizi = &dizi[0]; //Pointer ile dizi aynı isimle koyarak ekstra bir dizi tanımlamamıza gerek olmuyor.


	for (i = 0; i < 20; ++i)
	{

		dizi[i] = 1 + (rand() % 9);

		printf("%.2d. Eleman= %d\n", i + 1, dizi[i]);


		if (dizi[i] % 2 == 0) //Çift Kontrolü
		{
			cift[cift_sayac] = dizi[i];
			cift_sayac++;
		}

		else //diğerleri de tek oluyor.
		{
			tek[tek_sayac] = dizi[i];
			tek_sayac++;
		}
	}


	printf("\nÇİFT SAYILAR\n");

	for (i = 0; i < cift_sayac; i++)
	{
		printf("%d  ", cift[i]);
	}

	printf("\n");


	printf("\nTEK SAYILAR\n");

	for (i = 0; i < tek_sayac; i++)
	{
		printf("%d  ", tek[i]);
	}

	printf("\n");

	free(dizi);
	free(tek);

}
