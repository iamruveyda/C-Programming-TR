/* Büyük/Küçük Harf Değiştirme (2)

Büyük Harfleri Küçük, Küçük Harfleri Büyük Harf Yapan Program


// String (Karakter Tutan Diziler)
// For ile yazılan program

Klavyeden girilen bir ifadede yer alan büyük harfleri küçük harflere,
küçük harfleri büyük harflere hazır bir fonksiyon kullanmadan çeviren ve sonucu
ekrana yazdıran C programını yazınız. (Örneğin İfade “BuGün hAVa güzel” ise Sonuç “bUgÜN HavA GÜZEL” olmalıdır).
*/

#include <stdio.h>
#include <locale.h> 

int main()
{
	setlocale(LC_ALL, "Turkish");
	char ifade[256];
	printf("ifadeyi giriniz: ");
	gets(ifade);

	int i;

	//While ile yapmak daha doğru olur.
	for (i = 0; i < 256; i++)
	{
		if ((ifade[i] >= 65) && (ifade[i] <= 90)) //harf buyukse
			ifade[i] = ifade[i] + 32;
		else if ((ifade[i] >= 97) && (ifade[i] <= 122)) //harf buyukse
			ifade[i] = ifade[i] - 32;
		else if (ifade[i] == '\0') //ifade bittiyse
			break;
	}

	printf("\n");

	puts(ifade);

	return 0;
}
