#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char** name;
	Qualification_t* degrees;
} Student_t;

typedef struct {
	char** degree_name;
	float gpa;
	//int points;
	Level_t* years;
} Qualification_t;

typedef struct {
	int level;
	int num_course;
	Course_t* courses;
} Level_t;

typedef struct {
	char** course_name;
	int points;
	int num_assessments;
} Course_t;

void read_weights(float** array, int num_assessments);

float** weight_and_grade_array_allocator(int* number)
{
	int num_assessments = 0;
	printf("Enter the number of assessments: ");
	scanf("%d", &num_assessments);
	float** temp = calloc(2, sizeof(float*));
	temp[0] = calloc(num_assessments, sizeof(float));
	temp[1] = calloc(num_assessments, sizeof(float));
	read_weights(temp, num_assessments);
	*number = num_assessments;
	return temp;
}

void read_weights(float** array, int num_assessments)
{
	char answer;
	for (int i = 0; i < num_assessments; i++) {
		printf("Enter weighting for assessment #%d (as a percentage without the percentage sign): ", i);
		scanf("%f", &array[0][i]);
		wrong_entry:
		printf("Does this assessment have a grade [y/n]? ");
		scanf("%c", &answer);
		if (answer == 'y') {
			printf("What is the grade (as a percentage without the percentage sign)? ");
			scanf("%f", &array[1][i]);
		} else if (answer == 'n') {
			array[1][i] = -1.0;
		} else {
			printf("Please enter y/n\n");
			goto wrong_entry;
		}
	}

}

int main(void)
{
	int num = 0;
	float** temp;
	temp = weight_and_grade_array_allocator(&num);
	for (int i = 0; i < num; i++) {
		printf("%d: \t weighting: %.2f \t grade: %.2f\n", i, temp[0][i], temp[1][i]);
	}
	return 0;
}
