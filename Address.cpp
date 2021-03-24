#include <iostream>
#include "Address.h"


Address::Address() {
    home = "home";
    street = "Street";
    apt = "Apt";
    city = "city";
    state = "state";
    zip = "zip";
}

string Address::getHome() const {
    return home;
}

string Address::getStreet() const {
    return street;
}

string Address::getApt() const {
    return apt;
}

string Address::getCity() const {
    return city;
}

string Address::getState() const {
    return state;
}

string Address::getZip() const {
    return zip;
}


void Address::output() const {
    std::cout << "this is the output" << std::endl;
}

void Address::input() {
    std::cout << "Address of user." << std::endl;
}