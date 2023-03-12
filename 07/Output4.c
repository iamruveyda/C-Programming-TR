#include <stdio.h>


int x=0;

void main()
{
	int *ptr=&x; 
	/*
	aynı anlamda
	int *ptr;
	
	ptr=&x;
	*/
	
	printf("%p\n", ptr);
	
	x++;
	
	printf("%p\n", ptr);
}


/*Aynı Adres değerini verir.*/


