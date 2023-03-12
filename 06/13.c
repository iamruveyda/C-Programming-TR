/*

Decimal Sayıyı Binary Sayıya Çevirme


Verilen bir sayısının decimal’den binary’e dönüşümünü rekürsif fonksiyonla hesaplayan programı yazınız?
Write a C program for decimal to binary conversion with the recursive function?

// Özyinelemeli Fonksiyon (Recursive Function)
*/


#include <stdio.h>  
#include <locale.h>  


int binary(int sayi)
{
	if (sayi == 0)
	{
		return 0;
	}


	binary(sayi / 2);
	printf("%d", sayi % 2);


}


int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;

	printf("Onluk Tabanında Olan Bir Sayı Giriniz: ");
	scanf("%d", &sayi);

	binary(sayi);

	return 0;

}

/*


•	Onlu (Desimal, 10 Tabanlı, Decimal) Sayı Sistemi
Günlük hayatta kullandığımız sayı sistemi 10 tabanına göredir. Yani bu sistemde 0-1-2-3-4-5-6-7-8-9 sayıları mevcuttur. Kullanılan bu sayı sistemine de Onlu Sayı Sistemi veya Desimal Sistem denilmektedir.

•	İkili (Binary, 2 Tabanlı) Sayı Sistemi
İkili sayı sisteminde sadece 1 ve 0′ lar bulunur. Bu sayı sistemi 2 tabanında olduğu için İkili Sayı Sistemi veya Binary Sistem olarak isimlendirilmektedir.


//Desimal sayı binary sayıya çevrilirken binary sayının tabanı olan 2'ye bölünür.
Kalanlar bir kenara yazılarak tersten ikilik sayı olarak yazılır.



*/




/*
Örnek 45 sayısı girildiğinde

	printf("Modu Alınacak Sayı= %d\n", sayi);

45,22,11,5,2,1 sayılarını alt alta yazıyor.


	binary(sayi / 2); Sayi==0 Olana kadar bulunan sayıları 2 ye bölmeye devam ediyor. 

	printf("%d", sayi % 2); //Bulunan sayıların ayrı ayrı modları alınıp yanyana yazılınca sonuç çıkıyor.

*/

