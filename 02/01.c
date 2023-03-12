/* Tek Sayıların Toplamı

// While Kullanımı

Klavyeden çift sayı girilene kadar girilmiş olan tek sayıların toplamını hesaplayıp yazdıran programı C dili ile yazınız*/


#include <stdio.h>  
#include <locale.h>  


int main()
{
	setlocale(LC_ALL, "Turkish");
		
    int sayi, toplam=0;
    
    printf("Bir sayı giriniz: ");
    
    scanf("%d", &sayi);

   
    while (sayi%2!=0)
    {
        toplam+=sayi;
        printf("Bir Sayı Giriniz: ");
        scanf("%d", &sayi);
    }
    
	printf("Tek Sayıların Toplamı = %d", toplam);
    return 0;
 }
