/* Büyük/Küçük Harf Sayısını Bulma

//String (Karakter Tutan Diziler)


Klavyeden girilen metin içerisindeki küçük ve büyük harf sayısını bulan C programı


*/

#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[100];

	int sayac = 0, kucuk_harf = 0, buyuk_harf= 0;

	printf("Metin giriniz: ");
	gets(metin);

	while (metin[sayac] != '\0')
	{
		char karakter = metin[sayac];
		
		if (karakter >= 'a' && karakter <= 'z')
			
			kucuk_harf++;
		
		else if (karakter >= 'A' && karakter <= 'Z')
			
			buyuk_harf++;
		
		sayac++;
	}

	printf("\nMetnin içerisinde %d küçük ve %d büyük harf bulunuyor.\n", kucuk_harf, buyuk_harf);

}
