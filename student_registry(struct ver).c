#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    int studentId;
    char studentName[50];
    char studentMajor[50];
    float studentGpa;
    int studentCredits;
} Student;

// variables
void addStudent(Student list[], int *total);
void searchById(Student list[], int total);
void findByGPA(Student list[], int total);
void findByMajor(Student list[], int total);
void displayStudents(Student list[], int total);

int main()
{
    int choice;
    int total = 0;
    Student list[MAX];

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
                addStudent(list, &total);
                break;

            case 2:
                searchById(list, total);
                break;

            case 3:
                findByGPA(list, total);
                break;

            case 4:
                findByMajor(list, total);
                break;

            case 5:
                displayStudents(list, total);
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

// add student
void addStudent(Student list[], int *total)
{
    if(*total == MAX)
    {
        printf("Student list is full.\n");
        return;
    }

    Student s; // build it locally, then store

    printf("Enter student ID: ");
    scanf("%d", &s.studentId);

    printf("Enter student Name: ");
    scanf(" %[^\n]", s.studentName);

    printf("Enter student Major: ");
    scanf(" %[^\n]", s.studentMajor);

    printf("Enter student GPA: ");
    scanf("%f", &s.studentGpa);

    printf("Enter student Credits: ");
    scanf("%d", &s.studentCredits);

    list[*total] = s;   // struct assignment copies the whole thing
    (*total)++;

    printf("Student has been sucessfully added!\n");
}

// search by id
void searchById(Student list[], int total)
{
    int search;

    printf("Enter student ID: ");
    scanf("%d", &search);

    for(int i = 0; i < total; i++)
    {
        if(list[i].studentId == search)
        {
            printf("\nID: %d\n", list[i].studentId);
            printf("Name: %s\n", list[i].studentName);
            printf("Major: %s\n", list[i].studentMajor);
            printf("GPA: %.2f\n", list[i].studentGpa);
            printf("Credits: %d\n", list[i].studentCredits);
            return;
        }
    }

    printf("Student not found.\n");
}

// search by gpa
void findByGPA(Student list[], int total)
{
    float search;
    int found = 0;

    printf("Enter minimum GPA: ");
    scanf("%f", &search);

    for(int i = 0; i < total; i++)
    {
        if(list[i].studentGpa >= search)
        {
            printf("%s - %.2f\n", list[i].studentName, list[i].studentGpa);
            found = 1;
        }
    }
    if(found == 0)
        printf("No students found.\n");
}

// search by major
void findByMajor(Student list[], int total)
{
    char search[50];
    int count = 0;

    printf("Enter Major: ");
    scanf(" %[^\n]", search);

    for(int i = 0; i < total; i++)
    {
        if(strcmp(list[i].studentMajor, search) == 0)
        {
            printf("%s\n", list[i].studentName);
            count++;
        }
    }

    printf("Total Students: %d\n", count);
}

// display all students
void displayStudents(Student list[], int total)
{
    if(total == 0)
    {
        printf("No students added.\n");
        return;
    }

    for(int i = 0; i < total; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", list[i].studentId);
        printf("Name: %s\n", list[i].studentName);
        printf("Major: %s\n", list[i].studentMajor);
        printf("GPA: %.2f\n", list[i].studentGpa);
        printf("Credits: %d\n", list[i].studentCredits);
    }
}
