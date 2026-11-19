/*Name: Somning Mali
Roll no: C02078
Title :Library Book Indexing useing hashtable
*/


#include <stdio.h>
#define TABLE_SIZE 10
#define EMPTY -1
int hashTable[TABLE_SIZE];
void insertBook(int key)
{
    int index = key % TABLE_SIZE;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int pos = (index + i) % TABLE_SIZE;
        if (hashTable[pos] == EMPTY)
        {
            hashTable[pos] = key;
            printf("Book ID inserted successfully.\n");
            return;
        }
        if (hashTable[pos] == key)
        {
            printf("Book ID already exists.\n");
            return;
        }
    }
    printf("Hash table is full.\n");
}
void searchBook(int key)
{
    int index = key % TABLE_SIZE;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int pos = (index + i) % TABLE_SIZE;
        if (hashTable[pos] == EMPTY)
        {
            printf("Book ID not found.\n");
            return;
        }
        if (hashTable[pos] == key)
        {
            printf("Book ID found at position %d.\n", pos);
            return;
        }
    }
    printf("Book ID not found.\n");
}
// Display Hash Table
void display()
{
    int i;
    printf("\n Hash Table:\n");
    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == EMPTY)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}
int main()
{
    int choice, id, i;
    for (i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
    do
    {
        printf("\n--- Library Management ---\n");
        printf("1. Insert Book ID\n");
        printf("2. Search Book ID\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                if (id < 0)
                    printf("Invalid Book ID.\n");
                else
                    insertBook(id);
                break;
            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                if (id < 0)
                    printf("Invalid Book ID.\n");
                else
                    searchBook(id);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}

/*Output: 

student@TCOERCL-VI-04:~$ touch BookId78.c
student@TCOERCL-VI-04:~$ cc BookId78.c
student@TCOERCL-VI-04:~$ ./a.out

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 54362
Book ID inserted successfully.

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 876
Book ID inserted successfully.

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 908
Invalid choice.

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 908
Book ID inserted successfully.

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 2
Enter Book ID to search: 876
Book ID found at position 6.

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 3

 Hash Table:
0 : EMPTY
1 : EMPTY
2 : 54362
3 : EMPTY
4 : EMPTY
5 : EMPTY
6 : 876
7 : EMPTY
8 : 908
9 : EMPTY

--- Library Management ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 4
Exiting program.
student@TCOERCL-VI-04:~$ */
