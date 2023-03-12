/* Matematiksel İşlemler */

#include <stdio.h>    
#include <stdlib.h>
#include <locale.h>  

/*  ATAMA OPERATÖRLERİ
x += y   >  x = x+y
x -= y   >  x = x-y
x *= y   >  x = x*y
x /= y   >  x = x/y
x %= y   >  x = x%y

*/

/*  Arttırma ve Eksiltme Operatörleri

++x  > x = x+1     önce arttırılır, sonra atanır
--x  > x = x-1     önce eksiltilir, sonra atanır

x++  >             önce atanır, sonra arttırılır
x--  >             önce atanır, sonra azaltılır


*/


int main()
{

	setlocale(LC_ALL, "Turkish");

	int x, y;



	printf("Lütfen bir tam sayı giriniz: \n");
	scanf("%d", &x);


	y = x++;  //atanır sonra arttırılır.

	printf("x= %d, y= %d\n", x, y);



	printf("Lütfen bir tam sayı giriniz: \n");
	scanf("%d", &x);

	y = ++x; //önce arttırılır, sonra atanır

	printf("x= %d, y= %d\n", x, y);



	printf("Lütfen bir tam sayı giriniz: \n");
	scanf("%d", &x);

	x += 5;

	printf("x= %d", x);


	return 0;

}
