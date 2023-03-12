/* Dosya Güncelleme

Dosyada bilgileri tutulan öğrencilerden final notu 55 ile 59 arasında olan
tüm öğrencilerin notuna 5 puan ekleyerek dosyayı güncelleyen(update) program kodu

// Rastgele Erişimli Dosya

*/
#include <stdio.h>
#include <locale.h>

struct ogrenci
{
	int numara;
	char ad[20];
	float final_notu;
};


void main()
{
	setlocale(LC_ALL, "Turkish");

	struct ogrenci bilgi;

	int i = 1;

	FILE* myPtr;

	if ((myPtr = fopen("student.dat", "r+")) == NULL)
		printf("Dosya Açılamadı\n");

	/*
	r+ -> Dosya hem okuma hem de yazma için açılır.
		  Dosya yok ise açılamaz.
	*/

	else
	{
		fread(&bilgi, sizeof(struct ogrenci), 1, myPtr); //İlk Kaydı Okur

	/*fread: Dosyadan belirtilen kadar bayt okuyup hafızaya atar.

	fread(bellek, boyutu, sayısı, dosya_gosterici);

		bellek= dosyadan okutulacak yazdırılacak verinin geçici olarak
				bellekte saklanacağı alan
		boyutu= okutulacak alanı uzunluğu
		sayısı= verinin tekrarlanma sayısı
	*/
		while (!feof(myPtr)) //Dosyanın sonuna gelene kadar devam et.

	/*
	feof(Dosya İşaretçisi):  Dosyanın sonunu gösterir.
	*/
		{
			if (bilgi.final_notu >= 55 && bilgi.final_notu <= 59)
			{
				bilgi.final_notu += 5;

				fseek(myPtr, (i - 1) * sizeof(struct ogrenci), SEEK_SET);

				/* fseek: Dosyadaki konumu belirtilen işaretçinin konumunu ayarlar.

				fseek(dosya_gostericisi,offset,symbolic_constant)

					offset= dosyadaki konumu gösteren işaretçi
					symbolic_constant= dosyanın neresinden okumaya başlayacağını gösterir.

						SEEK_SET - başından başla
						SEEK_CUR - mevcut bulunan konumdan başla
						SEEK_END - dosyanın sonundan başla
				*/

				fwrite(&bilgi, sizeof(struct ogrenci), 1, myPtr);
				
				/*fwrite: bellekteki görüntüsü ile dosyaya yazar.

				fwrite(bellek, boyutu, sayısı, dosya_gosterici);

					bellek= dosyadan okutulacak yazdırılacak verinin geçici olarak
							bellekte saklanacağı alan
					boyutu= okutulacak alanı uzunluğu
					sayısı= verinin tekrarlanma sayısı
				*/

			}

			i++; //Bir sonraki kayıt için indisi artırır.

		//Sıradaki kaydı oku.
			fseek(myPtr, (i - 1) * sizeof(struct ogrenci), SEEK_SET);
			fread(&bilgi, sizeof(struct ogrenci), 1, myPtr);

		}


		printf("Hesaplar Güncellendi");


	}


	fclose(myPtr);  //Açılmış olan dosyayı kapatır.
}
