/* Çift Bağlı Liste (Double Linked List) Uygulaması */

#include <stdio.h>
#include <locale.h> //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 

struct database {
	int number;
	struct database* next;
	struct database* prev;
};

typedef struct database node;

node* head, * end, * tmp;


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
			end = head;
		}
		else {
			tmp->next = (node*)malloc(sizeof(node));
			tmp = tmp->next;
		}
		printf("%d. Sayıyı Giriniz: ", i + 1);
		scanf("%d", &tmp->number);
		tmp->prev = end;
		tmp->next = NULL;
		end->next = tmp;
		end = tmp;

	}

	printf("\n #Listeniz Oluşturuldu. Görmek İçin Ekrana Yazdırın\n");


	/*
	Oluşturulan listede;
	head = ilk düğüm
	end  = son düğüm
	tmp  = boş düğüm
						oldu.

	*/
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
	q = NULL;

	if (head->number == sayi)
	{

		if (head == NULL)
		{
			printf(" #Silme İşlemi Yapılamıyor.\n");
		}
		else
		{
			head = head->next;
			head->prev = NULL;

			free(p);

			printf("\n #Veri Başarıyla Silindi\n"
				"\n     (Listenin Baştaki (İlk Düğümü) Silindi)\n");
		}
	}
	else
	{
		while (p->next != NULL && p->number != sayi)
		{
			q = p;
			p = p->next;
		}

		if (p == end)
		{
			if (end == NULL)
			{
				printf(" #Silme İşlemi Yapılamıyor.\n");
			}
			else
			{
				end = end->prev;
				end->next = NULL;

				free(p);

				printf("\n #Veri Başarıyla Silindi\n"
					"\n     (Listenin Sonundaki (Son Düğümü) Silindi)\n");
			}
		}

		else if (p != end)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;

			free(p);

			printf("\n #Veri Başarıyla Silindi\n");
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
	tmp->prev = NULL;
	p->prev = tmp;
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
	tmp->prev = p;
	p->next = tmp;

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


/*-------------------------   9  -------------------------*/

void addthen() //head listesinin n. düğümün hemen ardından tmp düğümü ekleme
{
	node* p;

	tmp = (node*)malloc(sizeof(node));

	printf("Eklenecek Sayıyı Giriniz: ");
	scanf("%d", &tmp->number);

	int n;

	printf("Hangi Düğümden Sonra Eklensin: ");
	scanf("%d", &n);

	p = head;

	int i = 1;

	while (i < n) {
		head = head->next;
		i++;
	}

	tmp->prev = head;
	tmp->next = head->next;
	head->next = tmp;
	head = p;

}



/*-------------------------   10  -------------------------*/

void palindrom()
{
	/*(Palindrom, tersten okunuşu da aynı olan cümle, sözcük ve sayılara denilmektedir.)*/

	node* p, * q;


	if (head == NULL)
		return 1;

	p = head;
	q = NULL;

	while (p->next != NULL)
	{
		q = p;
		p = p->next;
	}

	while (head != p)
	{
		if (head->number != p->number)
		{
			printf(" Palindrom değildir\n");
			return 0;
		}

		head = head->next;
		p = q; //p=p->prev;
	}

	printf(" Palindromdur\n");
	return 1;
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
			"  8 - Listeyi Sil(Yok et)\n"
			"  9 - Listede Araya Eleman Ekleme\n"
			" 10 - Liste Palindrom Mudur?\n"


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
		else if (sec == 8) listeyiSil();
		else if (sec == 9) addthen();
		else if (sec == 10) palindrom();
	}
}
