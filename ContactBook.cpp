#include <iostream>
#include "ContactBook.h"

ContactBook::ContactBook() {
    ownerFirstName = "";
    ownerLastName = "";
    contactBook[10];
    bookSize = 0;      
}

ContactBook::ContactBook(string lName, string fName) {
    ownerFirstName = fName;
    ownerLastName = lName;
    contactBook[10];
    bookSize = 0;
}

string ContactBook::getOwnerLastName() {
    return ownerLastName;
}

string ContactBook::getOwnerFirstName() {
    return ownerFirstName;
}

void ContactBook::setOwnerLastName(string lName) {
    ownerLastName = lName;
}

void ContactBook::setOwnerLastName(string fName) {
    ownerFirstName = fName;
}

int ContactBook::addNewContact(Contact newContact) {
    if(bookSize < 10) {
        contactBook[bookSize] = newContact;
        bookSize++;
        return 0;
    } else {
        return 1;
    }
}