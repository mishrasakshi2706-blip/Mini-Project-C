#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    char department[30];
    int roomNo;
    float fees;
    char feeStatus[10];
};

struct Student s[MAX];
int count = 0;

// Add Student
void addStudent() {
    printf("\nEnter Student ID: ");
    scanf("%d", &s[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Department: ");
    scanf("%s", s[count].department);

    printf("Enter Room Number: ");
    scanf("%d", &s[count].roomNo);

    printf("Enter Hostel Fee: ");
    scanf("%f", &s[count].fees);

    printf("Enter Fee Status (Paid/Unpaid): ");
    scanf("%s", s[count].feeStatus);

    count++;
    printf("\nStudent Added Successfully!\n");
}

// View Students
void viewStudents() {
    int i;

    if(count == 0) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("ID\tName\t\tDepartment\tRoom\tFees\tStatus\n");
    printf("--------------------------------------------------------------------------------\n");

    for(i = 0; i < count; i++) {
        printf("%d\t%-15s\t%-10s\t%d\t%.2f\t%s\n",
               s[i].id, s[i].name, s[i].department,
               s[i].roomNo, s[i].fees, s[i].feeStatus);
    }
}

// Search Student
void searchStudent() {
    int id, i, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            printf("\nStudent Found\n");
            printf("ID: %d\n", s[i].id);
            printf("Name: %s\n", s[i].name);
            printf("Department: %s\n", s[i].department);
            printf("Room No: %d\n", s[i].roomNo);
            printf("Fees: %.2f\n", s[i].fees);
            printf("Status: %s\n", s[i].feeStatus);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nStudent Not Found!\n");
}

// Update Fee Status
void updateStudent() {
    int id, i;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            printf("Enter New Fee Status (Paid/Unpaid): ");
            scanf("%s", s[i].feeStatus);
            printf("\nRecord Updated Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

// Delete Student
void deleteStudent() {
    int id, i, j;

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            for(j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("\nRecord Deleted Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n========== HOSTEL MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Fee Status\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("\nThank You!\n");
                return 0;
            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
