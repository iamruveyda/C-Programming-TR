/*
Diziyi Artan Şekilde Yazma

//Pointer Kullanımı

*/


#include <stdio.h>
#include <locale.h>  
#define SIZE 100

void main()
{
	setlocale(LC_ALL, "Turkish");

	int N;

	int dizi[SIZE];

	int i, j, k;

	int* ptr;


	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);

	printf("\nDizideki %d Elemanın Değerlerini Giriniz \n", N);

	ptr = &dizi[0]; // ptr, dizi[0] dizisinin adresini saklar

	for (i = 0; i < N; i++)
	{
		printf("\n%d. Elemanı Giriniz: ", i + 1);

		scanf("%d", ptr + i);

		/*
		Dizi, işaretçi değişkeni dizinin temel adresini gösteren işaretçiler yardımıyla getirilebilir.
		Bu nedenle, işaretçileri kullanarak diziyi sıralamak için,
		dizinin öğelerine (pointer + indeks) biçimini kullanarak erişmemiz gerekir.

		*/
	}

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (*(ptr + i) > * (ptr + j))
			{
				k = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = k;
			}

		}
	}

	printf("\nKüçükten Büyüğe Sıralanmış Hali\n");


	for (i = 0; i < N; i++)
	{
		printf("\n%d. Eleman= %d \n", i + 1, *(ptr + i));

	}

}
