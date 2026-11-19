/*Name : Somning mali
Roll no: C02078
Title: Binary Search Tree operation and traversals*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int rollNo;
    char name[50];
    struct Node *left, *right;
};

struct Node *createNode(int rollNo, const char *name) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->rollNo = rollNo;
    snprintf(newNode->name, sizeof(newNode->name), "%s", name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int rollNo, const char *name) {
    if (root == NULL)
        return createNode(rollNo, name);
    if (rollNo < root->rollNo)
        root->left = insert(root->left, rollNo, name);
    else if (rollNo > root->rollNo)
        root->right = insert(root->right, rollNo, name);
    else
        printf("Roll Number %d already exists!\n", rollNo);
    return root;
}

struct Node *findMin(struct Node *node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

struct Node *deleteNode(struct Node *root, int rollNo) {
    if (root == NULL)
        return NULL;
    if (rollNo < root->rollNo)
        root->left = deleteNode(root->left, rollNo);
    else if (rollNo > root->rollNo)
        root->right = deleteNode(root->right, rollNo);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->rollNo = temp->rollNo;
        snprintf(root->name, sizeof(root->name), "%s", temp->name);
        root->right = deleteNode(root->right, temp->rollNo);
    }
    return root;
}
struct Node *search(struct Node *root, int rollNo) {
    if (root == NULL || root->rollNo == rollNo)
        return root;
    if (rollNo < root->rollNo)
        return search(root->left, rollNo);
    return search(root->right, rollNo);
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
        inorder(root->right);
    }
}
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
    }
}
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int main(void) {
    struct Node *root = NULL, *found;
    int choice, rollNo;
    char name[50];
    while (1) {
        printf("\n--- Student BST Management System ---\n");
        printf("1.Add a new student record (Insert)\n");
        printf("2. Remove a student record (Delete)\n");
        printf("3.Search for a student record\n");
        printf("4. Display records (Inorder - Sorted)\n");
        printf("5.Display records (Preorder)\n");
        printf("6. Display records (Postorder)\n");
        printf("7.Exit from program ....\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
            break;
        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                if (scanf("%d", &rollNo) != 1)
                    goto end;
                printf("Enter Student Name: ");
                if (scanf("%49s", name) != 1)
                    goto end;
                root = insert(root, rollNo, name);
                break;
            case 2:
                printf("Enter Roll Number to remove: ");
                if (scanf("%d", &rollNo) != 1)
                    goto end;
                if (search(root, rollNo) == NULL)
                    printf("Student not found!\n");
                else {
                    root = deleteNode(root, rollNo);
                    printf("Record removed successfully.\n");
                }
                break;
            case 3:
                printf("Enter Roll Number to search: ");
                if (scanf("%d", &rollNo) != 1)
                    goto end;
                found = search(root, rollNo);
                if (found != NULL)
                    printf("Student Found -> Roll No: %d | Name: %s\n", found->rollNo, found->name);
                else
                    printf("Student with Roll No %d not found.\n", rollNo);
                break;
            case 4:
                printf("--- Inorder Traversal ---\n");
                inorder(root);
                break;
            case 5:
                printf("--- Preorder Traversal ---\n");
                preorder(root);
                break;
            case 6:
                printf("--- Postorder Traversal ---\n");
                postorder(root);
                break;
            case 7:
                goto end;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
end:
    freeTree(root);
    return 0;
}

*/ Outoput: 

student@TCOERCL-VI-04:~$ cc Binarysearch78.c
student@TCOERCL-VI-04:~$ ./a.out

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 1
Enter Roll Number: 10
Enter Student Name: somningmali

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 1
Enter Roll Number: 47
Enter Student Name: sakshi

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 1 
Enter Roll Number: 98
Enter Student Name: soham

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 1
Enter Roll Number: 6
Enter Student Name: raju

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 2
Enter Roll Number to remove: 6
Record removed successfully.

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 3
Enter Roll Number to search: 98
Student Found -> Roll No: 98 | Name: soham

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 4
--- Inorder Traversal ---
Roll No: 10 | Name: somningmali
Roll No: 47 | Name: sakshi
Roll No: 98 | Name: soham

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 5
--- Preorder Traversal ---
Roll No: 10 | Name: somningmali
Roll No: 47 | Name: sakshi
Roll No: 98 | Name: soham

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 6
--- Postorder Traversal ---
Roll No: 98 | Name: soham
Roll No: 47 | Name: sakshi
Roll No: 10 | Name: somningmali

--- Student BST Management System ---
1.Add a new student record (Insert)
2. Remove a student record (Delete)
3.Search for a student record
4. Display records (Inorder - Sorted)
5.Display records (Preorder)
6. Display records (Postorder)
7.Exit from program ....
Enter your choice: 7
student@TCOERCL-VI-04:~$ /*
