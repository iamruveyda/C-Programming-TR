/*Girilen Sayıyı Tersten Yazan Program

// While Kullanımı
*/

#include <stdio.h>
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "Turkish");

	int sayi, ters = 0, basamak;

	printf("Tam Sayı Giriniz:  ");
	scanf("%d", &sayi);

	while (sayi != 0)
	{

		basamak = sayi % 10;
		ters = ters * 10 + basamak;
		sayi /= 10;

	}

	printf("Sayının Tersi:  %d", ters);
	return 0;
}
