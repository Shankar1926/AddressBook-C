/*
SHANKAR K - 25008_008

File: delete_contact.c

Description:
Implements the logic to delete a contact from the address book based on search criteria.
Supports deletion by name, phone number, or email ID, with user confirmation.

Purpose:
- Search and match contact details based on user input
- Allow deletion of specific matches among multiple results
- Maintain contact order and count after deletion
*/

#include <stdio.h>
#include <string.h>
#include "contact.h"

//Pointer to the AddressBook structure, user choice
void delete_contact(AddressBook *addressBook, int choice)
{
    int arr[20];               // To store matching contact indices
    int arr_index = 0;
    int found = 0;

    dot_pattern();

    // Prompt user for search input
    switch (choice)
    {
        case 1: printf("Enter the Name to search: "); break;
        case 2: printf("Enter the Phone Number to search: "); break;
        case 3: printf("Enter the Email to search: "); break;
    }

    char input[50];
    scanf(" %49[^\n]", input);  // Read input string with whitespace support

    dot_pattern();
    printf("%-5s %-20s %-15s %30s\n", "S.No", "Name", "Phone Number", "Email Id");
    dot_pattern();

    // Search contacts and collect matches
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if ((choice == 1 && strcmp(input, addressBook->contacts[i].name) == 0) ||
            (choice == 2 && strcmp(input, addressBook->contacts[i].phone) == 0) ||
            (choice == 3 && strcmp(input, addressBook->contacts[i].email) == 0))
        {
            printf("%d(%d) %-20s %-15s %30s\n",
                   arr_index + 1, i + 1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            arr[arr_index++] = i;
            found = 1;
        }
    }

    dot_pattern();

    if (!found)
    {
        printf("Not Found\n");
        return;
    }

    // Prompt user to select which matched contact to delete
    printf("Enter which contact you want to delete [1 to %d] : ", arr_index);
    int user_index;
    scanf("%d", &user_index);

    if (user_index < 1 || user_index > arr_index) 
    {
        printf("Invalid selection. Please enter a number between 1 and %d.\n", arr_index);
        return;
    }
    // Calculate actual index in contact array
    int delete_index = arr[user_index - 1];

    char confirm;
    printf("Are you sure you want to delete this contact? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        // Shift remaining contacts forward to fill the gap
        for (int i = delete_index; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }

        // Decrease total contact count
        addressBook->contactCount--;

        // Show result and updated contact list
        dot_pattern();
        printf("%53s\n", "Contact deleted successfully");
        printf("Updated Contact List:\n");
        listContacts(addressBook);
    }
    else {
    printf("Deletion cancelled.\n");
}
}
