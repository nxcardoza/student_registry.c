#include <stdio.h>
#include <string.h>

#define MAX 10
// declarations
void addStudent(int id[], char name[][50], char major[][50], float gpa[], int credits[], int *total);
void searchById(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total);
void findByGPA(float gpa[], char name[][50], int total);
void findByMajor(char major[][50], char name[][50], int total);
void displayStudents(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total);

// main function
int main()
{
    int choice;
    int total = 0;

    int id[MAX];
    char name[MAX][50];
    char major[MAX][50];
    float gpa[MAX];
    int credits[MAX];
// display
    do
    {
        printf("STUDENT REGISTRY\n\n");
        printf("1. Add a Student\n");
        printf("2. Search by ID\n");
        printf("3. Search by GPA\n");
        printf("4. Search by Major\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent(id, name, major, gpa, credits, &total);
                break;

            case 2:
                searchById(id, name, major, gpa, credits, total);
                break;

            case 3:
                findByGPA(gpa, name, total);
                break;

            case 4:
                findByMajor(major, name, total);
                break;

            case 5:
                displayStudents(id, name, major, gpa, credits, total);
                break;

            case 6:
                printf("Thank you for your service.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }

    } while(choice != 6);

    return 0;
}
// functions
// add student
void addStudent(int id[], char name[][50], char major[][50], float gpa[], int credits[], int *total)
{
    if(*total == MAX)
    {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &id[*total]);

    printf("Enter student Name: ");
    scanf(" %[^\n]", name[*total]);

    printf("Enter student Major: ");
    scanf(" %[^\n]", major[*total]);

    printf("Enter student GPA: ");
    scanf("%f", &gpa[*total]);

    printf("Enter student Credits: ");
    scanf("%d", &credits[*total]);

    (*total)++;

    printf("Student has been sucessfully added!\n");
}
// search by id
void searchById(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total)
{
    int search;

    printf("Enter student ID: ");
    scanf("%d", &search);

    for(int i = 0; i < total; i++)
    {
        if(id[i] == search)
        {
            printf("\nID: %d\n", id[i]);
            printf("Name: %s\n", name[i]);
            printf("Major: %s\n", major[i]);
            printf("GPA: %.2f\n", gpa[i]);
            printf("Credits: %d\n", credits[i]);
            return;
        }
    }

    printf("Student not found.\n");
}
// search by gpa
void findByGPA(float gpa[], char name[][50], int total)
{
    float search;
    int found = 0;

    printf("Enter minimum GPA: ");
    scanf("%f", &search);

    for(int i = 0; i < total; i++)
    {
        if(gpa[i] >= search)
        {
            printf("%s - %.2f\n", name[i], gpa[i]);
            found = 1;
        }
    }
    if(found == 0)
        printf("No students found.\n");
}
// search by major
void findByMajor(char major[][50], char name[][50], int total)
{
    char search[50];
    int count = 0;

    printf("Enter Major: ");
    scanf(" %[^\n]", search);

    for(int i = 0; i < total; i++)
    {
        if(strcmp(major[i], search) == 0)
        {
            printf("%s\n", name[i]);
            count++;
        }
    }

    printf("Total Students: %d\n", count);
}
// display all students
void displayStudents(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total)
{
    if(total == 0)
    {
        printf("No students added.\n");
        return;
    }

    for(int i = 0; i < total; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", id[i]);
        printf("Name: %s\n", name[i]);
        printf("Major: %s\n", major[i]);
        printf("GPA: %.2f\n", gpa[i]);
        printf("Credits: %d\n", credits[i]);
    }
}