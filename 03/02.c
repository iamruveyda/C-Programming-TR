/* Dizinin En Büyük ve En Küçük Elemanını Bulma */

#include <stdio.h>
#include <locale.h>
#define SIZE 100 


int main()
{
	setlocale(LC_ALL, "Turkish");

	int dizi[SIZE];
	int i,N;
	int max=0, min=0;

	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);

	printf("\n");

	for (i = 0; i < N; i++)
	{
		printf("%.2d. Elemanı Giriniz: ", i + 1);
		scanf("%d", &dizi[i]);
	}

	max = dizi[0];
	min = dizi[0];

	for (i = 1; i < N; i++)
	{
		if (dizi[i] > max)
		{
			max = dizi[i];
		}
		else if (dizi[i] < min)
		{
			min = dizi[i];
		}
	}

	printf("\nEn Büyük Sayı = %d\n", max);
	printf("\nEn Küçük Sayı = %d\n", min);

	return 0;
}
