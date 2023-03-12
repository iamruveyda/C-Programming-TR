#include <stdio.h> 

void fun(int n)
{
	if (n > 0)
	{
		fun(n - 1);
		printf("%d ", n);
		fun(n - 1);
	}
}

int main()
{
	fun(4);
	return 0;
}

/*
P(): Yazdır

f(4) = f(3) P(4) f(3)    <<< Buna Göre takip edilecek. 

f(3) = f(2) P(3) f(2)
f(2) = f(1) P(2) f(1)
f(1) = f(0) P(1) f(0)



f(3) = 1 2 1 3 1 2 1
P(4) = 4



Output= 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1

*/
