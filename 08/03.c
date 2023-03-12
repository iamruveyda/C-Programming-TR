/* İkili Arama Ağacı (Binary Search Tree BTREE) */

#include <stdio.h>
#include <locale.h> //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 


struct node {
	int data;
	struct node* left;  //Sol çocuğa işaretçi
	struct node* right; // Sağ çocuğa işaretçi
};

typedef struct node BTREE;

BTREE* myroot = NULL;
BTREE* tmp;

//Fonksiyon Prototipleri
BTREE* newNode(int);
int      isBSTorNot(BTREE*);
BTREE* insert(BTREE*, int);
void     preorder(BTREE*);
void     inorder(BTREE*);
void     postorder(BTREE*);
int      size(BTREE*);
BTREE* searchtree(BTREE*, int);
int      heightofTree(BTREE*);
void     mirror(BTREE*);
void     createmyroot();
int      minValue(BTREE*);
int      maxValue(BTREE*);
BTREE* deleteNode(BTREE*, int);
int      pathTotal(BTREE*, int);
void     createmyroot();




BTREE* newNode(int data) {

	BTREE* p;

	p = (BTREE*)malloc(sizeof(BTREE)); //Bellekten yer alıyor

	p->data = data;
	p->left = NULL;
	p->right = NULL;

	return p; // Bu adresi geri dönderiyor.

}

int isBSTorNot(BTREE* root) { //İkili Arama Ağacı Kontrolü

	if (root == NULL)
		return 1;

	if (root->left != NULL && root->left->data > root->data)
		return 0;

	if (root->right != NULL && root->right->data < root->data)
		return 0;

	if (!isBSTorNot(root->left) || !isBSTorNot(root->right))
		return 0;

	return 1;
}


BTREE* insert(BTREE* root, int data) // İkili Ağaca Veri Ekleme
{
	if (root != NULL) {

		if (data < root->data)
			root->left = insert(root->left, data); //Küçükse sola ekleme

		else
			root->right = insert(root->right, data); //Büyük ve eşitse sağa ekleme
	}

	else
		root = newNode(data);
	/* Eğer root boşsa (Herhangi bir eleman yoksa) newnode(data)gönderiyor.
	   BTREE* newNode(int data) döndüreln adresi root a atıyor.
	*/

	return root;
}


