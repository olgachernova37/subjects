#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Phonebook.hpp"
#include "Contact.hpp"

Phonebook::Phonebook()
{
    index = 0;
    size = 0;
}

Phonebook::~Phonebook()
{
}

std::string Phonebook::truncate(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Phonebook::displayTable() const
{
    std::cout << "|" << std::setw(10) << "INDEX";
    std::cout << "|" << std::setw(10) << "FIRST NAME";
    std::cout << "|" << std::setw(10) << "LAST NAME";
    std::cout << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << truncate(contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << truncate(contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << truncate(contacts[i].getNickname());
        std::cout << "|" << std::endl;
    }
}

void Phonebook::displayContact(int idx) const
{
    std::cout << "First name: " << contacts[idx].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[idx].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[idx].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[idx].getDarkestSecret() << std::endl;
}

void Phonebook::addContact(const Contact& contact)
{
    contacts[index] = contact;
    index = (index + 1) % 8;
    if (size < 8)
        size++;
    std::cout << "Contact added!" << std::endl;
}

void Phonebook::searchContact()
{
    if (size == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    displayTable();

    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty())
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            std::cout << "Invalid index." << std::endl;
            return;
        }
    }

    int idx = std::atoi(input.c_str());

    if (idx < 0 || idx >= size)
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }

    displayContact(idx);
}
