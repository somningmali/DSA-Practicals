/*Practical :1 
Title:Write a program to store marks of store using marks of array
Name: Somning Mali 
Roll No.:C02078 “B”
*/

#include <stdio.h>
int main() {
    int marks[100];
    int size = 0;
    int choice;
    int key;
    int found = 0;
    int i,j,temp;
    do {
        printf("\n1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
        	printf("Enter the number of students: ");
		scanf("%d", &size);
		printf("Enter the marks:\n");
		for(i = 0; i < size; i++) 
		{
			scanf("%d", &marks[i]);
		}
        	    printf("Mark added!\n");
        	break;
        case 2:
            printf("\n--- Student Marks ---\n");
            for(i = 0; i < size; i++) {
                printf("Student %d: %d\n", i + 1, marks[i]);
            }
            break;
        case 3: {
            int delIndex;
            printf("Enter student number to delete: ");
            scanf("%d", &delIndex);
            for(i = delIndex - 1; i < size - 1; i++) {
                marks[i] = marks[i + 1];
            }
            size--;
            printf("Mark deleted!\n");
            break;
        }
        case 4:
            printf("Enter the marks to linear search: ");
            scanf("%d", &key);
            found = 0;
            for(i = 0; i < size; i++) {
                if(marks[i] == key) {
                    printf("Element found at %d\n", i + 1);
                    found = 1;
                    break;
                }
            }
            if(found == 0) {
                printf("Element not found\n");
            }
            break;
        case 5: 
            int low = 0;
            int high = size - 1;
            int mid;
            printf("Enter the marks to binary search: ");
            scanf("%d", &key);        
            //bubble sort
	     for(i = 0; i < size - 1; i++) {
                for(j = 0; j < size - i - 1; j++) {
                    if(marks[j] > marks[j + 1]) {
                        temp = marks[j];
                        marks[j] = marks[j + 1];
                        marks[j + 1] = temp;
                    }
                }
            }
            printf("Sorted marks: ");
            for(i = 0; i < size; i++) {
                printf("%d ", marks[i]);
            }
            printf("\n");
	    //binary search
            while(low <= high) {
                mid = (low + high) / 2;
                if(marks[mid] == key) {
                    printf("Marks %d found at %d\n", key, mid + 1);
                    found = 1;
                    break;
                }
                else if(marks[mid] < key) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            if(found == 0) {
                printf("Element not found\n");
            }
            break;
        case 6:
        break;

        default:
            printf("Invalid choice\n");
        }

    } while(choice != 6);
    printf("\nProgram Exited.\n");
    return 0;
}


/*Output

student@student:~$ cc Somning.c
student@student:~$ ./a.out

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 1
Enter the number of students: 4
Enter the marks:
98
78
67
90
Mark added!

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 2

--- Student Marks ---
Student 1: 98
Student 2: 78
Student 3: 67
Student 4: 90

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 3
Enter student number to delete: 1
Mark deleted!

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 2

--- Student Marks ---
Student 1: 78
Student 2: 67
Student 3: 90

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 4
Enter the marks to linear search: 67
Element found at 2

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 5
Enter the marks to binary search: 90
Sorted marks: 67 78 90 
Marks 90 found at 3

1. Insert  2. Display  3. Delete  4. Linear Search  5. Binary Search  6. Exit
Enter choice: 6

Program Exited.
/*
