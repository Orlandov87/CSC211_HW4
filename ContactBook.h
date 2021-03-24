#include <iostream> 
#include <string>
#include "Contact.h"

using std::string;

class ContactBook {
    private:
        string ownerLastName;
        string ownerFirstName;
        Contact* contactBook;
        int bookSize;
        int searchContact(string fName, string lName);

    public:
        ContactBook();
        ContactBook(string ownerLastName, string ownerFirstName);

        string getOwnerLastName();
        string getOwnerFirstName();
        
        void setOwnerLastName(string lName);
        void setOwnerFirstName(string fName);

        int addNewContact(Contact contact);
        void deleteContact(string fName, string lName);
        void displayContactInfo(string fName, string lName);
        void updateContactInfo(string fName, string lName);
        void displayAllContacts();
};