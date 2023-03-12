/* AVL Ağacı (AVL Tree)

- Dengeli İkili Arama Ağacı

*/

#include <stdio.h>
#include <locale.h> //Tüm Diller ve Karakter setleri bu kütüphane de yer alır. 


struct node {
	int data;
	struct node* left;  // Sol çocuğa işaretçi
	struct node* right; // Sağ çocuğa işaretçi
	int height;
};

typedef struct node AVLTREE;

AVLTREE* myroot = NULL;
AVLTREE* tmp;



//Fonksiyon Prototipleri

int height(AVLTREE*);
int balance(AVLTREE*);
int maxNumber(int, int);
AVLTREE* newNode(int);
AVLTREE* rightRotate(AVLTREE*);
AVLTREE* leftRotate(AVLTREE*);
AVLTREE* leftRightRotate(AVLTREE*);
AVLTREE* rightLeftRotate(AVLTREE*);
AVLTREE* insert(AVLTREE*, int);
void     preorder(AVLTREE*);
void     inorder(AVLTREE*);
void     postorder(AVLTREE*);
int      size(AVLTREE*);
AVLTREE* searchtree(AVLTREE*, int);
int      heightofTree(AVLTREE*);
int      minValue(AVLTREE*);
int      maxValue(AVLTREE*);
void     createmyroot();
AVLTREE* deleteNode(AVLTREE*, int);


int height(AVLTREE* n) // işaretlenen Düğümün Yüksekliği
{
	if (n == NULL)
		return 0;

	return n->height;
}

int maxNumber(int x, int y) { // İki Sayıdan En Büyüğü

	return (x > y) ? x : y;

	/*
	int maxValue(int x, int y) {

		if(x>=y)
			return x;
		else
			return y;

	}*/
}


/*
- AVL ağacındaki bir düğümün denge faktörü, sol alt ağacın yüksekliği ile o düğümün sağ alt ağacının yüksekliği arasındaki farktır.
- AVL ağaçlarınının sol ve sağ alt ağaçlar arasındaki yükseklik farkı en fazla 1'dir. (İç Ağaçlarda dahil)
*/

int balance(AVLTREE* n)
{
	if (n == NULL)
		return 0;

	return height(n->left) - height(n->right);
}



AVLTREE* newNode(int data) {

	AVLTREE* p;

	p = (AVLTREE*)malloc(sizeof(AVLTREE)); // Bellekten yer alıyor

	p->data = data;
	p->left = NULL;
	p->right = NULL;

	p->height = 1;

	return p; // Bu adresi geri dönderiyor.

}

/* Tek Döndürme (Single Rotation)

1- Sağa Döndürme (Right Rotate)
2- Sola Döndürme (Left  Rotate)
*/

AVLTREE* rightRotate(AVLTREE* node) {

	AVLTREE* temp = node->left;

	node->left = temp->right;

	temp->right = node;

	node->height = maxNumber(height(node->left), height(node->right)) + 1;

	temp->height = maxNumber(height(temp->left), height(temp->right)) + 1;

	return temp;
}

AVLTREE* leftRotate(AVLTREE* node) {

	AVLTREE* temp = node->right;

	node->right = temp->left;

	temp->left = node;

	node->height = maxNumber(height(node->left), height(node->right)) + 1;

	temp->height = maxNumber(height(temp->left), height(temp->right)) + 1;

	return temp;
}

AVLTREE* leftRightRotate(AVLTREE* node) {

	node->left = leftRotate(node->left);

	return rightRotate(node);
}


AVLTREE* rightLeftRotate(AVLTREE* node) {

	node->right = rightRotate(node->left);

	return leftRotate(node);
}


AVLTREE* insert(AVLTREE* node, int data) {

	if (node == NULL)
		return(newNode(data));


	if (data < node->data)
		node->left = insert(node->left, data);

	else if (data > node->data)
		node->right = insert(node->right, data);

	else
		return node;

	node->height = 1 + maxNumber(height(node->left), height(node->right));


	int blnc = balance(node);

	if (blnc > 1 && data < node->left->data)
		return rightRotate(node);

	if (blnc < -1 && data > node->right->data)
		return leftRotate(node);

	if (blnc > 1 && data > node->left->data)
		return leftRightRotate(node);

	if (blnc < -1 && data < node->right->data)
		return rightLeftRotate(node);

	return node;
}



