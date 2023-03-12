/*
 Dizinin En Büyük Elemanını Bulma 

// Dizi ve İşlevi


C program to find maximum  elements in array using recursion

// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  
#define MAX_SIZE 100



int enbuyuksayi(int dizi[], int ilk_elemani, int son_elemani)
{
	int max;

	if (ilk_elemani == son_elemani)
		return dizi[ilk_elemani];

	else
	{
		max = enbuyuksayi(dizi, ilk_elemani + 1, son_elemani);

		if (dizi[ilk_elemani] >= max)

			return dizi[ilk_elemani];
		else
			return max;
	}


}




int main()
{
	setlocale(LC_ALL, "Turkish");
	
	int dizi[MAX_SIZE];
	int i, N;
	

	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);


	for (i = 0; i < N; i++)
	{
		printf("%d. Elemanı Giriniz: ", i + 1);
		scanf("%d", &dizi[i]);

	}

	printf("Dizinin En Büyük Elemanı = %d\n", enbuyuksayi(dizi, 0, N));


	return 0;

}