/* Büyük/Küçük Harf Değiştirme (1)

Büyük Harfleri Küçük, Küçük Harfleri Büyük Harf Yapan Program

//String (Karakter Tutan Diziler)
//While ile yazılan program

Klavyeden girilen bir ifadede yer alan büyük harfleri küçük harflere,
küçük harfleri büyük harflere hazır bir fonksiyon kullanmadan çeviren ve sonucu
ekrana yazdıran C programını yazınız.

(Örneğin İfade “BuGün hAVa güzel” ise Sonuç “bUgÜN HavA GÜZEL” olmalıdır).

 >ASCII KOD<
 65  = A
 90  = Z
 97  = a
 122 = z

 */

#include <stdio.h>
#include <locale.h> 


int main()
{
	setlocale(LC_ALL, "Turkish");

	char ifade[256];
	
	printf("Cümleyi Giriniz: ");
	gets(ifade);

	int i = 0;

	int fark = 'a' - 'A';

	while (ifade[i] != '\0') // '\0' simgesi NULL(bos) karakter
	{
		if (ifade[i] >= 'A' && ifade[i] <= 'Z')
		{
			ifade[i] += fark;
		}
		else if (ifade[i] >= 'a' && ifade[i] <= 'z')
		{
			ifade[i] -= fark;

		}
		
		printf("%c", ifade[i]); //alternatif: putchar(ifade[i])
		
		i++;
	}

	return 0;
}
