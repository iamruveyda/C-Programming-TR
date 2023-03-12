/* Dosyadan Dosyaya Kopyalama

Sıralı erişimli "notlar.txt" isimli bir dosyada öğrenci no(int), ad ve not(float) bilgisi tutulmaktadır. 
Bu dosyada yer alan kayıtlar arasında ismi "Ahmet" olan ve notu 60 ve üzerinde olan öğrencileri 
"basari.dat" isimli rastgele erişimli bir dosyaya yazarak aktaran kod

// Sıralı Erişimli Dosya -> Rastgele Erişimli Dosya


*/


#include <stdio.h>
#include <string.h>
#include <locale.h>


struct ogrenci
{
	int no;
	char ad[20];
	float not;
};


int main(void)
{
	setlocale(LC_ALL, "Turkish");

	FILE* ptr1, * ptr2;

	struct ogrenci kayit;

	ptr1 = fopen("notlar.txt", "r");
	ptr2 = fopen("basari.dat", "w");

	if (ptr1 != NULL && ptr2 != NULL)
	{
		fscanf(ptr1, "%d %s %f", &kayit.no, kayit.ad, &kayit.not);
	
	/* fscanf: Dosyadan okuma yapan bir işlevdir.
	fscanf(dosya_gostericisi, "%d %s %f", &myInt, myString, &myFloat)
	
	*/
		
		while (!feof(ptr1)) //Dosyanın sonuna gelene kadar devam et.

	/*
	feof(Dosya İşaretçisi):  Dosyanın sonunu gösterir.
	*/
		{
			if (strcmp(kayit.ad, "Ahmet") == 0 && kayit.no >= 60)
				fwrite(&kayit, sizeof(struct ogrenci), 1, ptr2);
			fscanf(ptr1, "%d %s %f", &kayit.no, kayit.ad, &kayit.not);
		}

		fclose(ptr1);
		fclose(ptr2);
		//fclose: Açılmış olan bir dosyayı kapatır.
	}

}

/*

strcmp= birinci yazı ile ikinci yazı birbirine eşit ise 0 değeridir.

*/
