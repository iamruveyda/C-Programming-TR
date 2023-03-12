/* Burası yorum satırıdır */

// #include [Başlığı(Header)] <kütüphane>

#include <stdio.h> //Her C programında olması gerekir.  //stdio.h: [STandarD Input/Output(Standart Girdi/Çıktı)]                   

#include <locale.h>  //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 

/*  main() fonksiyonu her C programında bulunması gereken bir fonksiyondur */


int main()
{
    printf("Hello world!\n");
     
    setlocale(LC_ALL,"Turkish"); //Türkçe karakter yazdırmamızı sağlayan fonksiyon
 
    printf("Merhaba Dünya\n");
   
    printf("İĞÜÇÖŞ iğüçöş");
	
    return; // Geriye değer gönderme işlemi yapar.
}
