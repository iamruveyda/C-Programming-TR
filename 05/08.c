/*  Metnin Kelime Sayısını Bulan Program

//String (Karakter Tutan Diziler)
//While ile

Klavyeden girilen metnin kelime sayısını bulan C programı
*/

#include <stdio.h>
#include <locale.h> 

int main()
{
	setlocale(LC_ALL, "Turkish");

	char ifade[256];
	printf("ifadeyi giriniz: ");
	gets(ifade);

	int i = 0;
	int sayac = 0;

	while (ifade[i] == 32)
		i++;

	while (1)
	{
		if ((ifade[i] == 32) && (ifade[i - 1] != 32))
			sayac++;
		else if ((ifade[i] == '\0') && (ifade[i - 1] != 32))
		{

			sayac++;
			break;
		}
		i++;
	}

	printf("%s ifadesinde %d tane kelime var.\n", ifade, sayac);


	return 0;
}
