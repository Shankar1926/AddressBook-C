/*
SHANKAR K - 25008_008

File: validate.c

Description:
Implements validation functions for phone numbers and email addresses 
used in the Address Book system.

Purpose:
- Ensure correct format and uniqueness of phone numbers and email IDs
- Support different validation modes (e.g., creation, search, edit)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

/*
 Function: validate_phone_number
 -------------------------------
 It contains exactly 10 digits
 All characters are digits
 It's not already present in the address book 
*/

//addressBook Pointer to the address book,number input as string,function_skip
int validate_phone_number(AddressBook *addressBook, char *number, int function_skip)
{
    int length = strlen(number);

    // Check length
    if (length != 10) {
        printf("Phone number must contain 10 digits\n");
        return 0;
    }

    // Check if all characters are digits
    for (int i = 0; i < length; i++) {
        if (!isdigit(number[i])) 
        {
            printf("Phone number must contain only digits\n");
            return 0;
        }
    }

    // In search mode (-2), no need to check for duplicates
    if (function_skip == -2) {
        return 1;
    }

    // Check for duplicate number in the address book
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(number, addressBook->contacts[i].phone) == 0) {
            printf("Phone number Already Exist!!\n");
            return 0;
        }
    
    }

    return 1;
}

/*
Function: validate_email
------------------------
It ends with `.com`
Contains a properly placed '@' with alphanumeric characters on both sides
No spaces or uppercase letters
It's not already present in the address book (unless search/editing mode)
*/

//addressBook Pointer to the address book, mail input as string, function_skip
int validate_email(AddressBook *addressBook, char *mail, int function_skip)
{
    int found = 0;
    int len = strlen(mail);

    // Check if ".com" is at the end
    if (strcmp(&mail[len - 4], ".com") != 0) {
        printf(".com should be present at the end\n");
        return 0;
    }

    // Check for a valid '@' format with alphanumeric before/after
    for (int i = 0; i < len; i++) {
        if (i > 0 && mail[i] == '@') {
            if (isalnum(mail[i - 1]) && isalnum(mail[i + 1])) {
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Invalid email format. Missing or misused '@'.\n");
        return 0;
    }

    // Check for uppercase letters or spaces
    for (int i = 0; i < len; i++) {
        if (isupper(mail[i]) || mail[i] == ' ') {
            printf("Email contains space or uppercase letters\n");
            return 0;
        }
    }

    // In search mode (-2), skip duplicate checking
    if (function_skip == -2) {
        return 1;
    }

    // Check for duplicate email
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(mail, addressBook->contacts[i].email) == 0) {
            printf("Email Id Already Exist!!\n");
            return 0;
        }
    }

    return 1;
}
