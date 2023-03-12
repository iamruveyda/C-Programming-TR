/* Kelimenin İlk Harfini Büyük Yapma

//String (Karakter Tutan Diziler)


Klavyeden girilen metnin içerisindeki kelimelerin sadece ilk harfini büyük yazan C programı

Örnek= merhaba dünya -> Merhaba Dünya
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[256];

	int i=0;

	int durum=1;
		
	printf("Metin Giriniz:");
	gets(metin);
		
	while (metin[i] != 0)
	{
		if (durum)
		{
			if (metin[i] >= 'a' && metin[i] <= 'z')
				
				metin[i] -= 32;
				durum = 0;
		}
		
		else
		{
			if (metin[i] >= 'A' && metin[i] <= 'Z')
				
				metin[i] += 32;
		}
			
		if (metin[i] == ' ' || metin[i] == '.')
			
			durum = 1;
			
		i++;
	}
		
	printf("%s", metin);
	
	return 0;

}
