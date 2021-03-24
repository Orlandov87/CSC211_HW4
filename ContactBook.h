#include <iostream> 
#include "Contact.h"

using std::string;

class ContactBook {
    public:
        ContactBook();
        ContactBook(string ownerLastName, string ownerFirstName);


    private:
        string ownerLastName;
        string ownerFirstName;
        Contact contactBook;

};