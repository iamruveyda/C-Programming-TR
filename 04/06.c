/*

Diziyi Artan ve Azalan Şekilde Yazma

C Fonksiyonu kullanarak bir diziyi artan ve azalan düzende Sıralama Programı


C Program to Sort an array in ascending and descending order using function
Code for Sorting of array elements using a function in C Programming

//Fonksiyon Kullanımı

*/


#include <stdio.h>  
#include <locale.h>  
#define MAX_SIZE 100


int diziyisirala(int dizi[], int N)
{
	int i, j, k;

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (dizi[i] > dizi[j])
			{
				k = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = k;
			}

		}
	}

}

int diziyisirala2(int dizi[], int N)
{
	int i, j, k;

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (dizi[i] < dizi[j])
			{
				k = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = k;
			}

		}
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


	printf("\n\n");

	printf("Girilen Dizi\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", dizi[i]);
	}



	printf("\n\n");


	diziyisirala(dizi, N);

	printf("Küçükten Büyüğe Sıralanmış Hali:\n");

	for (i = 0; i < N; i++)
	{
		printf("%d ", dizi[i]);
	}

	printf("\n\n");


	diziyisirala2(dizi, N);

	printf("Büyükten Küçüğe Sıralanmış Hali:\n");

	for (i = 0; i < N; i++)
	{
		printf("%d ", dizi[i]);
	}

	printf("\n\n");


	return 0;
}
