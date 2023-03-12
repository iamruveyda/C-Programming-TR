/* Metin İçerisinde Karakter Değiştirme

//String (Karakter Tutan Diziler)

Klavyeden girilen bir cümle içerisinde yer alan tüm ‘a’ karakterlerini ‘A’ ile değiştiren
ve değiştirilmiş metin ile kaç karakter değiştirildiğini ekrana yazdıran programı C dili ile kodlayınız. */

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	char cumle[256];
	printf("Bir Cümle Giriniz: ");
	gets(cumle);

	int i = 0;
	int sayac = 0;

	while (cumle[i] != '\0')
	{
		if (cumle[i] == 'a') // if(cumle[i]==97)  
		{
			cumle[i] = 'A'; //cumle[i] = 65;
			sayac++;
		}
		i++;

	}
	printf("\nDeğiştirilen Cümle = %s\t %d tane a A'ye cevrildi\n", cumle, sayac);

	return 0;
}
