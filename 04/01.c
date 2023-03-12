/*
Şans Oyunu : Craps
•	İki zar atılır.
•	Zarların toplam hesaplanır.
•	İlk atışta 7 veya 11 gelirse oyuncu kazanır.
•	İlk atışta 2, 3 veya 12 gelirse oyuncu kaybeder.
•	İlk atışta 4, 5, 6, 8, 9 ve 10 gelirse bu oyuncunun puanı oluyor.
•	Oyuncu 7 atmadan önce kendi puanını tutturmalıdır.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int zaratma(void)
{
	int ilkzar, ikincizar, toplam;

	ilkzar = 1 + (rand() % 6);

	ikincizar = 1 + (rand() % 6);

	printf("İlk Zar: %d \n", ilkzar);
	printf("İkinci Zar: %d \n", ikincizar);

	toplam = ilkzar + ikincizar;
	printf("Oyuncunun Puanı: %d + %d = %d \n", ilkzar, ikincizar, toplam);
	printf("\n");


	return toplam;

}



int main()
{
	setlocale(LC_ALL, "Turkish");

	int atis, puan, sonuc;


	srand(time(NULL)); //Rastgele Sayı Üretimi


	atis = zaratma();


	if (atis == 7 || atis == 11)
	{
		sonuc = 1;
		printf("OYUNCU KAZANDI\n");
	}

	else if (atis == 2 || atis == 3 || atis == 12)
	{
		sonuc = 2;
		printf("OYUNCU KAYBETTİ\n");
	}


	else     //else if (atis == 4 || atis == 5 || atis == 6 || atis == 8 || atis == 9 || atis == 10)
	{
		sonuc = 3;

	}

	while (sonuc == 3)
	{

		puan = zaratma();

		if (puan == atis)

		{
			sonuc = 1;
			printf("OYUNCU KAZANDI\n");
		}

		else if (puan == 7)

		{
			sonuc = 2;
			printf("OYUNCU KAYBETTİ\n");
		}

	}
	return 0;

}