void preorder(BTREE* root) { // Önce Kök

	// KÖK - SOL - SAĞ (Root-Left-Right) 

	if (root != NULL) {

		printf("%5d ", root->data);

		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BTREE* root) {  // Kök Ortada

	// SOL - KÖK - SAĞ (Left-Root-Right)

	if (root != NULL) {

		inorder(root->left);

		printf("%5d ", root->data);

		inorder(root->right);
	}
}

void postorder(BTREE* root) {  // Kök Sonda

	// SOL - SAĞ - KÖK (Left-Right-Root)

	if (root != NULL) {

		postorder(root->left);
		postorder(root->right);

		printf("%5d ", root->data);
	}
}

int size(BTREE* root) { // Düğüm Sayılarını Veren Fonksiyon

	if (root == NULL)
		return 0;

	else
		return size(root->left) + 1 + size(root->right);

}

int heightofTree(BTREE* root) { // Bir Ağacın Yüksekliğini Bulmak (Kökün Yüksekliği)

	if (root == NULL)
		return -1;

	else {

		int leftHeight, rightHeight;

		leftHeight = heightofTree(root->left);

		rightHeight = heightofTree(root->right);

		if (rightHeight > leftHeight)
			return rightHeight + 1;

		else
			return leftHeight + 1;
	}
}


BTREE* searchtree(BTREE* node, int data) { // İstenilen Veriyi Bulmak

	if (node != NULL)

		if (node->data == data)
			return node;

		else if (node->data > data)
			searchtree(node->left, data);

		else
			searchtree(node->right, data);

	else
		return NULL;
}



void mirror(BTREE* root) {
	/*
	İkili Bir Ağacın sol çocukları ile sağ çocukların yerini değiştiren fonksiyon. (Ayna Görüntüsü)

	*/
	if (root == NULL)
		return;

	else {
		BTREE* temp;

		mirror(root->left);
		mirror(root->right);

		temp = root->left; // Yer değiştirme işlemi yapıyor.

		root->left = root->right;
		root->right = temp;
	}
}

int minValue(BTREE* root) { // Ağaçtaki Tüm Verilerden En Küçük Olan Değer
	if (root == NULL)
		return 0;

	while (root->left != NULL)
		root = root->left;

	return(root->data);
}

int maxValue(BTREE* root) { // Ağaçtaki Tüm Verilerden En Büyük Olan Değer

	if (root == NULL)
		return 0;

	while (root->right != NULL)
		root = root->right;

	return(root->data);
}

BTREE* deleteNode(BTREE* root, int num) {

	BTREE* p, * q;

	if (root == NULL) //Ağaç yoksa
		return NULL;


	if (num < root->data) // Silinecek sayı, ebeveyninin verisinden küçükse
		root->left = deleteNode(root->left, num); // Sol Alt Ağaca Geçiliyor.

	else if (num > root->data) // Silinecek sayı, ebeveyninin verisinden büyükse
		root->right = deleteNode(root->right, num); // Sağ Alt Ağaca Geçiliyor.

	else
	{
		// Silinecek olan düğümün çocuğu yok ise
		if (root->left == root->right)
		{
			free(root);
			return NULL;
		}

		// Silinecek olan düğümün 1 çocuğu var ise
		if (root->left == NULL)
		{
			p = root->right;
			free(root);
			return p;
		}

		else if (root->right == NULL) {
			p = root->left;
			free(root);
			return p;
		}

		// Silinecek olan düğümün 2 çocuğu var ise

		else {
			p = q = root->right;
			while (p->left != NULL)
				p = p->left;
			p->left = root->left;
			free(root);
			return q;
		}
	}
}

int pathTotal(BTREE* root, int sum) {
	/*

	Girilin bir int değeri, kökten itibaren yaprak dahil olmak üzere o yol üzerindeki verilerin toplamına eşit mi?

	*/
	int pathSum;

	if (root == NULL) //Ağaç yok ise
		return (sum == 0);

	else {

		pathSum = sum - root->data;

		return(pathTotal(root->left, pathSum) || pathTotal(root->left, pathSum));
	}
}

void createmyroot() {

	int n = 0;
	int i = 0;

	printf("Ağaca Veri Eklemek İçin Sayı Giriniz (-1 Girilene kadar) \n");

	do {

		printf(" %d. Sayıyı Giriniz: ", i + 1);
		scanf("%d", &n);

		if (n != -1)
			myroot = insert(myroot, n);

		i++;

	} while (n != -1);

}

int main()
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karakter yazdırmamızı sağlayan fonksiyon

	int sec = 0;
	int node;

	while (sec != 100)
	{
		printf(
			"\n ****************************************************\n"
			"   1 - Ağaç Oluştur / Ağaç Varsa Veri Ekle\n"
			"   2 - İkili Bir Ağaç mı?\n"
			"   3 - Preorder?\n"
			"   4 - Inorder?\n"
			"   5 - Postorder?\n"
			"   6 - Ağaçtan İstediğiniz Veriyi Bulma\n"
			"   7 - Ağacın Yüksekliği (Kökün Yüksekliği) Nedir?\n"
			"   8 - Ağacın En Küçük Değeri Nedir?\n"
			"   9 - Ağacın En Büyük Değeri Nedir?\n"
			"  10 - Ağacın Düğümlerinin Sayısı Nedir?\n"
			"  11 - Ağaçtan Veri Silmek\n"
			"  12 - Sol Çocukları ile Sağ Çocukların Yerini Değiştir\n"
			"  13 - Girdiğiniz Değer Herhangi Bir Yol Üzerindeki Değerler Toplamına Eşit mi?\n"
			"  14 - ÇIKIŞ? \n"
		);

		printf("\n\n Seçiminizi Yapınız: ");
		scanf("%d", &sec);

		printf("\n");

		if (sec == 1) createmyroot();

		else if (sec == 2) {
			if (isBSTorNot((myroot)))
				printf("\n -- İkili Arama Ağacıdır.\n");
			else
				printf("\n -- İkili Arama Ağacı Değildir!\n");
		}

		else if (sec == 3) preorder(myroot);
		else if (sec == 4) inorder(myroot);
		else if (sec == 5) postorder(myroot);
		else if (sec == 6) {
			printf("\nAranacak Veriyi Giriniz: ");
			scanf("%d", &node);

			tmp = searchtree(myroot, node);

			if (tmp)
			{
				printf("Düğüm Bulundu= %d\n", tmp->data);
			}
			else
			{
				printf("Ağaçta Böyle Bir Veri YOK\n");
			}
		}

		else if (sec == 7) {
			printf("Ağacın Yüksekliği: %d\n", heightofTree(myroot));
		}

		else if (sec == 8) printf("%d", minValue(myroot));
		else if (sec == 9) printf("%d", maxValue(myroot));
		else if (sec == 10) printf("%d", size(myroot));
		else if (sec == 11) {

			printf("\nSilinecek Veriyi Giriniz: ");
			scanf("%d", &node);

			tmp = deleteNode(myroot, node);

			if (tmp)
			{
				printf("Düğüm Silindi");
			}
			else
			{
				printf("Ağaçta Böyle Bir Veri YOK\n");
			}
		}

		else if (sec == 12) mirror(myroot);

		else if (sec == 13) {

			printf("\n Veriyi Giriniz: ");
			scanf("%d", &node);

			tmp = pathTotal(myroot, node);

			if (tmp)
			{
				printf("\n-- Yoldaki Değerlerin Toplamı Girdiğiniz Değere EŞİT --\n");
			}
			else
			{
				printf("\n-- Yoldaki Değerlerin Toplamı Girdiğiniz Değere Eşit DEĞİL! -- \n");
			}
		}
		else if (sec == 14) exit(0);
	}
}
