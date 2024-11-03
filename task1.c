#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;


void insert(Student stdnt[], int index) {
  printf("Enter Student ID for student %d: \n", index + 1);
  scanf("%d", &stdnt[index].id);
  getchar();
  printf("Enter name for student %d: \n", index + 1);
  scanf("%[^\n]s",stdnt[index].name);
  
  getchar();
  printf("Enter GPA for student %d: \n", index + 1);
  scanf("%f", &stdnt[index].gpa);
}

int main() {
    int n;
    printf("Enter number of students: \n");
    scanf("%d", &n);

    Student stdnt[n]; 

    for (int i = 0; i < n; i++) {
    insert(stdnt, i);
    }

    printf("Student:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", stdnt[i].id, stdnt[i].name, stdnt[i].gpa);
    }

    return 0;
}

