/* Title : Roll number sorting system using bubble sort . create a program to organise student roll numbers .
            a) Accept roll numbers from user 
       b)Sort them in ascending order using bubble sort 
       c) Display sorted roll numbers
       d)Display Intermediates passes of sorting 
Name : Mali Somning dundappa
Roll no: C02078 "Div:B"
*/

#include <stdio.h>
int main() {
int roll[100], n = 0;
int choice, i, j, temp;
do {
printf("\n===== MENU =====\n");
printf("1. Insert Roll Numbers\n");
printf("2. Sort in ascending order & display intermediate\n");
printf("3. Display sorted roll number\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("\nEnter number of students: ");
scanf("%d", &n);
if (n <= 0 || n > 100) {
printf("Invalid number of students!\n");
n = 0;
break;
}
printf("Enter %d roll numbers:\n", n);
for (i = 0; i < n; i++) {
scanf("%d", &roll[i]);
}
printf("\nRoll numbers inserted successfully!\n");
break;
case 2:
if (n == 0) {
printf("\nNo roll numbers entered yet.\n");
} else {
printf("\n--- Sorting Process (Bubble Sort) ---\n");

for (i = 0; i < n - 1; i++) {

for (j = 0; j < n - i - 1; j++) {
if (roll[j] > roll[j + 1]) {
temp = roll[j];
roll[j] = roll[j + 1];
roll[j + 1] = temp;
}
}
printf("Pass %d: ", i + 1);
for (j = 0; j < n; j++) {
printf("%d ", roll[j]);
}
printf("\n");
}
printf("\nRoll numbers sorted successfully!\n");
}
break;
case 3:
if (n == 0) {
printf("\nNo roll numbers entered yet.\n");
} else {
printf("\nSorted Roll Numbers: ");

for (i = 0; i < n; i++) {
printf("%d ", roll[i]);
}

printf("\n");
}
break;
case 4:
printf("\nExiting program...\n");
break;
default:
printf("\nInvalid choice! Please try again.\n");
}
} while (choice != 4);
return 0;
}

*/Output :

student@TCOERCL-VI-20:~$ cc somning78.c
student@TCOERCL-VI-20:~$ ./a.out

===== MENU =====
1.Insert Roll Numbers
2.Sort in ascending order & display
3.intermediateDisplay sorted roll number
 4.Exit
Enter your choice: 1

Enter number of students: 12
Enter 12 roll numbers:
41
5
89
46
12
78
65
79
44
16
9
3

Roll numbers inserted successfully!

===== MENU =====
1.	Insert Roll Numbers
2.	Sort in ascending order & display intermediate
3.	Display sorted roll number
4.	Exit
Enter your choice: 2

--- Sorting Process (Bubble Sort) ---
Pass 1: 5 41 46 12 78 65 79 44 16 9 3 89 
Pass 2: 5 41 12 46 65 78 44 16 9 3 79 89 
Pass 3: 5 12 41 46 65 44 16 9 3 78 79 89 
Pass 4: 5 12 41 46 44 16 9 3 65 78 79 89 
Pass 5: 5 12 41 44 16 9 3 46 65 78 79 89 
Pass 6: 5 12 41 16 9 3 44 46 65 78 79 89 
Pass 7: 5 12 16 9 3 41 44 46 65 78 79 89 
Pass 8: 5 12 9 3 16 41 44 46 65 78 79 89 
Pass 9: 5 9 3 12 16 41 44 46 65 78 79 89 
Pass 10: 5 3 9 12 16 41 44 46 65 78 79 89 
Pass 11: 3 5 9 12 16 41 44 46 65 78 79 89 

Roll numbers sorted successfully!

===== MENU =====
1.	Insert Roll Numbers
2.	Sort in ascending order & display intermediate
3.	Display sorted roll number
4.	Exit
Enter your choice: 3 

Sorted Roll Numbers: 3 5 9 12 16 41 44 46 65 78 79 89 

===== MENU =====
1.	Insert Roll Numbers
2.	Sort in ascending order & display intermediate
3.	Display sorted roll number
4.	Exit
Enter your choice: 4

Exiting program…
/*
