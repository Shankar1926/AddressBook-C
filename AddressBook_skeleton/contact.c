/*
SHANKAR K - 25008_008

File: contact.c

Description:
Implements core contact functionalities for the Address Book system.
Includes creation, searching, editing, deletion, listing, and file-based persistence.

Purpose:
- Manage user input and contact operations
- Validate phone numbers and email IDs
- Save contacts to a file and load them at startup
- Display formatted output for better user experience
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "validate.h"
#include "edit_contact.h"
#include "search_contact.h"
#include "delete_contact.h"

void dot_pattern()
{
        printf("-------------------------------------------------------------------------\n");
}
void listContacts(AddressBook *addressBook) 
{
	int i;
	dot_pattern();
	printf("%-5s %-20s %-15s %30s\n","S.No","Name","Phone Number","Email Id");
	dot_pattern();
	for( i = 0 ; i < addressBook->contactCount; i++)
	{
		printf("%-5d %-20s %-15s %30s\n", i+1 , addressBook->contacts[i].name,
                        addressBook->contacts[i].phone,addressBook->contacts[i].email);
		printf("\n");
	}
	dot_pattern();
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
        dot_pattern();
        printf("%43s\n","Create Contact");
        dot_pattern();

        char name[50];
        printf("Enter the name : ");
        scanf(" %49[^\n]", name);
        strcpy(addressBook->contacts[addressBook->contactCount].name , name );

        while(1)
        {
                char number[20];
	        printf("Enter Phone Number : ");
	        scanf(" %19[^\n]" , number);
                if(validate_phone_number( addressBook , number , -1))
                {
                        strcpy( addressBook->contacts[addressBook->contactCount].phone, number );
                        break;
                }
                else
                {
                        printf("Invalid phone number!!Try Again\n");
                }
        }
        while(1)
        {
                char mail[50];
                printf("Enter Email Id : ");
                scanf(" %49[^\n]" , mail);
                if(validate_email( addressBook , mail , -1 ))
                {
                        strcpy( addressBook->contacts[addressBook->contactCount].email,mail);
                        break;
                }
                else
                {
                        printf("Invalid Email Id!!Try Again\n");
                }
        }

        dot_pattern();  
        printf("%50s\n","Contact created successfully!!\n");
        dot_pattern();

        addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
        dot_pattern();
        printf("%43s\n","Search Contact");
        dot_pattern();

	int choice;
	do
	{
		printf("Search Menu\n");
		printf("1.search by Name\n");
		printf("2.search by Phone Number\n");
		printf("3.search by Email Id\n");
		printf("4.Exit to main Menu\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 ... 3: search_contacts(addressBook , choice );
				break;
			case 4: dot_pattern(); 
                                printf("%50s\n","Search completed and Exiting!!!");
                                dot_pattern();
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	}while(choice != 4);
}

void editContact(AddressBook *addressBook)
{
        dot_pattern();
        printf("%43s\n","Edit Contact");
        dot_pattern();

	int choice;
        do
        {
                printf("Edit Menu\n");
                printf("1.search by Name\n");
                printf("2.search by Phone Number\n");
                printf("3.search by Email Id\n");
                printf("4.Exit to main Menu\n");
                printf("Enter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1 ... 3 :  edit_contact( addressBook ,choice);
                                        break;
                        case 4: dot_pattern(); 
                                printf("%60s\n","Contact Edited Successfully and Exiting!!!");
                                dot_pattern();
                                break;
                        default:
                                printf("Invalid choice. Please try again.\n");
                }
        }while(choice != 4);

}

void deleteContact(AddressBook *addressBook)
{
        dot_pattern();
        printf("%43s\n","Delete Contact");
        dot_pattern();
        
	int choice;
	do
	{
		printf("Delete Menu\n");
                printf("1.search by Name\n");
                printf("2.search by Phone Number\n");
                printf("3.search by Email Id\n");
                printf("4.Exit to main Menu\n");
                printf("Enter your choice : ");
                scanf("%d",&choice);
		switch(choice)
		{
			case 1 ... 3 :  delete_contact( addressBook , choice );
                                        break;

			case 4: dot_pattern();
                                printf("%53s\n","Contact deleted successfully and exiting");
				dot_pattern();
                                break;
			default:
				printf("Invalid choice. please try again\n");
		}
	}while( choice != 4);
}
