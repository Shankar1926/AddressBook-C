/*
SHANKAR K - 25008_008

File: file.c

Description:
Handles file operations for the Address Book system using CSV format.
Ensures data persistence by saving and loading contact details.

Purpose:
- Save contact data to a file (`contact.csv`)
- Load existing contacts from file during program start
*/

#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp;
        fp = fopen("contact.csv","w");
        if( fp == NULL )
        {
                perror("Error : ");
                return;
        }
        fprintf(fp,"#%d\n",addressBook->contactCount);

        for( int i = 0 ; i < addressBook->contactCount ; i++ )
        {
            fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        fclose(fp);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp;
        fp = fopen("contact.csv","r");
        if( fp == NULL )
        {
                perror("Error : ");
                return;
        }
        fscanf(fp,"#%d\n",&addressBook->contactCount);

        for( int i = 0 ; i < addressBook->contactCount ; i++ )
        {
            fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
        fclose(fp);
}
