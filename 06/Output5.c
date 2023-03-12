#include <stdio.h>
#include <locale.h> //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 


struct complex {

	int real;
	int im;

};

struct complex sum(struct complex s1, struct complex s2) {

	struct complex result;

	result.real = s1.real + s2.real;
	result.im = s1.im + s2.im;

	return result;
}


main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter yazdırmamızı sağlayan fonksiyon

	struct complex a1, a2, a3;

	a1.real = 5;
	a1.im = 3;

	a2.real = 15;
	a2.im = 30;

	a3 = sum(a1, a2);

	printf("Sonuç: %d+i%d\n", a3.real, a3.im);

}
