#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Karakterler


\0 > sonlandırıcı karakter (null character) 
\a > çan sesi (alert) 
\b > geri boşluk (back space) 
\t > 1 tane tab kadar boşluk bırakır. (horizontal TAB) 
\n > Bir alt satıra geçer(new line) 
\v > düşey tab (vertical tab) 
\f > sayfa ileri (form feed) 
\r > satır başı (carriage return) 

*/


/*
Veri Tipleri
   char-> int -> float -> double


   - char    : Karakter(Character): Alfabedeki büyük küçük harfler, özel semboller //1 byte (-128'den 127'ye kadar) STANDART ASCII TABLOSU

	 unsigned char > İşaretsiz char Türü

   - int     : Tamsayı(İnteger): Tamsayı değişken ve sabitleri tanımlamak için kullanılır. //4 byte

	 [signed] short [int] > İşaretli Kısa Tamsayı Türü    // 2 byte (-32.768 - 32.767)
	 [signed] long  [int] > İşaretli Uzun Tamsayı Türü    // 4 byte (-2.147.483.648 - 2.147.483.647)
	 unsigned short [int] > İşaretsiz Kısa Tamsayı Türü   // 2 byte
 	 unsigned long  [int] > İşaretsiz Uzun Tamsayı Türü	  // 4 byte

   - float   : Küsüratlı Sayılar: Virgüllü kısmıyla ifade eder. //4 byte

   - double  : Daha Hassas Küsüratlı Sayılar: Float türünden 2 kat daha duyarlıdır. //8 byte
	   
	 long double

*/


/*
Yer ve Tür Belirleyiciler
   Yer Belirleyicileri
	- auto
	- register
	- static
	- extern
   Tür Belirleyicileri
	- const       > Bir değişken ile tanımlandığında ve ilk değer atandığında, bu değişken içeriği hiç değişmez.
	ÖRN: const pi = 3.14;
		 const double pi = 3.1416;

	- volatile


*/


int main()

{
	setlocale(LC_ALL, "Turkish");

	int tamsayi;

	char karakter;

	char karakterDizisi[50];

	float kesirlisayi1;

	double kesirlisayi2;

	/* scanf veri alır, printf veri gönderir*/

	printf("Lütfen bir tam sayı giriniz: ");
	scanf("%d", &tamsayi);

	printf("Lütfen bir karakter giriniz: ");
	scanf(" %c", &karakter);

	/* scanf(" %c" ,&karakter);
	Program içerisinde kullanıcıdan birden fazla tipte değer almak istediğimizde derleyicinin kafasının karışmaması 
	için karakter alırken bir boşluk kullanarak karakter değerini kullanıcıdan almalıyız.
	 */

	printf("Lütfen bir karakter dizini giriniz: ");
	scanf("%s", &karakterDizisi);  	
	// scanf("%s" ,&karakterDizisi),  scanf("%s" ,karakterDizisi), scanf("%s" ,karakterDizisi[0]) 

	printf("Lütfen bir kesirli sayı giriniz: "); // Program bizden kesirli bir sayı değeri girmemizi istediğinde virgül kullanarak girmeliyiz.
	scanf("%f", &kesirlisayi1);

	printf("Lütfen bir daha hassas küsüratlı bir sayı giriniz: ");
	scanf("%lf", &kesirlisayi2);


	/* printf ("Sabit metin bilgisi", değişken ismi)*/
	printf("\n\n");

	printf("Girilen Tam Sayı: %d\n", tamsayi);
	printf("Girilen Karakter: %c\n", karakter);
	printf("Girilen Karakter Dizisi: %s\n", karakterDizisi);
	printf("Girilen Kesirli Sayı: %f\n", kesirlisayi1);
	printf("Girilen Hassas Küsüratlı Sayı: %lf\n", kesirlisayi2);




	int x = 15;
	float y = 15;
	double z = 15;

	printf("\n\n");
	printf("int / float= %f\n", x / y);
	printf("int / float= %lf\n", x / z);
	printf("float / double= %f\n", y / z);


	int t = 3;
	printf("\n\n");
	printf("%f\n", (float)x);
	printf("%.1f", (float)x);

}
