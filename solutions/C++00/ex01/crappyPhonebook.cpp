#include <iostream>
#include <cctype>
#include "Phonebook.hpp"
#include "Contact.hpp"
using namespace std;

string getInput(const string& prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    while (input.empty())
    {
        cout << "Field cannot be empty. " << prompt;
        getline(cin, input);
    }
    return input;
}



int main()
{
    Phonebook phonebook;
    string command;

    while (true)
    {
        cout << "Write a command: ";
        getline(cin, command);
        if (command == "ADD")
        {
            Contact contact;
            contact.setLastName(getInput("Write last name: "));
            contact.setFirstName(getInput("Write first name: "));
            contact.setNickname(getInput("Write nickname: "));
            contact.setPhoneNumber(getInput("Write phone number: "));
            contact.setDarkestSecret(getInput("Write darkest secret: "));
            phonebook.addContact(contact);
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
    return (0);
}
