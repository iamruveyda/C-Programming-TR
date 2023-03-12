/*

Metni Tersten Yazdırma Programı


// Özyinelemeli Fonksiyon (Recursive Function)

*/


#include <stdio.h>  
#include <locale.h>  



int ters() 

{
	char metin; 
	scanf("%c", &metin);  

	if (metin != '\n')
	{
	

		ters();  

		printf("%c", metin);

	}
}


int main()
{
	setlocale(LC_ALL, "Turkish");


	printf("Lütfen Metninizi Giriniz: \n");

	ters();

	
	return 0;

}

/*
int ters() fonksiyonu kullanıcı tarafından girilen ilk harfi metin değişkeninde saklar.

Değişken '\ n' dışında bir karakterse, ters () işlevi yeniden çağrılır.

ters () ikinci kez çağrıldığında, kullanıcı tarafından girilen ikinci harf tekrar metin 'e kaydedilir.
Ancak, ikinci fonksiyondaki metin değişkeni birincisiyle aynı değildir. Her ikisi de bellekte farklı yer tutarlar.


'\ n' girdiğinde, en son işlevi ters () işlevi  en son karakteri basar printf("%c", metin) nedeniyle
ve ikinci ters () işlevine geri döner.


Yine, ikinci son ters () işlevi, ikinci son karakteri basar ve 
üçüncü son ters () işlevine geri döner.

Bu süreç devam ediyor ve son çıktı ters metin olacak.

KAYNAK: https://www.programiz.com/c-programming/examples/reverse-sentence-recursion

*/
