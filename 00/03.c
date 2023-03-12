/* Alan Genişliği Ayırarak Yazdırma

%d   > Tamsayı Belirleyici 
	  (int) onluk sayı sisteminde yazar.

%ld  > Uzun Tamsayı Belirleyici
	  (long) onluk sayı sisteminde yazar.

%f   > Ondalık Sayı Belirleyici
	  (float,double) onluk sayı sisteminde yazar.

%lf  > Uzun Ondalık Sayı Belirleyici
	  (double,long) onluk sayı sisteminde yazar.

%e   > Üstel Biçim Belirleyici
      Gerçek sayıları üstel biçimde yazar.

%u   > İşaretsiz Tamsayı Belirleyici
	  (unsigned int) onluk sayı sisteminde yazar.

%x   > İşaretsiz Hexadesimal (Onaltılık) Belirleyici
      (unsigned int) onaltılık sayı sisteminde yazar.

%o   > İşaretsiz Oktal (Sekizlik) Belirleyici
	  (unsigned int) sekizlik sayı sisteminde yazar.

%g   > Durume göre %f veya %e kullanılan Belirleyici
	  Kısa olan şekli tercih ederler

%c   > Karakter Belirleyici


%s   > Metin Belirleyici


*/


#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");


	printf("	%%d Kullanımı\n");
	printf("\n");


	printf("Output:%d\n", 7);
	/* Aynısı gibi yazar.*/

	printf("Output:%6d\n", 7);
	/* 6 karakterli bir alan içerisinde yazdırır. Yani 5 karakterlik yer atlayarak değeri yazar.*/

	printf("Output:%06d\n", 7);
	/* Aynı tam sayı değeri 6 karakterlik bir alan içerisine yazar ama boşluk olan yerler sıfır ile doldurur.*/

	printf("Output:%-10d\n", 75);
	/* (-) işareti sola dayalı yazdırır.*/

					printf("\n********************************\n");

	printf("	%%f Kullanımı\n");
	printf("\n");


	printf("Output:%.8f\n", 1.234);
	/* Virgülden sonrasındaki sayıyı yazdıktan sonra 8 karakterlik olması için boşluklar sıfırla tamamlanır.*/

	printf("Output:%2.3f\n", 45.58678);
	/* Tam sayı bölümü 2, desimal bölümü (Virgülden sonrası) ise 3 karakter yazdırır. Yuvarlama yapar.*/

	printf("Output:%2.3f\n", 45.58);
	/* Tam sayı bölümü 2, desimal bölümü ise 3 karakter yazdırır.*/

	printf("Output:%5.3f\n", 45.58);
	/* Tam sayı bölümü 5, desimal bölümü ise 3 karakter yazdırır.*/

	printf("Output:%-15.3f\n", 45.58);
	/* Sola dayalı tam sayı bölümü aynı, desimal bölümü ise 3 karakter yazdırır.*/

					printf("\n********************************\n");

	printf("	%%e Kullanımı\n");
	printf("\n");


	printf("Output:%+.3e\n", -123.456789);
	/* Sayısını üssel gösterimle 3 hane hassasiyetli olarak (+ -) işareti ile birlikte yazdırır.*/

	printf("Output:%.2e\n", 225.68);
	printf("Output:%20.2e\n", 225.68);
	printf("Output:%-20.2e\n", 225.68);
	
					printf("\n********************************\n");


	

	unsigned int u = 57054;
	printf("Output (%%u) = %u\n", u); /* u değerini onluk sistemde yazar */
	printf("Output (%%o) = %o\n", u); /* u değerini sekizlik sistemde yazar */
	printf("Output (%%x) = %x\n", u); /* u değerini onaltılık sistemde yazar */
	
					printf("\n********************************\n");

	long int lo = 23467;
	unsigned long int unlo = 65242;
	printf("Output (%%ld) = %ld\n", lo);   /* onluk sistemde yazar */
	printf("Output (%%lu) = %lu\n", unlo); /* onluk sistemde yazar */
	printf("Output (%%lx) = %lo\n", unlo); /* sekizlik sistemde yazar */
	printf("Output (%%lx) = %lx\n", unlo); /* onaltılık sistemde yazar */

					printf("\n********************************\n");

	
	printf("Output (%%s) = %s\n", "This is a string");

	printf("Output (%%g) = %g\n", 123456.789);
}
