/*
SHANKAR K - 25008_008

File: contact.h

Description:
Defines the structures and function prototypes for the Address Book system.
Handles creating, searching, editing, deleting, and listing contacts.
Supports file operations to ensure data persistence.

Purpose:
- Manage contact details
- Provide function declarations
- Enable saving/loading contact data
*/

#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>

#define MAX_CONTACTS 100

typedef struct Contact{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void dot_pattern();
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

#endif
