/*
N adet Fibonacci Sayısı Yazdıran Program
// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  


int fibonacci(int x)
{
	if (x == 0 || x == 1)
	{
		return x;
	}
	else
		return fibonacci(x - 1) + fibonacci(x - 2);
}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi, i;

	printf("Kaç tane Fibonacci sayısı yazılsın?: ");
	scanf("%d", &sayi);

	for (i = 1; i <= sayi; i++)
	{
		printf("%d\n", fibonacci(i));
	}

	return 0;

}

/*


i=1 fibonacci(1)

i=2 fibonacci(1)+fibonacci(0)

i=3 fibonacci(2)+fibonacci(1)


*/