void preorder(AVLTREE* root) { // Önce Kök

	// KÖK - SOL - SAĞ (Root-Left-Right) 

	if (root != NULL) {

		printf("%5d ", root->data);

		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(AVLTREE* root) {  // Kök Ortada

	// SOL - KÖK - SAĞ (Left-Root-Right)

	if (root != NULL) {

		inorder(root->left);

		printf("%5d ", root->data);

		inorder(root->right);
	}
}

void postorder(AVLTREE* root) {  // Kök Sonda

	// SOL - SAĞ - KÖK (Left-Right-Root)

	if (root != NULL) {

		postorder(root->left);
		postorder(root->right);

		printf("%5d ", root->data);
	}
}

int size(AVLTREE* root) { // Düğüm Sayılarını Veren Fonksiyon

	if (root == NULL)
		return 0;

	else
		return size(root->left) + 1 + size(root->right);

}

AVLTREE* minValueNode(AVLTREE* node)
{
	AVLTREE* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

int minValue(AVLTREE* root) { // Ağaçtaki Tüm Verilerden En Küçük Olan Değer
	if (root == NULL)
		return 0;

	while (root->left != NULL)
		root = root->left;

	return(root->data);
}

int maxValue(AVLTREE* root) { // Ağaçtaki Tüm Verilerden En Büyük Olan Değer

	if (root == NULL)
		return 0;

	while (root->right != NULL)
		root = root->right;

	return(root->data);
}


int heightofTree(AVLTREE* root) { // Bir Ağacın Yüksekliğini Bulmak (Kökün Yüksekliği)

	if (root == NULL)
		return -1;

	else {

		int leftHeight, rightHeight;

		leftHeight  = heightofTree(root->left);

		rightHeight = heightofTree(root->right);

		if (rightHeight > leftHeight)
			return rightHeight + 1;

		else
			return leftHeight + 1;
	}

}

AVLTREE* searchtree(AVLTREE* node, int data) { // İstenilen Veriyi Bulmak

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

AVLTREE* deleteNode(AVLTREE* root, int data) {

	/*1. Kısım: İkili Arama Ağacı silme işlemi ile aynı yapılır*/

	if (root == NULL)
	return root;

	if (data < root->data)
		root->left = deleteNode(root->left, data);

	else if (data > root->data)
		root->right = deleteNode(root->right, data);

	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			AVLTREE* temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;

			free(temp);
		}
		else
		{
			AVLTREE* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}


	/* 2. Kısım: AVL Ağacı Olması İçin Döndürme İşlemleri Yapılır*/

	if (root == NULL)
		return root;

	root->height = 1 + maxNumber(height(root->left), height(root->right));


	int blnc = balance(root);

	if (blnc > 1 && balance(root->left) >= 0)
		return rightRotate(root);

	if (blnc > 1 && balance(root->left) < 0)
		return leftRightRotate(root);

	if (blnc < -1 && balance(root->right) <= 0)
		return leftRotate(root);

	if (blnc < -1 && balance(root->right) > 0)
		return rightLeftRotate(root);

	return root;
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



int main() {

	setlocale(LC_ALL, "Turkish"); //Türkçe karakter yazdırmamızı sağlayan fonksiyon

	int sec = 0;
	int node;


	while (sec != 100)
	{

		printf(
			"\n ****************************************************\n"
			"   1 - Ağaç Oluştur / Ağaç Varsa Veri Ekle\n"
			"   2 - Preorder?\n"
			"   3 - Inorder?\n"
			"   4 - Postorder?\n"
			"   5 - Ağaçtan İstediğiniz Veriyi Bulma\n"
			"   6 - Ağacın Yüksekliği (Kökün Yüksekliği) Nedir?\n"
			"   7 - Ağacın En Küçük Değeri Nedir?\n"
			"   8 - Ağacın En Büyük Değeri Nedir?\n"
			"   9 - Ağacın Düğümlerinin Sayısı Nedir?\n"
			"  10 - Ağaçtan Veri Silmek\n"


		);

		printf("\n\n Seçiminizi Yapınız: ");
		scanf("%d", &sec);

		printf("\n");

		if (sec == 1) createmyroot();

		else if (sec == 2) preorder(myroot);
		else if (sec == 3) inorder(myroot);
		else if (sec == 4) postorder(myroot);
		else if (sec == 5) {
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

		else if (sec == 6) {
			printf("Ağacın Yüksekliği: %d\n", heightofTree(myroot));
		}

		else if (sec == 7) printf("%d", minValue(myroot));
		else if (sec == 8) printf("%d", maxValue(myroot));
		else if (sec == 9) printf("%d", size(myroot));
		else if (sec == 10) {

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
	}
}
