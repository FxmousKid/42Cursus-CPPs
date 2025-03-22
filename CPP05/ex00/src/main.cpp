/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:41:14 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 17:18:09 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bur("John", 1);
	
	std::cout << "Test 1" << std::endl;
	try {
		Bureaucrat bur2("John", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Test 2" << std::endl;
	try {
		Bureaucrat bur3("John", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Test 3" << std::endl;
	try {
		bur.incrementGrade(1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	Bureaucrat bur2("Joe", 150);
	std::cout << "Test 4" << std::endl;
	try {
		bur2.decrementGrade(1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}
