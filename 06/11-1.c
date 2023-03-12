/*
Dizideki Elemanlar Toplamı


C program to find sum of array elements using recursion

// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  
#define MAX_SIZE 100

int topla(int dizi[], int x, int y)  //topla(dizi, 0, N); x=0, y=N <<< Başlangıç
{
	if (x >= y)
		return 0;
	else
		return (dizi[x] + topla(dizi, x + 1, y));
}



int main()
{
	setlocale(LC_ALL, "Turkish");
	
	int dizi[MAX_SIZE];
	int i,N;
	int sonuc;
	
	printf("Dizinin Boyutunu Giriniz: ");
	scanf("%d", &N);


	for (i = 0; i < N; i++)
	{
		printf("%d. Elemanı Giriniz: ", i + 1);
		scanf("%d", &dizi[i]);

	}

	sonuc = topla(dizi, 0, N);

	printf("Dizideki Elemanların Toplamı: %d", sonuc);

	return 0;

}
