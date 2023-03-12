#include <stdio.h>
#include <locale.h> //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 


void calculate(int a) {

	printf("%3d", a);

	if (a < 9)
		calculate(a + 1);
	
	printf("%3d", a);
}


void calculate_2(int a) {

	printf("%3d", a);

	if (a > 9)
		calculate_2(a - 1);

	printf("%3d", a);
}


main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter yazdırmamızı sağlayan fonksiyon

	printf("\ncalculate(1)   : ");

	calculate(1);

	printf("\n\ncalculate_2(20): ");

	calculate_2(20);
}
