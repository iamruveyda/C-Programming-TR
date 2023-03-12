#include <stdio.h>  


void main()
{

	double* m, ** k, myArray[5] = { 2.0,4.0,6.0,8.0,10.0 };


	m = &myArray[1];

	k = &m;

	
	printf("%p\n", *k); //myArray[1] adresini verir.

	printf("%.1f\n", *(*(k)+2)); //myArray[3] değerini verir. Output=8.0

	m = myArray;

	printf("%.1f\n", *(m + 1));  //Output=4.0

	*(m + 3) += 7.26;

	m += 2;

	printf("%.1f\n", *(m + 1)); //Output=15.30

	m -= 2;

	printf("%p\n", m); // myArray[0] adresini verir.
}
