#include <iostream> 
#include <string>
#include "Contact.h"

using std::string;

class ContactBook {
    private:
        string ownerLastName;
        string ownerFirstName;
        Contact contactBook[10];
        int bookSize;

    public:
        ContactBook();
        ContactBook(string ownerLastName, string ownerFirstName);

        string getOwnerLastName();
        string getOwnerFirstName();
        
        void setOwnerLastName(string lName);
        void setOwnerFirstname(string fName);

        int addNewContact(Contact contact);
        //MARK: Check Point
        //TODO: Define these functions
        void deleteContact();
        void displayContactInfo();
        void updateContactInfo();
        void displayAllContacts();

};