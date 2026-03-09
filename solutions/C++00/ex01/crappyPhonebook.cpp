#include <iostream>
#include <cctype>
#include "Phonebook.hpp"
#include "Contact.hpp"
using namespace std;


void addContact(const Contact& contact)
{
cout << "Contact added: " << contact.getLastName() << " " << contact.getFirstName() << " " << contact.getNickname() << " " << contact.getPhoneNumber() << " " << contact.getDarkestSecret() << endl;
}

int main()
{

    string darkestSecret;
    string phoneNumber;
    string nickname;
    string firstName;
    string lastName;
    string command;

    while(true)
    {
        cout << "Write a command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            cout << "Write last name: ";
            std::getline(std::cin, lastName);
            while (lastName.empty())
            {
                cout << "Field cannot be empty. Write last name: ";
                std::getline(std::cin, lastName);
            }
            cout << "Write first name: ";
            std::getline(std::cin, firstName);
            while (firstName.empty())
            {
                cout << "Field cannot be empty. Write first name: ";
                std::getline(std::cin, firstName);
            }
            cout << "Write nickname: ";
            std::getline(std::cin, nickname);
            while (nickname.empty())
            {
                cout << "Field cannot be empty. Write nickname: ";
                std::getline(std::cin, nickname);
            }
            cout << "Write phone number: ";
            std::getline(std::cin, phoneNumber);
            while (phoneNumber.empty())
            {
                cout << "Field cannot be empty. Write phone number: ";
                std::getline(std::cin, phoneNumber);
            }
            cout << "Write darkest secret: ";
            std::getline(std::cin, darkestSecret);
            while (darkestSecret.empty())
            {
                cout << "Field cannot be empty. Write darkest secret: ";
                std::getline(std::cin, darkestSecret);
            }


            Contact contact;
            contact.setLastName(lastName);
            contact.setFirstName(firstName);
            contact.setNickname(nickname);
            contact.setPhoneNumber(phoneNumber);
            contact.setDarkestSecret(darkestSecret);
            // if (contact.isFull(contact))
            // {
            //     cout << "Contact is full" << endl;
            // }
            // else
            // {
            //     cout << "Contact is not full" << endl;
            //     break;
            // }
            addContact(contact);
        }
        else if (command == "SEARCH")
        {

        }
        else if (command == "EXIT")
        {
            break;
        }
    }
    return (0);
}
