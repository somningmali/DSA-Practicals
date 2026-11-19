*/ Name:somning mali
roll: C02078
Title: Browser Navigation System Using Stack /*

#include <stdio.h>
#include <string.h>
#define max 50
int main(){
    char backStack[max][50];
    char forwardStack[max][50];
    char currentPage[50] = "Home";
    char page[50];
    int backTop = -1;
    int forwardTop = -1;
    int choice;
    do {
        printf("\n === Browser Navigation === \n");
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){ 
            case 1:
                printf("Enter the new page : ");
                scanf("%s", page);
                backTop++;
                strcpy(backStack[backTop], currentPage);
                strcpy(currentPage, page);
                forwardTop = -1;
                printf("Page visited successfully.\n");
                break;
            case 2:
                if (backTop == -1){
                    printf("No previous page available.\n");
                }
                else {
                    forwardTop++;
                    strcpy(forwardStack[forwardTop], currentPage);
                    strcpy(currentPage, backStack[backTop]);
                    backTop--;
                    printf("Back operation successful.\n");
                }
                break;
            case 3:
                if (forwardTop == -1){
                    printf("No forward page available.\n");
                }
                else {
                    backTop++;
                    strcpy(backStack[backTop], currentPage);
                    strcpy(currentPage, forwardStack[forwardTop]);
                    forwardTop--;
                    printf("Forward operation successful.\n");
                }
                break;
            case 4:
                printf("Current Page: %s\n", currentPage);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);
    return 0;
}

*/Output :

 === Browser Navigation ===
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice : 1
Enter the new page : instagram
Page visited successfully.

 === Browser Navigation ===
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice : 2
Back operation successful.

 === Browser Navigation ===
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice : 3
Forward operation successful.

 === Browser Navigation ===
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice : 4
Current Page: instagram

 === Browser Navigation ===
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Exit
Enter your choice : 5
/*
