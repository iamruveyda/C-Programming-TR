/*
Metni Tersten Yazdırma

//Pointer Kullanımı

*/

#include <stdio.h>  
#include <locale.h>  
#define SIZE 20

int main()
{
	setlocale(LC_ALL, "Turkish");


	char metin[SIZE];
	char tersi[SIZE];

	char* ptr_1 = metin;
	char* ptr_2 = tersi;

	int i = 0;

	printf("Metin giriniz: ");
	gets(metin);    // alternatif: scanf("%s", metin);


	while (*ptr_1)
	{

		ptr_1++;
		i++;

	}

	while (i >= 0)
	{
		ptr_1--;
		*ptr_2 = *ptr_1;
		ptr_2++;
		--i;
	}


	*ptr_1 = '\0';

	printf("Metnin Tersi: %s", tersi);

	return 0;

}
