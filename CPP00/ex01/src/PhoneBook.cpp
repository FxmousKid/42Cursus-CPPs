#include "PhoneBook.hpp"
#include "Setup.hpp"
#include <cstdlib>
#include <iostream>

PhoneBook::PhoneBook() {
	contactCount = 0;
}

void	PhoneBook::addContact(void)
{ 
	Contact contact = Contact();
	str		string = "";

	std::cout << "Please enter the First Name of the Contact : ";
	std::getline(std::cin, string);
	while (string.empty()) {
		std::cout << "First Name cannot be empty. Please enter the First Name of the Contact : ";
		std::getline(std::cin, string);
	}
	contact.setFirstName(string);

	std::cout << "Please enter the Last Name of the Contact : ";
	std::getline(std::cin, string);
	while (string.empty()) {
		std::cout << "Last Name cannot be empty. Please enter the Last Name of the Contact : ";
		std::getline(std::cin, string);
	}
	contact.setLastName(string);

	std::cout << "Please enter the Nickname of the Contact : ";
	std::getline(std::cin, string);
	while (string.empty()) {
		std::cout << "Nickname cannot be empty. Please enter the Nickname of the Contact : ";
		std::getline(std::cin, string);
	}
	contact.setNickname(string);

	std::cout << "Please enter the Phone Number of the Contact : ";
	std::getline(std::cin, string);
	while (string.empty()) {
		std::cout << "Phone Number cannot be empty. Please enter the Phone Number of the Contact : ";
		std::getline(std::cin, string);
	}
	contact.setPhoneNumber(string);

	std::cout << "Please enter the Darkest Secret of the Contact : ";
	std::getline(std::cin, string);
	while (string.empty()) {
		std::cout << "Darkest Secret cannot be empty. Please enter the Darkest Secret of the Contact : ";
		std::getline(std::cin, string);
	}
	contact.setDarkestSecret(string);

	std::cout << GRN << "Contact added successfully !\n" << END << std::endl;
	
	if (this->contactCount == 8) {
		for (int i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i + 1];
		this->contactCount = 7;
	}
	this->contacts[this->contactCount] = contact;
	this->contactCount++;
}

str		get_n_space(int n)
{
	str	res = "";
	for (int i = 0; i < n; i++)
		res += " ";	
	return (res);
}

void	display_word(str word)
{
	int	len;

	len = word.length();
	if (len > 10)
		std::cout << word.substr(0, 9) << ".";
	else if (len <= 10)
		std::cout << get_n_space(10 - len) << word;
}

void	display_header(void)
{
	std::cout << "\n";
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << "\n";
	std::cout << "|";
	display_word("Index");
	std::cout << "|";
	display_word("First Name");
	std::cout << "|";
	display_word("Last Name");
	std::cout << "|";
	display_word("Nickname");
	std::cout << "|";
	std::cout << "\n";
}

void	display_row(Contact c, int index)
{
	str	string;
	
	std::cout << "|" << get_n_space(9) << index << "|";
	string = c.getFirstName();
	display_word(string);
	std::cout << "|";
	string = c.getLastName();
	display_word(string);
	std::cout << "|";
	string = c.getNickname();
	display_word(string);
	std::cout << "|";
}

void	display_chosen_contact(Contact c)
{
	std::cout << "First Name : " << c.getFirstName() << std::endl;
	std::cout << "Last Name : " << c.getLastName() << std::endl;
	std::cout << "Nickname : " << c.getNickname() << std::endl;
	std::cout << "Phone Number : " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << c.getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact(void)
{
	str	string;
	int	idx_choice;

	display_header();
	for (int i = 0; i < this->contactCount; i++) {
		display_row(this->contacts[i], i);
		std::cout << "\n";
	}
	for (int i = 0; i < 45; i++)
		std::cout << "-";
	std::cout << "\n\n";

	std::cout << "Please enter the index of the contact you want to display : ";
	std::getline(std::cin, string);
	while (string.empty()) {
		std::cout << "Please enter the index of the contact you want to display : ";
		std::getline(std::cin, string);
	}
	idx_choice = atoi(string.c_str());
	while (idx_choice < 0 || idx_choice >= this->contactCount) {
		std::cout << "Invalid index" << std::endl;
		std::cout << "Please enter the index of the contact you want to display : ";
		std::getline(std::cin, string);
		idx_choice = atoi(string.c_str());
	}
	display_chosen_contact(this->contacts[idx_choice]);
	std::cout << "\n";
}



