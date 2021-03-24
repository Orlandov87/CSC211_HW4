#include <iostream>
#include <string>
#include "Contact.h"

using std::string;

void askUser();
int terminalMenu();
int searchArray(string, string, int, Contact[]);
void searchContact(Contact[], int);
void displayAllContacts(Contact[], int);

int main() {

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

int searchArray(string f, string l, int size, Contact contacts[]) {
    int locationOfUser = -1;
    for(int i = 0; i < size; i++) {
        if ((f.compare(contacts[i].getFirstName()) == 0) && (l.compare(contacts[i].getLastName()) == 0)) {
            locationOfUser = i;
        } 
    }
    return locationOfUser;
}

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

void displayAllContacts(Contact contacts[], int size) {
    std::cout << " -- Contacts -- " << std::endl;
    for (int i = 0; i < size; i++) {
        contacts[i].printInfo();
        cout << std::endl;
    }
}
