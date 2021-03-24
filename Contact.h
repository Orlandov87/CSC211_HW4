#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include "Address.h"
using std::string;

class Contact {
    private: 
        string fName;
        string lName;
        Address address;
        string phoneNumber;
        string email;
        
        bool validateEmail(std::string email);
        bool validatePhone(std::string phonenumber);

    public: 
        Contact();
        Contact(string fName, string lName, Address address, string phoneNumber, string email);
        string getFirstName();
        string getLastName();
        string getAddress();
        string getPhoneNumber();
        string getEmail();
        void setFistName(string fName);
        void setLastName(string lName);
        void setAddress();
        void setPhoneNumber(string phoneNumber);
        void setEmail(string email);
        void inputData();
        void printInfo();
};
#endif