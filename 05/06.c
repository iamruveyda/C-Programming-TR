/* Kaç Tane Karakter Var Hesaplama

//String (Karakter Tutan Diziler)

Klavyeden girilen bir string içerisinde kelimelerden kaç tane "e" (İstediğini Yapabilirsin) karakteri geçtigini bulan c programı
*/


#include <stdio.h>
#include <locale.h> 

int main()
{
	setlocale(LC_ALL, "Turkish");

	char karakter[256];
	printf("Karakteri giriniz: ");
	gets(karakter);

	int i = 0;
	int sayac = 0;

	while (karakter[i] != '\0')
	{
		if (karakter[i] == 'e') //İstediğin karakteri yazabilirsin.
			sayac++;
		i++;
	}
	printf("\n%s ifadesinde %d tane karakter var", karakter, sayac);

	return 0;

}
