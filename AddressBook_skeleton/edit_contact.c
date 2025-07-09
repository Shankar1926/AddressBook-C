/*
SHANKAR K - 25008_008

File: edit_contact.c

Description:
Provides functionality to search for a contact and edit its details.
Supports editing by name, phone number, or email address.

Purpose:
- Search contacts using selected criteria
- Validate input fields before editing
- Allow user to update specific fields of a selected contact
*/


#include <stdio.h>
#include <string.h>
#include "contact.h"
#include "validate.h"

/*
Function: edit_contact
-----------------------
Allows the user to search for a contact by Name, Phone, or Email and
edit one of its fields (name, phone number, or email address).

*/
//Pointer to the AddressBook structure containing all contacts , user choice
void edit_contact(AddressBook *addressBook, int choice)
{
    int arr[20];            // Stores matching indices
    int arr_index = 0, found = 0;

    // Prompt based on search type
    switch (choice)
    {
        case 1: printf("Enter the Name to search : "); break;
        case 2: printf("Enter the Phone number to search: "); break;
        case 3: printf("Enter the Email to search: "); break;
    }

    char input[50];
    scanf(" %[^\n]", input);  // Read user input

    // Validate the input if searching by phone or email
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

    // Header
    printf("%-5s %-20s %-15s %30s\n", "S.No", "Name", "Phone Number", "Email Id");
    dot_pattern();

    // Search for matching contacts
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if ((choice == 1 && strcmp(input, addressBook->contacts[i].name) == 0) ||
            (choice == 2 && strcmp(input, addressBook->contacts[i].phone) == 0) ||
            (choice == 3 && strcmp(input, addressBook->contacts[i].email) == 0))
        {
            printf("%d(%d) %-20s %-15s %30s\n\n",
                   arr_index + 1, i + 1,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);

            arr[arr_index++] = i;  // Store match index
            found = 1;
        }
    }

    dot_pattern();

    if (!found)
    {
        printf("Not Found\n");
    }
    else
    {
        // Ask user to pick one of the matching contacts
        printf("Enter which contact you want to edit [ 1 to %d ] : ", arr_index);
        int user_index;
        scanf("%d", &user_index);

        if (user_index < 1 || user_index > arr_index) 
        {
            printf("Invalid selection. Please enter a number between 1 and %d.\n", arr_index);
            return;
        }

        int edit_index = arr[user_index - 1];  // Get actual index

        // Ask user what they want to edit
        int edit_by;
        printf("1.Edit Name\n2.Edit Phone Number\n3.Edit Email Id\n");
        printf("Enter which detail you wish to edit : ");
        scanf("%d", &edit_by);

        // Edit Name
        if (edit_by == 1)
        {
            printf("Enter New Name : ");
            scanf(" %[^\n]", addressBook->contacts[edit_index].name);

            dot_pattern();
            printf("%43s\n", "Name updated!");
            dot_pattern();
        }
        // Edit Phone Number
        else if (edit_by == 2)
        {
            while (1)
            {
                char temp_number[20];
                printf("Enter New Number : ");
                scanf(" %[^\n]", temp_number);

                if (validate_phone_number(addressBook, temp_number, -1))
                {
                    strcpy(addressBook->contacts[edit_index].phone, temp_number);
                    dot_pattern();
                    printf("%43s\n", "Phone Number updated!");
                    dot_pattern();
                    break;
                }
            }
        }
        // Edit Email ID
        else
        {
            while (1)
            {
                char temp_mail[50];
                printf("Enter New Email Id : ");
                scanf(" %[^\n]", temp_mail);

                if (validate_email(addressBook, temp_mail, -1))
                {
                    strcpy(addressBook->contacts[edit_index].email, temp_mail);
                    dot_pattern();
                    printf("%43s\n", "Email Id updated!");
                    dot_pattern();
                    break;
                }
            }
        }

        // Display updated contact
        printf("%-5d %-20s %-15s %30s\n", edit_index + 1,
               addressBook->contacts[edit_index].name,
               addressBook->contacts[edit_index].phone,
               addressBook->contacts[edit_index].email);
        dot_pattern();
    }
}
