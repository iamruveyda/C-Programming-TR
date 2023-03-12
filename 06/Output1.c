#include<stdio.h> 

void fun(int x)
{
    if (x > 0)
    {
        fun(--x);
        printf("%d\t", x);
        fun(--x);
    }
}

int main()
{
    int a = 4;
    fun(a);
    getchar();
    return 0;
}




/*

P(): Yazdır

fun(4) = fun(3) + P(3) + fun(2) <<< Buna Göre takip edilecek. 


fun(3) = fun(2) + P(2) + fun(1)
fun(2) = fun(1) + P(1) + fun(0)
fun(1) = fun(0) + P(0) + fun(-1)

Output: 0 1 2 0 3 0 1

fun(3) = 0 1 2 0
fun(2) = 0 1


*/
