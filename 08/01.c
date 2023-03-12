/* Tek Bağlı Liste (Singly Linked List) Uygulaması */


#include <stdio.h>
#include <locale.h> //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 



struct database {
	int number;
	struct database* next;
};

typedef struct database node;

node* head, * tmp;


/*-------------------------   1  -------------------------*/

void createList() //Liste Oluşturma Fonksiyonu
{
	int n, i;

	printf("Veri Sayısını Giriniz: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{

		if (i == 0) {
			head = (node*)malloc(sizeof(node));
			tmp = head;
		}

		else {
			tmp->next = (node*)malloc(sizeof(node));
			tmp = tmp->next;
		}

		printf("%d. Veriyi Giriniz: ", i + 1);
		scanf("%d", &tmp->number);
	}

	tmp->next = NULL;

	printf("\n #Listeniz Oluşturuldu. Görmek İçin Ekrana Yazdırın\n");
}

/*-------------------------   2  -------------------------*/

void printList() //Listeyi Ekranda Gösteren Fonksiyon
{
	node* p;

	p = head;

	int i = 0;

	if (p == NULL) {

		printf("\n #Listede Bir Veri Yok\n");
		return;
	}

	printf("\n#Oluşturduğunuz Liste; \n");

	while (p != NULL)
	{
		printf("%d. Sayı: %d\n", i + 1, p->number);
		p = p->next;
		i++;
	}
	printf("\n");
}

/*-------------------------   3  -------------------------*/

void deleteNode() //Listede Silmek İstediğiniz Veriyi Silen Fonksiyon
{
	node* p, * q;

	int sayi;

	printf("Silmek İstediğiniz Veri(Sayıyı) Giriniz: ");
	scanf("%d", &sayi);

	p = head;
	q = head;


	if (p->number == sayi)
	{
		head = p->next;

		free(p);

		printf("\n #Veri Başarıyla Silindi\n"
			"\n  (Listenin İlk Düğümü Silindi)\n");
	}

	else
	{
		while (p->next != NULL && p->number != sayi)
		{
			q = p;
			p = p->next;
		}

		if (p->number == sayi)
		{
			q->next = p->next;
			free(p);
			printf("\n #Veri Başarıyla Silindi\n");
		}

		else if (p->next == NULL)
		{
			printf("\n #Silinecek Bir Veri Bulunamadı\n");
		}
	}

}

/*-------------------------   4  -------------------------*/

void addNode() //Listeye İstediğiniz Veriden önce Düğüm Ekleme
{
	node* p, * q;

	int sayi;

	tmp = (node*)malloc(sizeof(node));

	printf("Eklenecek Veriyi(Sayıyı) Giriniz: ");
	scanf("%d", &tmp->number);

	printf("Hangi Sayıdan Önce Ekrana Yazılsın? =  ");
	scanf("%d", &sayi);

	p = head;
	q = head;

	if (p->number == sayi)
	{
		tmp->next = p;
		head = tmp;
		printf("\n #Veri Listenin Başına Eklendi. Görmek İçin Ekrana Yazdırın\n");
	}
	else
	{
		while (p->next != NULL && p->number != sayi)
		{
			q = p;
			p = p->next;
		}

		if (p->number == sayi)
		{
			q->next = tmp;
			tmp->next = p;
			printf("\n #Veri Belirtilen Konuma Eklendi. Görmek İçin Ekrana Yazdırın\n");
		}

		else if (p->next == NULL)
		{
			p->next = tmp;
			tmp->next = NULL;
			printf("\n #Veri Listenin Sonuna Eklendi. Görmek İçin Ekrana Yazdırın\n");
		}
	}
}

/*-------------------------   5  -------------------------*/


void addNodeFirst() //Listenin Başına Düğüm Ekleme
{
	node* p;

	tmp = (node*)malloc(sizeof(node));

	printf("Eklenecek Veriyi(Sayıyı) Giriniz: ");
	scanf("%d", &tmp->number);

	p = head;

	tmp->next = p;
	head = tmp;

	printf("\n #Veri Listenin Başına Eklendi. Görmek İçin Ekrana Yazdırın\n");
}


