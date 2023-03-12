/*
Dinamik olarak ayrılan bir hafıza bölgesine 1 ile 100 arasında rastgele oluşturulan
10 tane tam sayıyı yazan program

//Dinamik bellek ayırma yöntemi kullanımı
*/


#include <locale.h>  
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>



int main()
{
	setlocale(LC_ALL, "Turkish");

	srand(time(NULL)); //Rastgele Sayı Üretimi

	int* p;

	int i;

	p = malloc(10 * sizeof(int));

	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1 + (rand() % 100);

		printf("%2d. Eleman= %d\n", i + 1, *(p + i));

	}

}