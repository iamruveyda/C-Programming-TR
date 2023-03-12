/* Bilgiyi Ekrana Basma

Dosyada bilgileri tutulan öğrencilerden en yüksek ikinci final notuna
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


void ikinciMax(FILE*okuPtr)
{

	struct ogrenci bilgi, max1, max2;

	fread(&bilgi, sizeof(struct ogrenci), 1, okuPtr); //İlk Kaydı okur.

/* fread: Dosyadan belirtilen kadar bayt okuyup hafızaya atar.
	fread(bellek, boyutu, sayısı, dosya_gosterici);

		bellek= dosyadan okutulacak yazdırılacak verinin geçici olarak
				bellekte saklanacağı alan
		boyutu= okutulacak alanı uzunluğu
		sayısı= verinin tekrarlanma sayısı
*/

	max1 = bilgi;
	max2 = bilgi;

	while (!feof(okuPtr)) //Dosyanın sonuna gelene kadar devam et.

/*
	feof(Dosya İşaretçisi):  Dosyanın sonunu gösterir.
*/
	{
		if (bilgi.not> max1.not)
		{
			max2 = max1;
			max1 = bilgi;
		}

		else if (bilgi.not> max2.not)
			max2 = bilgi;

		fread(&bilgi, sizeof(struct ogrenci), 1, okuPtr);

	}

	printf("İkinci En Büyük Final Notu Olan Öğrenci\n");
	printf("%d\t%s\t%2.f\n", max2.numara, max2.ad, max2.not);


}


int main(void)
{
	setlocale(LC_ALL, "Turkish");

	FILE* myPtr;

	if ((myPtr = fopen("student.dat", "r")) == NULL)
		printf("Dosya Açılamadı\n");

	else
		ikinciMax(myPtr);
}
