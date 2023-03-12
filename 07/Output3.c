#include <stdio.h>
#include <locale.h> 


void main()
{
	double* m, ** k, myArray[5] = { 1.0,2.0,3.0,4.0,5.0 };

	m = myArray; //m=&myArray[0] m dizinin ilk elemanın adresidir.

	printf("%.1f\n", *(m + 1)); // Output=2.0

	*(m + 3) += 3.86; // myArray[3]= *(m+3) =7.86

	m += 2; // m artık dizi[2] de başlıyor.

	printf("%.1f\n", *(m + 1)); //Output=7.9

	m = &myArray[3]; //m artık MyArray[3] adresini tutuyor.

	k = &m;  

	printf("%.1f\n", *(*(k)-1)); //myArray[2] değerini verir.

	printf("%p\n", *k); //myArray[3]'ün adresini verir.

	m = m - 1;

	printf("%p", m); //myArray[2] adresini verir.
}
