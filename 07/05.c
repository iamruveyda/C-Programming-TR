/*
Dizinin En Büyük Elemanını Bulma

//Dinamik bellek ayırma yöntemi kullanımı

*/


#include <stdio.h>  
#include <locale.h>  
#include <stdlib.h>



int main()
{
	setlocale(LC_ALL, "Turkish");


	int i, n;

	int* ptr;


	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &n);

	ptr = (int*)calloc(n,sizeof(int));

	if (ptr == NULL)
	{
		printf("Yeterli Hafıza Alanı Yok!");
	
	}


	for (i = 0; i < n; i++)
	{
		printf("%d. Elemanı Giriniz: ", i + 1);
		scanf("%d", ptr + i);

	}

	for (i = 0; i < n; i++)
	{
		if (*ptr < *(ptr + i))
		{

			*ptr = *(ptr + i);

		}

	}

	printf("Dizinin En Büyük Elemanı = %d\n", *ptr);

	return 0;

}