/*-------------------------   6  -------------------------*/


void addNodeLast() //Listenin Sonuna Düğüm Ekleme
{
	node* p, * q;

	tmp = (node*)malloc(sizeof(node));

	printf("Eklenecek Veriyi(Sayıyı) Giriniz: ");
	scanf("%d", &tmp->number);

	p = head;

	while (p->next != NULL)
	{
		q = p;
		p = p->next;
	}

	p->next = tmp;
	tmp->next = NULL;

	printf("\n #Veri Listenin Sonuna Eklendi. Görmek İçin Ekrana Yazdırın\n");
}


/*-------------------------   7  -------------------------*/

void cnt() //Listedeki Eleman Sayısını Ekrana Yazdırma
{
	node* p;
	int sayac = 0;

	p = head;

	while (p != NULL)
	{
		sayac++;
		p = p->next;
	}

	printf("\n #Eleman Sayısı: %d\n", sayac);
}



/*-------------------------   8  -------------------------*/

void sondakiDugumuBasaAlma() {

	node* p, * q;

	p = head;
	q = NULL;

	while (p != NULL && p->next != NULL)
	{
		q = p;
		p = p->next;
	}

	q->next = NULL;
	p->next = head;
	head = p;

	printf("\n #Sondaki Düğüm Başa Alındı. Görmek İçin Ekrana Yazdırın\n");
}

/*-------------------------   9  -------------------------*/

void listeyiSil()
{
	node* p;

	if (head == NULL) {
		printf("\n #Listede Sayı Yok\n");
		return;
	}

	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
	printf("\n #Liste Yok Edildi\n");
}


/*-------------------------  10  -------------------------*/


void yer_degistirme() // İstediğiniz İki Verinin Yerini Değiştirme
{
	node* prev1, * prev2, * node1, * node2, * temp;

	prev1 = NULL;
	prev2 = NULL;
	temp = NULL;
	node1 = head;
	node2 = head;

	int n1, n2;

	printf("Yer Değiştirmek İstediğiniz İki Tane Sayının Değerlerini Giriniz: \n");
	scanf("%d %d", &n1, &n2);


	// Listenin Boş Olup Olmadığını Kontrol Etme
	if (head == NULL) {
		return;
	}

	// Sayılar eşitse yer değişmeyecek  
	if (n1 == n2)
		return;

	//Arama Yapma (dugum1 için)
	while (node1 != NULL && node1->number != n1) {
		prev1 = node1;
		node1 = node1->next;
	}

	//Arama Yapma (dugum2 için)
	while (node2 != NULL && node2->number != n2) {
		prev2 = node2;
		node2 = node2->next;
	}

	if (node1 != NULL && node2 != NULL) {


		if (prev1 != NULL)
			prev1->next = node2;
		else
			head = node2;

		if (prev2 != NULL)
			prev2->next = node1;
		else
			head = node1;

		temp = node1->next;
		node1->next = node2->next;
		node2->next = temp;
	}
	else {
		printf("#Yer Değiştirme Yapılamıyor.\n");
	}
}


/*-------------------------  11  -------------------------*/

void en_buyuk_sayi()
{
	node* p;

	p = head;

	int enBuyuk = p->number;

	while (p != NULL)
	{
		if (p->number >= enBuyuk)
		{
			enBuyuk = p->number;
		}
		p = p->next;
	}

	printf("\nEn Büyük Sayı= %d\n", enBuyuk);
}

/*-------------------------  12  -------------------------*/

void en_kucuk_sayi()
{
	node* p;

	p = head;

	int enKucuk = p->number;

	while (p != NULL)
	{
		if (p->number <= enKucuk)
		{
			enKucuk = p->number;
		}
		p = p->next;
	}

	printf("\nEn Küçük Sayı= %d\n", enKucuk);
}


