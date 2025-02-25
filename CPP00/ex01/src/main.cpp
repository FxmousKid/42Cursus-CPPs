/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:07:50 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:08 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Setup.hpp"

void	eval(str string, PhoneBook &pb)
{
	if (string == "ADD") {
		pb.addContact();	
	}
	else if (string == "SEARCH") {
		pb.searchContact();
}
	else if (string == "EXIT") {
		(void)pb;
	}
	else {
		std::cout << string << " is not a valid command" << std::endl;
	}
}

void	repl(void)
{
	str	string;
	PhoneBook phoneBook;

	phoneBook = PhoneBook();
	while (string != "EXIT")
	{
		std::cout << "Please input a command : " ;
		std::getline(std::cin, string);
		if (string.empty())
			continue ;
		eval(string, phoneBook);
	}
}

int main(void)
{

	repl();
	return (0);
}
