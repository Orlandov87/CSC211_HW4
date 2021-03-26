#include <iostream>
#include <string>
#include "ContactBook.h"

using std::string;

int mainMenu();
void askUserForName(bool);
string fName, lName;

int main() {

    int userSelection;
    bool self = true;
    bool isRunning = true;
    std::cout << " Welcome to your new \"Contact Book\". " << std::endl;
    askUserForName(self);
    self = false;
    ContactBook myBook = ContactBook(lName, fName);
    std::cout << "\nThank you " + fName + ", your \"Contact Book\" as been created!\n" << std::endl;

    while(isRunning) {
        userSelection = mainMenu();

        switch (userSelection) {
            case 1: {
                // Add New Contact
                Contact newContact = Contact();
                newContact.inputData();
                myBook.addNewContact(newContact);
                break;
            }
            case 2:
                // Delete Old Contact
                askUserForName(self);
                myBook.deleteContact(fName, lName);
                break;
            case 3:
                askUserForName(self);
                myBook.displayContactInfo(fName, lName);
                // Display contact info
                break;
            case 4:
                // Update contact info
                askUserForName(self);
                myBook.updateContactInfo(fName, lName);
                break;
            case 5:
                // Display all contact
                myBook.displayAllContacts();
                break;
            case 6:
                // Exit program
                isRunning = false;
                break;
            default:
                std::cout << " *** NOT VALID INPUT ***" << std::endl;
        }
    }
}

void askUserForName(bool self) {
    string prefix;
    prefix = (self) ? "your " : "";
    std::cout << " Please enter "+prefix+"first name: ";
    std::cin >> fName;
    std::cout << " Please enter "+prefix+"last name: ";
    std::cin >> lName;
}

int mainMenu() {
    int selection = 0;

    std::cout << "\n------ MAIN MENU: ------" << std::endl;
    std::cout << "1: Add New Contact." << std::endl;
    std::cout << "2: Delete old Contacts." << std::endl;
    std::cout << "3: Display Contact Info." << std::endl;
    std::cout << "4: Update Contact Info." << std::endl;
    std::cout << "5: Display All Contacts." << std::endl;
    std::cout << "6: Exit Program." << std::endl;
    std::cout << "Please enter your option: ";
    std::cin >> selection;
    std::cout << std::endl;

    return selection;
}
