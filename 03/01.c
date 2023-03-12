/* Dizideki Elemanların Ortalaması


*/

#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 100



int main()

{
	setlocale(LC_ALL, "Turkish");

	float dizi[MAX_SIZE];
	int i, N;
	float toplam=0;

	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		printf("%.2d. Elemanı Giriniz: ", i + 1);
		scanf("%f", &dizi[i]);

		toplam += dizi[i];
	}

	printf("\nGirilen Elemanların Ortalaması= %f\n", toplam / N);
	
	return 0;

}
