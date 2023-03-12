/* Girilen Sayıyı Tersten Yazan Program

//Fonksiyon Kullanımı

*/

#include <stdio.h>
#include <locale.h>

int tersinialma(int sayi)
{
	int ters = 0, basamak;

	while (sayi != 0)
	{

		basamak = sayi % 10;
		ters = ters * 10 + basamak;
		sayi /= 10;

	}

	return ters;
}

int main()
{

	setlocale(LC_ALL, "Turkish");

	int sayi;

	printf("Tam Sayı Giriniz: ");
	scanf("%d", &sayi);

	printf("\nSayının Tersi: %d\n", tersinialma(sayi));

	return 0;
}
