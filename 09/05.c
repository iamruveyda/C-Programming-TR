/* Yer Değiştirme */

#include <stdio.h>
#include <locale.h>
#define MAX_SIZE 25

struct student {
	int  schoolnumber;
	char name[MAX_SIZE];
	char surname[MAX_SIZE];

};

void display(FILE*);

int main()
{
	setlocale(LC_ALL, "Turkish");

	struct student school;

	int  i;
	int  students;

	printf("Öğrenci Sayısını Giriniz: ");
	scanf("%d", &students);

	printf("\n");

	FILE* fptr;


	if ((fptr = fopen("student.txt", "w")) == NULL)
		printf("Dosya Açılamadı\n");

	else
	{
		rewind(fptr);

		//fprintf(fptr, "%-28s%-30s%10s\n", "Öğrencinin Okul Numarası", "Öğrencinin Soyadı", "Öğrencinin Adı");


		for (i = 0; i < students; ++i)
		{
			printf("%d. Öğrenci\n", i + 1);

			printf("Öğrencinin Okul Numarası:");
			scanf("%d", &school.schoolnumber);

			printf("Öğrencinin Adı:");
			scanf("%s", &school.name);

			printf("Öğrencinin Soyadı:");
			scanf("%s", &school.surname);


			printf("\n");


			fprintf(fptr, "%-10d%-16s%-16s\n", school.schoolnumber, school.name, school.surname);
		}

		fclose(fptr);
	}


	printf("\nÖğrenci Bilgileri Dosyaya Yazıldı\n");

	display(fptr);

	printf("\nYer Değiştirme Yapıldı\n");

	fclose(fptr);
}


void display(FILE* fptr)
{
	struct student tmp1 = {0,"",""};
	struct student tmp2 = {0,"",""};

	if ((fptr = fopen("student.txt", "r+")) == NULL)
		printf("Dosya Açılamadı\n");

	else
	{

		fseek(fptr, (0) * sizeof(struct student), SEEK_SET);


		fread(&tmp1, sizeof(struct student), 1, fptr);


		fseek(fptr, (2) * sizeof(struct student), SEEK_SET);


		fread(&tmp2, sizeof(struct student), 1, fptr);



		fseek(fptr, (0) * sizeof(struct student), SEEK_SET);


		fwrite(&tmp2, sizeof(struct student), 1, fptr);


		fseek(fptr, (2) * sizeof(struct student), SEEK_SET);


		fwrite(&tmp1, sizeof(struct student), 1, fptr);

	}
}
