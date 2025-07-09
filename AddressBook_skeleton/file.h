/*
SHANKAR K - 25008_008

File: file.h

Description:
Declares file operation functions for saving and loading contact data 
to and from a CSV file for the Address Book system.

Purpose:
- Provide prototypes to handle file-based persistence
- Ensure contacts are retained across program runs
*/


#ifndef FILE_H
#define FILE_H

#include "contact.h"

void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
