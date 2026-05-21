#include <iostream>
#include <cctype>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"


// Зчитує від користувача непорожнє значення.
std::string getInput(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Field cannot be empty. " << prompt;
        getline(std::cin, input);
    }
    return input;
}



// Запускає цикл команд телефонної книги.
int main()
{
    Phonebook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Write a command: ";
        getline(std::cin, command);
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
