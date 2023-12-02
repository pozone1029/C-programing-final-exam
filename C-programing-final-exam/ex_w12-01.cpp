#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> 
#include <stdio.h>

typedef struct grade {
	int Chinese, Math, English, Computer_science;
} grade;
struct student {
	char name[10];
	int student_id;
	grade student_grade;
}stu[] = { {"Bob",309553045,0,10,20,30},{"Kevin",309551116,100,100,50,100},{"Dave",309551110,59,80,43,70},
	{"Steve",309552003,95,33,10,99},{"Stuart",309552052,80,40,70,80} };


int main() {
	int Chinese_t, Math_t, English_t, Computer_science_t;
	char C[10], M[10], E[10], CS[10];
	scanf("%s %d", C,&Chinese_t);
	scanf("%s %d", M,&Math_t);
	scanf("%s %d",E, &English_t);
	scanf("%s %d",CS, &Computer_science_t);
	printf("\nResult:\n");
	printf("Chinese:");
	for (int i = 0; i < 5; i++) {
		if (Chinese_t > stu[i].student_grade.Chinese) {
			printf("%d ", stu[i].student_id);
		}
	}
	printf("\n");
	printf("Math:");
	for (int i = 0; i < 5; i++) {
		if (Math_t > stu[i].student_grade.Math) {
			printf("%d ", stu[i].student_id);
		}
	}
	printf("\n");
	printf("English:");
	for (int i = 0; i < 5; i++) {
		if (English_t > stu[i].student_grade.English) {
			printf("%d ", stu[i].student_id);
		}
	}
	printf("\n");
	printf("Computer Science:");
	for (int i = 0; i < 5; i++) {
		if (Computer_science_t > stu[i].student_grade.Computer_science) {
			printf("%d ", stu[i].student_id);
		}
	}
	return 0;

}