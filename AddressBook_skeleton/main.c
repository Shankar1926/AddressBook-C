/*
SHANKAR K - 25008_008

File: main.c

Description:
Main driver of the Address Book application. Presents a menu-based interface 
to perform operations like creating, searching, editing, deleting, and listing contacts.

Purpose:
- Initialize the address book and load data from file
- Handle user menu input and call respective functions
- Save contacts to file before exiting
*/


#include "contact.h"
int main() 
{
    int choice;

    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do 
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) 
	{
	    case 1:
		createContact(&addressBook);
		break;
	    case 2:
		searchContact(&addressBook);
		break;
	    case 3:
		editContact(&addressBook);
		break;
	    case 4:
		deleteContact(&addressBook);
		break;
	    case 5:
		listContacts(&addressBook);
		break;
	    case 6:
		printf("Saving and Exiting...\n");
		saveContactsToFile(&addressBook);
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);
    return 0;
}
