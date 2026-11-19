/* Name: Somning mali
  roll:C02078
  Title : implement a hospital patient registration system using queue.
  simulate a paitent queue using queue dsa.
  1. add patient
  2.attend patient
  3.view patient
  4.check queue empty*/
  
#include <stdio.h>
struct patient
{
    int patient_id;
    char arrival_time[20];
};
struct patient queue[6];
int front = -1;
int rear = -1;
void addPatient()
{
    if (rear == 5)
    {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    printf("Enter Patient ID: ");
    scanf("%d", &queue[rear].patient_id);
    printf("Enter Arrival Time: ");
    scanf("%s", queue[rear].arrival_time);
    printf("Patient added successfully\n");
}
void attendPatient()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Patient ID: %d\n", queue[front].patient_id);
    printf("Arrival Time: %s\n", queue[front].arrival_time);
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}
void viewPatients()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("\nPatients in Queue:\n");
    for (i = front; i <= rear; i++)
    {
        printf("Patient ID: %d\n", queue[i].patient_id);
        printf("Arrival Time: %s\n", queue[i].arrival_time);
    }
}
void checkEmpty()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n--- Hospital Patient Registration ---\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addPatient();
                break;
            case 2:
                attendPatient();
                break;
            case 3:
                viewPatients();
                break;
            case 4:
                checkEmpty();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 5);
    return 0;
}

/* Output:
student@TCOERCL-VI-04:~$ cc Hospital78.c
student@TCOERCL-VI-04:~$ ./a.out

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 584
Enter Arrival Time: 10
Patient added successfully

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1   
Enter Patient ID: 5454
Enter Arrival Time: 11
Patient added successfully

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 5645
Enter Arrival Time: 12
Patient added successfully

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 5462
Enter Arrival Time: 01
Patient added successfully

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 5698
Enter Arrival Time: 2
Patient added successfully

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Enter Patient ID: 5896  
Enter Arrival Time: 3
Patient added successfully

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 1
Queue is Full

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 2
Patient ID: 584
Arrival Time: 10

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 3

Patients in Queue:
Patient ID: 5454
Arrival Time: 11
Patient ID: 5645
Arrival Time: 12
Patient ID: 5462
Arrival Time: 01
Patient ID: 5698
Arrival Time: 2
Patient ID: 5896
Arrival Time: 3

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 4
Queue is Not Empty

--- Hospital Patient Registration ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
Enter your choice: 5
Exiting...
student@TCOERCL-VI-04:~$ /*
