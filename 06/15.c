/*
Pascal Üçgeni Oluşturma

// Özyinelemeli Fonksiyon (Recursive Function)

*/

#include <stdio.h>
#include <locale.h>  
#define MAX_SIZE 50

int fun(int i, int j) {

	if (i == j || j == 0)
		return 1;

	else
		return fun(i - 1, j) + fun(i - 1, j - 1);
}

int main() {

	setlocale(LC_ALL, "Turkish");

	int N, i, j, A[MAX_SIZE][MAX_SIZE];

	printf("Satır Sayısı İçin\n"
		   "Lütfen Bir Değer Giriniz: ");
	scanf("%d", &N);

	printf("\n");

	for (i = 0;i < N;i++) {

		for (j = 0;j <= i;j++) {
			A[i][j] = fun(i, j);
		}
	}

	for (i = 0;i < N;i++) {

		for (j = 0;j <= i;j++) {

			printf("%-6d", A[i][j]);

		}
		printf("\n");
	}
}