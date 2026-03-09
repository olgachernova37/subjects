#include <iostream>
#include <cctype>
#include "Phonebook.hpp"
#include "Contact.hpp"
using namespace std;

Contact::Contact() {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
	full = false;
}
Contact::~Contact() {
}
std::string Contact::getFirstName() const {
    return firstName;
}
std::string Contact::getLastName() const {
    return lastName;
}
std::string Contact::getNickname() const {
    return nickname;
}
std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}
std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
bool Contact::isFull() const {
    return full;
}

