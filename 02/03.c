/* Girilen Değerlerin Ortalamasını Hesaplama

//For Kullanımı

SIZE (#define SIZE İstediğin Sayı) elemanlı bir dizideki değerleri toplayıp ortalamasını yazan program. */

#include <stdio.h>
#include <locale.h>  
#define SIZE 3

int main()
{
	setlocale(LC_ALL, "Turkish");

	int i;
	float a[SIZE], ort, toplam;
	toplam = 0;

	for (i = 0; i < SIZE; i++)

	{
		printf("Sayı Giriniz: ");
		scanf("%f", &a[i]);
		toplam = toplam + a[i];
	}


	ort = toplam / SIZE;
	printf("Ortalama=%.2f", ort);

	return 0;
}
