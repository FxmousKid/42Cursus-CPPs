/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:41:14 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 21:50:41 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	sectionTitle(const std::string& title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

Bureaucrat	burro("burro", 42);
Intern		interno;

void	testMake(const std::string& formName, const std::string& target) 
{
	sectionTitle(formName);

	AForm	*form = interno.makeForm(formName, target);

	std::cout << *form;
	burro.signForm(*form);
	burro.executeForm(*form);

	delete form;
}

int	main() {
	try {
		testMake("robotomy request", "Bender");
		testMake("presidential pardon", "lrocca");
		testMake("shrubbery creation", "home");
		testMake("not a form", "you");
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
