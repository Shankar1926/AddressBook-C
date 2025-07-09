/*
SHANKAR K - 25008_008

File: search_contact.c

Description:
Implements search functionality for the Address Book system.
Allows users to search contacts by name, phone number, or email.

Purpose:
- Prompt user for search criteria
- Validate input (for phone and email)
- Display matching contacts in formatted output
*/


#include <stdio.h>
#include <string.h>
#include "contact.h"
#include "validate.h"


//addressBook Pointer to the AddressBook structure , User's choice
void search_contacts(AddressBook *addressBook, int choice)
{
    char input[50];
    int found = 0;     

    // Prompt based on user's search criteria
    switch (choice)
    {
        case 1:
            printf("Enter the name to search : ");
            break;
        case 2:
            printf("Enter the Phone Number to search : ");
            break;
        case 3:
            printf("Enter the Email Id to search : ");
            break;
    }

    // Read input value
    scanf(" %[^\n]", input);

    // Validate input for phone/email before proceeding
    if (choice == 2 && !validate_phone_number(addressBook, input, -2))
    {
        printf("Enter valid number to search\n");
        return;
    }
    else if (choice == 3 && !validate_email(addressBook, input, -2))
    {
        printf("Enter valid Email Id to search\n");
        return;
    }

    // Print header for result display
    dot_pattern();
    printf("%-5s %-20s %-15s %30s\n", "S.No", "Name", "Phone Number", "Email Id");
    dot_pattern();

    // Search and display matches
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if ((choice == 1 && strcmp(input, addressBook->contacts[i].name) == 0) ||
            (choice == 2 && strcmp(input, addressBook->contacts[i].phone) == 0) ||
            (choice == 3 && strcmp(input, addressBook->contacts[i].email) == 0))
        {
            // Print matching contact
            printf("%-5d %-20s %-15s %30s\n", i + 1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            found = 1;
        }
    }

    dot_pattern();

    // If no matches were found
    if (!found)
    {
        printf("No matching contact found.\n");
    }
}
