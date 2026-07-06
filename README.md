#define MAX 10
// declarations - these are the declarations of each function to work.
void addStudent(int id[], char name[][50], char major[][50], float gpa[], int credits[], int *total);
void searchById(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total);
void findByGPA(float gpa[], char name[][50], int total);
void findByMajor(char major[][50], char name[][50], int total);
void displayStudents(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total);

// main function - this is where all the code asks and runs.
int main()
{
    int choice;
    int total = 0;

    int id[MAX];
    char name[MAX][50];
    char major[MAX][50];
    float gpa[MAX];
    int credits[MAX];
// display - the display for the student registry.
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
            case 1: // if the user chooses '1' then it goes here and it calls the addStudent function below and breaks the code to exit the switch case. 
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
// the full functions - this is where the real magic happens. 

// add student - this function lets you add the students ID, Name, Major, GPA, Credits and also lets it add to the total list to be used later. 

void addStudent(int id[], char name[][50], char major[][50], float gpa[], int credits[], int *total)
{
    if(*total == MAX)
    {
        printf("Student list is full.\n"); // - MAX is 10, if it detects that its 10 then it will show this.
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

    (*total)++; // this is where it adds the student to the total, we used * so that we it can change the value to +1.

    printf("Student has been sucessfully added!\n");
}

// search by id - this function lets user search the student's information through their ID number. 
void searchById(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total)
{
    int search;

    printf("Enter student ID: ");
    scanf("%d", &search);

    for(int i = 0; i < total; i++) // total is used to know where we should limit it. 
    {
        if(id[i] == search) // if id is the same as search then it prints.
        {
            printf("\nID: %d\n", id[i]);
            printf("Name: %s\n", name[i]);
            printf("Major: %s\n", major[i]);
            printf("GPA: %.2f\n", gpa[i]);
            printf("Credits: %d\n", credits[i]);
            return;
        }
    }

    printf("Student not found.\n"); // failsafe
}

// search by gpa - this function lets the user search a list of students based on their GPAs. 
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
            found = 1; // it returns sucessfully
        }
    }
    if(found == 0) //failsafe
        printf("No students found.\n");
}

// search by major - this is the function that lets the user find the students under that major.
void findByMajor(char major[][50], char name[][50], int total)
{
    char search[50]; 
    int count = 0; 

    printf("Enter Major: ");
    scanf(" %[^\n]", search);

    for(int i = 0; i < total; i++)
    {
        if(strcmp(major[i], search) == 0) //strcmp is used to compare strings, since we are using strings on our major. 
        {
            printf("%s\n", name[i]);
            count++; // updates the count variable.
        }
    }

    printf("Total Students: %d\n", count); 
}
// display all students - this is the function that lets the user see all the students that hey have listed(MAX is 10).
void displayStudents(int id[], char name[][50], char major[][50], float gpa[], int credits[], int total)
{
    if(total == 0) // failsafe if the system finds 0 students in the system.
    {
        printf("No students added.\n");
        return;
    }
// if it doesn't find anything equal to zero then this code starts.
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
