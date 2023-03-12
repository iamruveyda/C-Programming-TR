/* Kelimelerin Baş Harflerini Yazdırma

//String (Karakter Tutan Diziler)
//While ile

Klavyeden girilen cümlede yer alan kelimelerin baş harflerini ekrana yazdıran programı C dilinde yazınız.

 >ASCII KOD< 
 32 = Space

 */

#include <stdio.h>
#include <locale.h>  
#define SIZE 256

int main()
{
	setlocale(LC_ALL, "Turkish");

	char cumle[SIZE];

	printf("Cümlenizi Giriniz: ");
	gets(cumle);

	int i = 1;
	int sayac = 0;

	printf("%c", cumle[0]); // alternatif: putchar(cumle[0])

	while (cumle[i] != '\0') // '\0' simgesi NULL(bos) karakter
	{
		if ((cumle[i] == 32) && (cumle[i + 1] != 32))
		{
			putchar(cumle[i + 1]);  // alternatif: printf("%c", cumle[i + 1]);
		}

		i++;
	}

	return 0;
}
