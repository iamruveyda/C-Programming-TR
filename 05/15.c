/* Büyük Ünlü Uyumu

//String (Karakter Tutan Diziler)

*/

#include <stdio.h>
#include <locale.h>



int uzunlukbulma(char metin[])
{
	int i = 0;

	while (metin[i] != '\0')  //Null görene kadar dönmeye devam eder.
	{
		i++;
	}
	return i;

}

int main()
{
	setlocale(LC_ALL, "Turkish");

	char metin[100];

	int kalin = 0, ince = 0;

	printf("Metin Giriniz: ");
	gets(metin);

	int uzunluk = uzunlukbulma(metin);

	for (int i = 0; i < uzunluk; i++)
	{
		
		if (metin[i] == 'a' || metin[i] == 'ı' || metin[i] == 'o' || metin[i] == 'u')
			kalin++;

		if (metin[i] == 'e' || metin[i] == 'i' || metin[i] == 'ö' || metin[i] == 'ü')
			ince++;

	}

	if (kalin != 0 && ince != 0)
		printf("\nBüyük Ünlü Uyumuna Uymaz\n");

	else
		printf("\nBüyük Ünlü Uyumuna Uyar\n");

	return 0;

}
