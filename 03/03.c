/* Dizi İçerisinde Sayı Arama ve o Sayıdan kaç tane olduğunu Yazan Program

Klavyeden girilen SIZE elemanlı dizi içerisinde klavyeden girilen sayının frekansını bulan C programı

*/

#include <stdio.h>
#include <locale.h>
#define SIZE 100

int main()
{
	setlocale(LC_ALL, "Turkish");

	int dizi[SIZE],N;
	int x;
	int frekans = 0;
	int i, toplam = 0;
	
	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);

	printf("\n");

	printf("Aranacak Sayı: ");
	scanf("%d", &x);

	printf("\n");


	for (i = 0; i < N; i++)
	{
		printf("%.2d. Elemanı Giriniz: ", i + 1);
		scanf("%d", &dizi[i]);
		if (dizi[i] == x)
			frekans++;
	}


	printf("\nDizi içerisinde %d adet, %d sayısı vardır.\n", frekans, x);
	
	return 0;
}
