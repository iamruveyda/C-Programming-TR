/*
Dizideki Elemanları Tersten Yazma (Pointer)
Verilen dizi içerisinde yer alan sayıları pointer kullanarak ters şekilde sıralayan programı C dilinde yazınız.
*/


#include <stdio.h>  
#include <locale.h>  
#define SIZE 100

void main ()
{
	setlocale(LC_ALL, "Turkish");

	int dizi[SIZE];
	int i, N;
	int* ptr;



	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);

	printf("\nDizideki %d Elemanın Değerlerini Giriniz \n",N);

	ptr = &dizi[0]; // ptr, dizi[0] dizisinin adresini saklar


	for (i = 1; i <= N; i++)
	{
		printf("\n%d. Elemanı Giriniz: ", i);

		scanf("%d", ptr); //değerin adresini alır.

		ptr++; //Adresi artırır. Adres 4 byte artar. 

	}



	printf("\n--------------------------\n");

	printf("\nDizideki Elemanların Tersi\n");

	ptr = &dizi[N - 1];

	for (i = N; i > 0; i--)
	{
		printf("\n%d. Eleman= %d \n", i, *ptr); //*ptr dizideki değerleri verir.

		ptr--; //Adresi azaltır. Adres 4 byte azalır.
	}

}
