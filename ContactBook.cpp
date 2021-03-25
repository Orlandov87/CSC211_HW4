#include <iostream>
#include "ContactBook.h"

ContactBook::ContactBook() {
    ownerFirstName = "";
    ownerLastName = "";
    contactBook = new Contact[10];
    bookSize = 0;      
}

ContactBook::ContactBook(string lName, string fName) {
    ownerFirstName = fName;
    ownerLastName = lName;
    contactBook = new Contact[10];
    bookSize = 0;
}

string ContactBook::getOwnerLastName() { return ownerLastName; }
string ContactBook::getOwnerFirstName() { return ownerFirstName; }

void ContactBook::setOwnerLastName(string lName) {
    ownerLastName = lName;
}

void ContactBook::setOwnerFirstName(string fName) {
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

void ContactBook::deleteContact(string fName, string lName) {
    int index;
    index = searchContact(fName, lName);
    if (index == -1) {
        std::cout << "\n *** NO SUCH USER *** \n" << std::endl;
    } else {
        //std::memcpy(&contactBook[index], &contactBook[bookSize], sizeof(Contact));
        //contactBook[index];
        bookSize--;
        std::cout << "\n - USER DELETED - \n" << std::endl;
    }
}

void ContactBook::displayContactInfo(string fName, string lName) {
    int index = -1;
    index = searchContact(fName, lName);

    if (index == -1) {
        std::cout << "\n *** NO SUCH USER *** \n" << std::endl;
    } else {
        contactBook[index].printInfo();
    }
}

void ContactBook::updateContactInfo(string fName, string lName) {
    int index = -1;
    index = searchContact(fName, lName);
    if (index != -1 ) {
        contactBook[index].inputData();
    }
}
// DONE
void ContactBook::displayAllContacts() {
    if (bookSize == 0) {
        std::cout << "*** NO CONTACTS ***\n" << std::endl;
    } else {
        std::cout << " --- Contact Book --- " << std::endl;
        for (int i = 0; i < bookSize; i++) {
            contactBook[i].printInfo();
            cout << std::endl;
        }
    }
}

// Internal
int ContactBook::searchContact(string f, string l) {
    int index = -1;
    for(int i = 0; i < bookSize; i++) {
        if ((f.compare(contactBook[i].getFirstName()) == 0) && (l.compare(contactBook[i].getLastName()) == 0)) {
            index = i;
        } 
    }
    return index;
}
