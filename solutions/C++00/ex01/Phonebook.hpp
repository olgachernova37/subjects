#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <string>

class Phonebook
{
    private:
        Contact contacts[8];
        int index;
        int size;
        std::string truncate(const std::string& str) const;
        void displayTable() const;
        void displayContact(int idx) const;

    public:
        Phonebook();
        ~Phonebook();
        void addContact(const Contact& contact);
        void searchContact();
};

#endif
