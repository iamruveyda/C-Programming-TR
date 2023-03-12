/* Dosya Örnek Uygulama

 Öğrencilere ait numara, isim, vize ve final notunun tutulduğu “notlar.txt” isimli dosya üzerinde işlemler yapabileceğiniz bir C programı yazınız. Buna göre programın menüsü şu şekilde olacaktır:,
 1- Dosya oluştur / veri gir
 2- Dosyadan oku / listele
 3- Geçme notu 60 üstü olanları listele
 4- Dosyada geçme notu 60 ve üstü olanları “gecenler.txt”, düşük olanları ise “kalanlar.txt”  dosyasına yazdır.
 5- Dosya boyutunu ekrana yazdır.
Not: Her bir menü seçeneği bir fonksiyon ile yapılıcaktır.

*/

#include <stdio.h>
#include <locale.h>


struct ogrenci {
	int okul_no;
	char isim[40];
	int vize_notu;
	int final_notu;


};

void dosyaOlustur()
{
	struct ogrenci okul;

	int i;
	int ogrenci_sayisi;

	printf("Öğrenci Sayısını Giriniz: ");
	scanf("%d", &ogrenci_sayisi);

	printf("\n");

	FILE* fptr;

	if ((fptr = fopen("notlar.txt", "w")) == NULL)
		printf("Dosya Açılamadı\n");

	else
	{
		for (i = 0; i < ogrenci_sayisi; ++i)
		{
			printf("%d. Öğrenci\n", i + 1);

			printf("Öğrencinin Okul Numarası:");
			scanf("%d", &okul.okul_no);

			printf("Öğrencinin Adı:");
			scanf("%s", okul.isim);

			printf("Öğrencinin Vize Notu:");
			scanf("%d", &okul.vize_notu);

			printf("Öğrencinin Final Notu:");
			scanf("%d", &okul.final_notu);

			printf("\n");

			fprintf(fptr, "%d\t%s\t%d\t%d\n", okul.okul_no, okul.isim, okul.vize_notu, okul.final_notu);

		}

		fclose(fptr);
	}


	printf("\nÖğrenci Notları Dosyaya Yazıldı\n");

}

void dosyaOku()
{
	struct ogrenci okul;

	FILE* fptr;


	if ((fptr = fopen("notlar.txt", "r")) == NULL)
		printf("Dosya Açılamadı\n");

	else
	{
		fscanf(fptr, "%d%s%d%d", &okul.okul_no, okul.isim, &okul.vize_notu, &okul.final_notu);


		while (!feof(fptr))
		{

			printf("%d\t%s\t%d\t%d\n", okul.okul_no, okul.isim, okul.vize_notu, okul.final_notu);

			fscanf(fptr, "%d%s%d%d", &okul.okul_no, okul.isim, &okul.vize_notu, &okul.final_notu);
		}


	}

	fclose(fptr);
}

void listele()
{
	struct ogrenci okul;

	FILE* fptr;

	int gecme_notu;



	if ((fptr = fopen("notlar.txt", "r")) == NULL)
		printf("Dosya Açılamadı\n");

	else
	{
		fscanf(fptr, "%d%s%d%d", &okul.okul_no, okul.isim, &okul.vize_notu, &okul.final_notu);

		gecme_notu = (okul.vize_notu * 0.4) + (okul.final_notu * 0.6);

		while (!feof(fptr))
		{

			if (gecme_notu >= 60)
			{
				printf("%d\t%s\t%d\t%d\n", okul.okul_no, okul.isim, okul.vize_notu, okul.final_notu);
			}

			fscanf(fptr, "%d%s%d%d", &okul.okul_no, okul.isim, &okul.vize_notu, &okul.final_notu);

			gecme_notu = (okul.vize_notu * 0.4) + (okul.final_notu * 0.6);

		}

	}



	fclose(fptr);
}

void dosyaKopyalama()
{
	struct ogrenci okul;

	FILE* fptr = fopen("notlar.txt", "r");
	FILE* kalan = fopen("kalanlar.txt", "w");
	FILE* gecen = fopen("gecenler.txt", "w");

	int gecme_notu;


	if (fptr == NULL)
		printf("Dosya Açılamadı\n");

	else
	{
		fscanf(fptr, "%d%s%d%d", &okul.okul_no, okul.isim, &okul.vize_notu, &okul.final_notu);

		gecme_notu = (okul.vize_notu * 0.4) + (okul.final_notu * 0.6);

		while (!feof(fptr))
		{
			if (gecme_notu >= 60)
			{
				fprintf(gecen, "%d\t%s\t%d\t%d\n", okul.okul_no, okul.isim, okul.vize_notu, okul.final_notu);
			}

			else
			{
				fprintf(kalan, "%d\t%s\t%d\t%d\n", okul.okul_no, okul.isim, okul.vize_notu, okul.final_notu);
			}

			fscanf(fptr, "%d%s%d%d", &okul.okul_no, okul.isim, &okul.vize_notu, &okul.final_notu);
			gecme_notu = (okul.vize_notu * 0.4) + (okul.final_notu * 0.6);
		}

	}

	printf("\nGeçenler ve Kalanlar İçin Ayrı Dosyalar Oluşturuldu.\n");


	fclose(kalan);
	fclose(gecen);
	fclose(fptr);
}

void dosyaBoyutu()
{
	int i = 0;
	char k;

	FILE* fptr = fopen("notlar.txt", "r");

	if (fptr == NULL)
		printf("Dosya Açılamadı\n");

	else
	{

		k = fgetc(fptr);

		while (!feof(fptr))
		{
			i++;
			k = fgetc(fptr);
		}


	}

	printf("Dosyanın Boyutu: %d Byte\n", i);
	fclose(fptr);
}



int main()
{
	setlocale(LC_ALL, "Turkish");

	int sec = 6;

	while (sec != 7)
	{
		printf("\n1 - Dosya Oluştur\n"
			"2 - Dosyayı Oku\n"
			"3 - Dersi Geçen Öğrencilerin Listesi\n"
			"4 - Geçenler Ayrı Dosyaya Kalanları Ayrı Dosyaya Yazdır\n"
			"5 - Dosya Boyutunu Ekrana Yazdır\n"
			"6 - Çıkış\n");

		printf("Seçiminizi Yapınız:");
		scanf("%d", &sec);

		printf("\n");

		if (sec == 1) dosyaOlustur();
		else if (sec == 2) dosyaOku();
		else if (sec == 3) listele();
		else if (sec == 4) dosyaKopyalama();
		else if (sec == 5) dosyaBoyutu();
		else if (sec == 6) exit(0);
	}
}
