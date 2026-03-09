#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{
    private:
    Contact contacts[8];
    int index;
    int size;

    public:
    Phonebook();
    ~Phonebook();

    void searchContact();

    protected:


};

#endif
