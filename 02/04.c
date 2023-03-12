/*  Bir Sayı Diğer Sayının Katı Mıdır? */

#include <stdio.h>
#include <locale.h>

int main()

{

	setlocale(LC_ALL, "Turkish");

	int buyukSayi, kucukSayi;

	printf("Lutfen once büyük sayıyı sonra küçük sayıyı giriniz...\n");

	scanf("%d %d", &buyukSayi, &kucukSayi);


	if (buyukSayi % kucukSayi == 0)
	{

		printf("Katıdır\n");

	}

	else
	{

		printf("Katı Değildir\n");

	}

	return 0;
}
