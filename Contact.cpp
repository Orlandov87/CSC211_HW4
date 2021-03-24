#include <iostream>
#include <string>
#include <regex>
#include "Contact.h"

using std::cout;
using std::cin;
using std::regex;
using std::getline;
using std::ws;

Contact::Contact() {
    fName = "John";
    lName = "Doe";
    address = Address();
    phoneNumber = "12312312";
    email = "JohnDoe@me.com";
}

Contact::Contact(string fName, string lName, Address address, string phoneNumber, string email) {
    setFistName(fName);
    setLastName(lName);
    this->address = Address();
    this->address.input();

    setPhoneNumber(phoneNumber);
    setEmail(email);
}

bool Contact::validateEmail(string email) { 
    string regStr = "([a-zA-Z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)([.a-z]+)([a-z]+)";
    if (regex_match(email, regex(regStr))) {
        return true;
    }
    return false;
}

bool Contact::validatePhone(string phoneNumber) {
    if(regex_match(phoneNumber, regex("[0-9]+")) && phoneNumber.size() == 10) {
        return true;
    }
    return false;
}
// Accessors for all instance variable (class members)
string Contact::getFirstName() { return fName; }
string Contact::getLastName() { return lName; }
string Contact::getAddress() { return address.getHome(); }
string Contact::getPhoneNumber() { return phoneNumber; }
string Contact::getEmail() { return email; }

// Mutators functions
void Contact::setFistName(std::string fName) { this -> fName = fName; }
void Contact::setLastName(string lName) { this -> lName = lName; }
void Contact::setAddress() { address.input(); }

void Contact::setPhoneNumber(string phoneNumber) {
    if(validatePhone(phoneNumber)) {
        this -> phoneNumber = phoneNumber;
    } else {
        std::cout << "Invalid phone number format." ; 
    }
}

void Contact::setEmail(string email) {
    if (validateEmail(email)) {
        this -> email = email;
    } else {
        cout << "Invalid Email format.\n";
    }
}

void Contact::inputData() {
    string fName, lName, phoneNumber, email;
    bool validPhone = false, validEmail = false;
    //bool validPhone = false, validEmail = false;

    cout << "Please enter first name: ";
    cin >> fName;
    cout << "Please enter last name: ";
    cin >> lName;
    cout << "Please enter your address: ";
    address.input();
    //getline(cin >> ws, address);
    do {
        cout << "Please enter your phone number without any special characters: ";
        cin >> phoneNumber;

        if (validatePhone(phoneNumber)) {
            validPhone = true;
        } else {
            cout << "Not valid phone number\n";
        }
        
    } while(!validPhone);

    do {
        cout << "Please enter an Email: ";
        cin >> email;

        if (validateEmail(email)) {
            validEmail = true;
        } else {
            cout << "Not valid email.\n";
        }
    } while(!validEmail);

    this->fName = fName;
    this->lName = lName;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

void Contact::printInfo() {
    cout << fName + " " + lName + "\n";
    address.output();
    cout << phoneNumber << " " << email << std::endl;
}
