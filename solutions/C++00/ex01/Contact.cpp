#include <iostream>
#include <cctype>
#include "Phonebook.hpp"
#include "Contact.hpp"

// Ініціалізує порожній контакт.
Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}
// Знищує об'єкт контакту.
Contact::~Contact()
{
}
// Повертає ім'я.
std::string Contact::getFirstName() const
{
	return firstName;
}
// Повертає прізвище.
std::string Contact::getLastName() const
{
	return lastName;
}
// Повертає псевдонім.
std::string Contact::getNickname() const
{
	return nickname;
}
// Повертає номер телефону.
std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}
// Повертає найтемнішу таємницю.
std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

// Встановлює ім'я.
void Contact::setFirstName(const std::string &fName)
{
	firstName = fName;
}
// Встановлює прізвище.
void Contact::setLastName(const std::string &lName)
{
	lastName = lName;
}
// Встановлює псевдонім.
void Contact::setNickname(const std::string &nick)
{
	nickname = nick;
}
// Встановлює номер телефону.
void Contact::setPhoneNumber(const std::string &pNumber)
{
	phoneNumber = pNumber;
}
// Встановлює найтемнішу таємницю.
void Contact::setDarkestSecret(const std::string &dSecret)
{
	darkestSecret = dSecret;
}
// Перевіряє, чи всі поля заповнені.
bool isFull(Contact &contact)
{
	if (contact.getLastName() == "" || contact.getFirstName() == "" || contact.getNickname() == "" || contact.getPhoneNumber() == "" || contact.getDarkestSecret() == "")
	{
		return false;
	}
	return true;
}