/*-------------------------  13  -------------------------*/

void ortalama()
{
	node* p;

	p = head;

	int ortalama, toplam = 0, i = 0;

	if (p == NULL)
	{
		printf("\nListede Sayı Yok\n");
	}

	else
	{
		while (p != NULL)
		{
			toplam += p->number;
			p = p->next;
			i++;
		}

		ortalama = toplam / i;

		printf("\nListenin Ortalaması= %d\n", ortalama);
	}
}

/*-------------------------  14  -------------------------*/

void reverselist()
{
	node* prevNode, * curNode;

	if (head != NULL)
	{
		prevNode = head;
		curNode = head->next;
		head = head->next; //curNode ve head aynı yerde oldu.

		prevNode->next = NULL; //ilk düğümü diğerlerinden ayırıyor. 

		while (head != NULL)
		{
			head = head->next;
			curNode->next = prevNode;

			prevNode = curNode;
			curNode = head;
		}

		head = prevNode;
	}

	printf("\n #Liste Ters Çevirildi. Görmek İçin Ekrana Yazdırın\n");


	/* Kaynak: https://codeforwin.org/2015/09/c-program-to-reverse-singly-linked-list.html */
}

/*-------------------------  15  -------------------------*/

void en_kucugu_cift_dugumlerden_cikar()
{
	node* p;

	p = head;

	int enKucuk = p->number;

	while (p != NULL)
	{
		if (p->number <= enKucuk)
		{
			enKucuk = p->number;
		}
		p = p->next;
	}

	p = head;

	while (p != NULL)
	{
		if ((p->number) % 2 == 0)
		{
			p->number -= enKucuk;
		}
		p = p->next;
	}

	printf("\nEn Küçük Sayı Tüm Çift Sayılardan Çıkarıldı. Görmek İçin Ekrana Yazdırın\n");


}

/*-------------------------  16  -------------------------*/

void en_buyugu_cift_dugumlerden_cikar()
{
	node* p;

	p = head;

	int enBuyuk = p->number;

	while (p != NULL)
	{
		if (p->number >= enBuyuk)
		{
			enBuyuk = p->number;
		}
		p = p->next;
	}

	p = head;

	while (p != NULL)
	{
		if ((p->number) % 2 == 0)
		{
			p->number -= enBuyuk;
		}
		p = p->next;
	}

	printf("\nEn Büyük Sayı Tüm Çift Sayılardan Çıkarıldı. Görmek İçin Ekrana Yazdırın\n");


}

/*-------------------------  17  -------------------------*/

void delete_same_node() //Aynı sayıları siliyor.
{
	node* p, * q, * r;

	p = head;

	while (p != NULL && p->next != NULL)
	{
		q = p;

		while (q->next != NULL)
		{
			if (p->number == q->next->number)
			{
				r = q->next;
				q->next = q->next->next;
				free(r);
			}

			else
				q = q->next;
		}
		p = p->next;
	}

	printf("\nGörmek İçin Ekrana Yazdırın\n");
}

/*-------------------------  18 -------------------------*/

void list_bilgi() {

	int i = 1;

	while (head != NULL) {

		printf("%d. Düğümün Adresi= %p \n", i, head);
		printf("%d. Düğümün Verisi= %d \n", i, head->number);
		printf("%d. Düğümün Bağlı Olduğu Dğümün Adresi= %p \n\n", i, head->next);
		head = head->next;
		i++;
	}

}



/*-------------------------  101 -------------------------*/


