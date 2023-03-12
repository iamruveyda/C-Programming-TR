/* Dizinin En Büyük ve En Küçük Elemanını Bulma

// Dizi ve İşlevi
// Fonksiyon ile

*/

#include <stdio.h>
#include <locale.h> 
#define SIZE 100

void fonksiyon(int dizi[], int N)
{

	int min = 0, max = 0;
	int i;

	max = dizi[0];
	min = dizi[0];

	for (i = 1; i < N; i++)
	{
		if (dizi[i] > max)
		{
			max = dizi[i];
		}
		if (dizi[i] < min)
		{
			min = dizi[i];
		}
	}

	printf("\nEn Büyük Sayı = %d\n", max);
	printf("\nEn Küçük Sayı = %d\n", min);
}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int dizi[SIZE], N;
	int i;

	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);

	printf("\n");

	for (i = 0; i < N; i++)
	{
		printf("%.2d. Elemanı Giriniz: ", i + 1);
		scanf("%d", &dizi[i]);
	}

	fonksiyon(dizi, N);
	return 0;
}
