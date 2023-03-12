/*

Girilen Metnin(String) Palindromik Olup Olmadığını Bulmak

(Palindrom, tersten okunuşu da aynı olan cümle, sözcük ve sayılara denilmektedir.)

// Özyinelemeli Fonksiyon (Recursive Function)
*/

#include <stdio.h>  
#include <locale.h>  
#define SIZE 100



int uzunlukbulma(char metin[])
{

	int i = 0; // karakter sayısını alacak


	while (1) // Sonsuz Döngü
	{
		if (metin[i] == '\0') // '\0' simgesi NULL(bos) karakter
		{
			break; //NULL gelince sonsuz döngüden çıkıyoruz
		}

		i++;

	}

	return i; //Metnin uzunluğunu verir.


	/* Alternatif

	while(metin[i] != '\0')  //Null görene kadar dönmeye devam eder.
		{

			i++;
		}

			return i;

	*/


}



int palindrome(char metin[], int uzunluk)
{
	if (uzunluk <= 0)
	{
		return 1;   //Uzunluk eğer sıfıra kadar gelebildiyse 1' döndürüyoruz.
	}

	else if (metin[0] == metin[uzunluk - 1])
	{
		return palindrome(metin + 1, uzunluk - 2);
	}

	else
	{
		return 0; //Yukarıdaki if ler doğru olmazsa sıfır döndürüyoruz.

	}

}



int main()
{
	setlocale(LC_ALL, "Turkish");


	char metin[SIZE];

	printf("Metin giriniz: ");
	gets(metin);    // alternatif: scanf("%s", metin);


	int uzunluk = uzunlukbulma(metin);

	/*
	Tersini Yazdırma

	int sayac = 0;


	printf("\nMetnin Tersi: ");

	for (sayac = uzunluk - 1; sayac >= 0; sayac--)

		putchar(metin[sayac]); // printf("%c", metin[sayac]) //Belirtilen karakteri ekrana yazar.

	*/


	int sonuc = palindrome(metin, uzunluk);

	if (sonuc == 1)  //Eğer sonuç 1 ise palindromdur.
	{
		printf("\n '%s' ifadesi palindromdur\n", metin);
	}

	else if (sonuc == 0) //Eğer sonuç 2 ise palindrom değildir.
	{
		printf("\n '%s' ifadesi polindrom değildir.\n", metin);
	}


}

/*

Örnek:KAZAK kelimesi

metin[0]: K
metin[1]: A
metin[2]: Z
metin[3]: A
metin[4]: K


****	uzunlukbulma(char metin[]) fonksiyonu; Bu kelimenin uzunluğunu bulacak. 
strlen() fonksiyonun işlevini yapar.
(strlen fonksiyonu başlangıç adresini aldığı yazının uzunluğu ile geri döner.)


****	palindrome(char metin[], int uzunluk) fonksiyonu; 

	if (5 <= 0) 'YANLIŞ'
	{
		return 1;   
	}

	else if (metin[0] == metin[4])  (  (metin[0]: KK)== (metin[4]: K) ) 'DOĞRU'
	{
		return palindrome(metin + 1, 5 - 2); başa geri dönüyor
	}

		if (3 <= 0) 'YANLIŞ'
		{
			return 1;   
		}	

		else if (metin[0] == metin[2]) ( (metin[1]: A) ==  (metin[3]: A) ) 'DOĞRU'

		{

			return palindrome(metin + 1, 3 - 2); başa geri dönüyor

		}
			
			if (1 <= 0) 'YANLIŞ'
			{
				return 1;
			}

			else if (metin[0] == metin[0])  ( (metin[2]: Z) == (metin[2]: Z) )  'DOĞRU'

			{

				return palindrome(metin + 1, 1 - 2 ); başa geri dönüyor

			}

				
				if (-1 <= 0) 'DOĞRU'

				{
					return 1; 
				}


**** int sonuc = palindrome(metin, uzunluk);

	if (sonuc == 1)  'DOĞRU'
	{
		printf("\n '%s' ifadesi palindromdur\n", metin);
	}


*/
