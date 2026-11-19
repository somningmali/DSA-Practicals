/*Title:-Dynamic Contact List Management Using Linked List
Roll No:-C02078 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct contact
{
char name[30];
long int phone;
struct contact *next;
};
int main()
{
struct contact *head = NULL;
struct contact *newnode, *temp, *prev;
char name[30];
int choice;
do
{
printf("\n==== MENU ====");
printf("\n1.Insert New Contact :\n2.Insert New Contact At End :\n3.Delete a Contact Using Name :\n4.Search Contact :\n5.Display All Contacts :\n6.Exit");
printf("\nEnter Your Choice : ");
scanf("%d",&choice);
switch (choice)
{
case 1: // Insert at beginning
newnode=(struct contact*)malloc(sizeof(struct contact));
printf("Enter name: ");
scanf("%s",newnode->name);
printf("Enter phone: ");
scanf("%ld",&newnode->phone);
newnode->next=head;
head=newnode;
break;
case 2: // Insert New Contact At End
newnode = (struct contact*)malloc(sizeof(struct contact));
printf("Enter name: ");
scanf("%s",newnode->name);
printf("Enter phone: ");
scanf("%ld",&newnode->phone);
newnode->next=NULL;
if (head==NULL)
{
head=newnode;
}
else
{
temp=head;
while (temp->next != NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
break;
case 3: // Delete a Contact Using Name
printf("Enter name to delete: ");
scanf("%s",name);
temp=head;
prev=NULL;
while (temp != NULL && strcmp(temp->name, name) != 0)
{
prev = temp;
temp = temp->next;
}
if (temp == NULL)
{
printf("Contact not found.\n");
}
else
{
if (prev == NULL)
{
head = temp->next;
}
else
{
prev->next = temp->next;
}
free(temp);
printf("Contact deleted successfully.\n");
}
break;
case 4: // Search Contact
printf("Enter name to search: ");
scanf("%s",name);
temp = head;
while (temp != NULL)
{
if (strcmp(temp->name,name) == 0)
{
printf("Contact Found\n");
printf("Name:%s\n", temp->name);
printf("Phone:%ld\n", temp->phone);
break;
}
temp = temp->next;
}
break;
case 5: // Display Contacts
temp = head;
while (temp != NULL)
{
printf("Name:%s\n", temp->name);
printf("Phone:%ld\n", temp->phone);
temp = temp->next;
}
break;
case 6: // Exiting Program
printf("Exit\n");
break;
}
} while (choice != 6);
}


/* output : 

student@TCOERCL-VI-11:~$ cc contact.c
student@TCOERCL-VI-11:~$ ./a.out
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 1
Enter name: Aditya
Enter phone: 3456399821
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 1
Enter name: Rohan
Enter phone: 2659283252
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 5
Name:Rohan
Phone:2659283252
Name:Aditya
Phone:3456399821
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 2
Enter name: Rahul
Enter phone: 8957691223
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 5
Name:Rohan
Phone:2659283252
Name:Aditya
Phone:3456399821
Name:Rahul
Phone:8957691223
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 3
Enter name to delete: Rahul
Contact deleted successfully.
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 5
Name:Rohan
Phone:2659283252
Name:Aditya
Phone:3456399821
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 4
Enter name to search: Aditya
Contact Found
Name:Aditya
Phone:3456399821
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 5
Name:Rohan
Phone:2659283252
Name:Aditya
Phone:3456399821
==== MENU ====
1.Insert New Contact :
2.Insert New Contact At End :
3.Delete a Contact Using Name :
4.Search Contact :
5.Display All Contacts :
6.Exit
Enter Your Choice : 6
Exit
*/
