/*

Boy ve kilo bilgisini alarak vücut kitle indeksini hesaplayan kitleIndeks isimli bir fonksiyon yazınız. 
Bu fonksiyon aşağıda verilen tabloya göre değer döndürmektedir. 

Yazdığınız fonksiyonu main fonksiyonunda çağırarak kullanın ve bir program yazınız. Programın örnek çalışması şekilde verildiği gibi olmalıdır. 
Vücut kitle indeksi hesabı aşağıda verilmiştir.


Write a function named bodyIndex that computes body mass index by taking height and weight information. Write a program that calls the function in the main. 
The sample output of the program should be as it is given.


*/


#include <stdio.h>  
#include <locale.h>  


int kitleindeks(float boy, float kilo)
{

	float indeks;

	indeks = kilo / (boy * boy);

	if (indeks <= 18)
	{
		return 1;
	}

	else if (indeks <= 25)
	{
		
		return 2;
	}

	else if (indeks <= 30)
	{
		
		return 3;
	}

	else
	{
		return 4;
	}
}


int main()
{

	setlocale(LC_ALL, "Turkish");

	float boy=0, kilo=0;

	printf("Boyunuzu ve Kilonuzu Giriniz: "); //boyu metre cinsinden kiloyu da kg cinsinden giriniz.
	scanf("%f %f", &boy, &kilo);


	int sonuc = kitleindeks(boy, kilo);

	if(sonuc==1)
		printf("ZAYIF");

	else if(sonuc==2)
		printf("NORMAL");

	else if(sonuc==3)
		printf("KİLOLU");

	else
		printf("OBEZ");		

}
