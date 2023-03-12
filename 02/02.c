/* En Büyük ve En Küçük Sayıyı Bulma

//While Kullanımı

Kullanıcı klavyeden -1 girene kadar girilmiş olan sayıların en büyüğü ile en küçüğünü ekrana yazdıran program*/

#include <stdio.h>
#include <locale.h>  

int main()
{
	setlocale(LC_ALL, "Turkish");

	float sayi, max, min;
	printf("Sayı Giriniz: ");
	scanf("%f", &sayi);

	min = sayi;
	max = sayi;

	while (sayi != -1)
	{

		if (sayi > max)
			max = sayi;

		if (sayi < min)
			min = sayi;

		printf("Sayı Giriniz: ");
		scanf("%f", &sayi);

	}
	printf("En Büyük Sayı: %.2f\n", max);
	printf("En Küçük Sayı: %.2f", min);

}
