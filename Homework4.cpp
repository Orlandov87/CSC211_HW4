#include <iostream>
#include <string>
#include "ContactBook.h"

using std::string;

//void askUser();
//int terminalMenu();
//int searchArray(string, string, int, Contact[]);
//void searchContact(Contact[], int);
//void displayAllContacts(Contact[], int);
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

/*
    bool keepAddingContacts = true, programIsRunning = true;
    char userAnswer = 'n';
    int userSelection, size = 0;
    Contact contacts[10];
    std::cout << "Please enter up to 10 contacts" << std::endl;

    do {
        Contact temp = Contact();
        temp.inputData();

        contacts[size] = temp;
        size++;

        cout << "Continue adding contacts: Yes (y), No(n): ";
        cin >> userAnswer;
        cout << std::endl;
        if(userAnswer == 'n' || size == 10) { keepAddingContacts = false; }
    } while(keepAddingContacts);

    //bool programIsRunning = true;
    do {
        userSelection = terminalMenu();

        if (userSelection == 1) {
            searchContact(contacts, size);
        } else if (userSelection == 2) {
            displayAllContacts(contacts, size);
        } else if (userSelection == 3) {
            programIsRunning = false;
        }
        userSelection = 0;
    } while(programIsRunning);
    return 0;
}
*/
/*
int terminalMenu() {
    int temp = 0;
    std::cout << "------ MAIN MENU: ------\n" << std::endl;
    std::cout << "1: Search for contact." << std::endl;
    std::cout << "2: Display all contacts." << std::endl;
    std::cout << "3: End the program." << std::endl;
    std::cout << "Please enter your option: ";
    std::cin >> temp;
    std::cout << std::endl;
    return temp;
}
*/

/* Copied over to ContactBook.cpp
int searchArray(string f, string l, int size, Contact contacts[]) {
    int locationOfUser = -1;
    for(int i = 0; i < size; i++) {
        if ((f.compare(contacts[i].getFirstName()) == 0) && (l.compare(contacts[i].getLastName()) == 0)) {
            locationOfUser = i;
        } 
    }
    return locationOfUser;
}
*/
/*
void searchContact(Contact contacts[], int size) {
    string fName, lName;
    //Search
    std::cout << "Please enter the first name to search: ";
    std::cin >> fName;
    std::cout << "Please enter the last name to search: ";
    std::cin >> lName;
    std::cout << std::endl;

    int locationOfUser = 0;
    locationOfUser = searchArray(fName, lName, size, contacts);
    if (locationOfUser > -1 ) {
        contacts[locationOfUser].printInfo();
    } else {
        std::cout << "** USER NOT FOUND **.\n" << std::endl;
    }
}
*/