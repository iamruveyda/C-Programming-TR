/*Metnin Karakter Uzunluğunu Bulma

//String (Karakter Tutan Diziler)

Klavyeden girilen metnin karakter uzunluğu bulan C programı (Boşluklarda sayılır)
*/

#include <stdio.h>
#include <locale.h> 

void main() //Void yazıldığında fonksiyon geriye bir deger gondermez.
		//int main() yazmak istiyorsan sonuna return eklemen gerekir.
{

	setlocale(LC_ALL, "Turkish");

	char metin[256];
	int sayac = 0;
	printf("Metni Giriniz: ");
	gets(metin);

	while (metin[sayac] != '\0')
		sayac++;
	printf("Girilen metin %d karakterden oluşur.", sayac);

}
