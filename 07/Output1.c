#include <stdio.h>  


void main()
{

	int* m, ** p, *** k, myArray[5] = { 2,4,6,8,10 };

	m = &myArray[2]; //m artık MyArray[2] adresini tutuyor.

	p = &m;

	k = &p;

	printf("%p\n", **k); // MyArray[2] adresini verir.

	printf("%d\n", *(**(k)+2)); // MyArray[2] deydi 8 bayt giderse MyArray[4] dizisinin değerini verir.

	m = myArray; //m=&myArray[0] m dizinin ilk elemanın adresidir.

	printf("%d\n", *(*(p)+1)); //Output=4 

	**(p) += 7.26;

	m += 3; // m artık dizi[3] de başlıyor.

	printf("%d\n", *(*(p)-3)); //Output=9

	printf("%p\n", **k); // MyArray[3] adresini verir.

}