void question_01() {

	node* yenidugum;

	head = (node*)malloc(sizeof(node));

	if (head == NULL)
	{
		printf("YETERLİ HAFIZA YOK");
		exit(0);
	}

	head->next = NULL;
	tmp = head;


	int number;

	printf("Sayı Giriniz: ");
	scanf("%d", &number);


	if (number == -1)
	{
		printf("\nProgram Sonlandırıldı\n");
		exit(0);
	}

	else

		head->number = number;


	while (1)
	{
		printf("Sayı Giriniz: ");
		scanf("%d", &number);

		if (number == -1)
			break;


		if (number % 2 == 0)
		{

			yenidugum = (node*)malloc(sizeof(node));

			if (yenidugum == NULL)
			{
				printf("YETERLI HAFIZA YOK");
				exit(0);
			}

			yenidugum->number = number;
			yenidugum->next = NULL;

			head->next = yenidugum;
			head = yenidugum;
		}

		else
		{
			yenidugum = (node*)malloc(sizeof(node));

			if (yenidugum == NULL)
			{
				printf("YETERLI HAFIZA YOK");
				exit(0);
			}

			yenidugum->number = number;
			yenidugum->next = tmp;

			tmp = yenidugum;
		}

	}


	while (tmp != NULL)
	{
		printf("%d\n", tmp->number);

		tmp = tmp->next;

	}

}


/*-------------------------  MAIN  -------------------------*/

int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter yazdırmamızı sağlayan fonksiyon

	int sec = 0;

	while (sec != 100)
	{

		printf("*************************\n"
			"  0 - Programdan Çıkış Yap\n"
			"  1 - Listenizi Oluşturun\n"
			"  2 - Listeyi Ekrana Yazdırın\n"
			"  3 - Listede İstediğiniz Herhangi Bir Veriyi Silin\n"
			"  4 - Listeye Veri Ekleme (Seçilen Verinin Öncesine Ekler)\n"
			"  5 - Listenin Başına Veri Ekleme\n"
			"  6 - Listenin Sonuna Veri Ekleme\n"
			"  7 - Listedeki Verilerin Sayısı\n"
			"  8 - Listenin Sondaki Düğümü Başa Alma\n"
			"  9 - Listeyi Sil(Yok et)\n"
			" 10 - Listedeki Değerlerin Yerlerini Değiştirme\n"
			" 11 - Listedeki En Büyük Sayıyı Bulma\n"
			" 12 - Listedeki En Küçük Sayıyı Bulma\n"
			" 13 - Listedeki Değerlerin Ortalamasını Bulma\n"
			" 14 - Listedeki Değerleri Ters Çevirme\n"
			" 15 - Listedeki En Küçük Sayıyı Tüm Çift Sayılardan Çıkarma\n"
			" 16 - Listedeki En Büyük Sayıyı Tüm Çift Sayılardan Çıkarma\n"
			" 17 - Listede Aynı Değere Sahip Olan Düğümleri Silme\n"
			" 18 - Liste Elemanlarının Tüm Bilgileri\n"

			" \n*** EKSTRA***\n"
			" 101 - Klavyeden -1 girilene kadar verilen tek sayıları tek bağlı doğrusal bir listenin başına, verilen çift sayıları ise listenin sonuna ekle\n"
		

		);

		printf("\n Seçiminizi Yapınız:");
		scanf("%d", &sec);

		printf("\n");

		if (sec == 0) exit(0);
		else if (sec == 1) createList();
		else if (sec == 2) printList();
		else if (sec == 3) deleteNode();
		else if (sec == 4) addNode();
		else if (sec == 5) addNodeFirst();
		else if (sec == 6) addNodeLast();
		else if (sec == 7) cnt();
		else if (sec == 8) sondakiDugumuBasaAlma();
		else if (sec == 9) listeyiSil();
		else if (sec == 10) yer_degistirme();
		else if (sec == 11) en_buyuk_sayi();
		else if (sec == 12) en_kucuk_sayi();
		else if (sec == 13) ortalama();
		else if (sec == 14) reverselist();
		else if (sec == 15) en_kucugu_cift_dugumlerden_cikar();
		else if (sec == 16) en_buyugu_cift_dugumlerden_cikar();
		else if (sec == 17) delete_same_node();
		else if (sec == 18) list_bilgi();
		else if (sec == 101) question_01();



	}
}
