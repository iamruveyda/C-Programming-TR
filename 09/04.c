/* Bilgiyi Ekrana Basma (2)

Dosyada bilgileri tutulan öğrencilerden en düşük ikinci final notuna
sahip öğrencinin numara,ad ve notunu bilgilerini ekranan basan kod

//  Rastgele Erişimli Dosya


*/


#include <stdio.h>
#include <locale.h>


struct ogrenci
{
	int numara;
	char ad[40];
	float not;
};


void ikinciMin(FILE*okuPtr)
{

	struct ogrenci bilgi, min1, min2;

	fread(&bilgi, sizeof(struct ogrenci), 1, okuPtr); //İlk Kaydı okur.

/* fread: Dosyadan belirtilen kadar bayt okuyup hafızaya atar.
	fread(bellek, boyutu, sayısı, dosya_gosterici);

		bellek= dosyadan okutulacak yazdırılacak verinin geçici olarak
				bellekte saklanacağı alan
		boyutu= okutulacak alanı uzunluğu
		sayısı= verinin tekrarlanma sayısı
*/

	min1 = bilgi;
	min2 = bilgi;

	while (!feof(okuPtr)) //Dosyanın sonuna gelene kadar devam et.

/*
	feof(Dosya İşaretçisi):  Dosyanın sonunu gösterir.
*/
	{
		if (bilgi.not<min1.not)
		{
			min2 = min1;
			min1 = bilgi;
		}

		else if (bilgi.not < min2.not)
			min2 = bilgi;

		fread(&bilgi, sizeof(struct ogrenci), 1, okuPtr);

	}

	printf("İkinci En Düşük Final Notu Olan Öğrenci\n");
	printf("%d\t%s\t%2.f\n", min2.numara, min2.ad, min2.not);


}


int main(void)
{
	setlocale(LC_ALL, "Turkish");

	FILE* myPtr;

	if ((myPtr = fopen("student.dat", "r")) == NULL)
		printf("Dosya Açılamadı\n");

	else
		ikinciMin(myPtr);
}
