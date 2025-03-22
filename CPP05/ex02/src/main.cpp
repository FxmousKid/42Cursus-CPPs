/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:41:14 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 20:31:58 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/*
void testCPP05Ex02() {
    std::cout << "\n========== TESTING FORMS ==========\n" << std::endl;

    // Testing Bureaucrats with different grades
    try {
        std::cout << "--- Creating Bureaucrats ---" << std::endl;
        Bureaucrat highRank("Director", 1);        // Highest rank
        Bureaucrat midRank("Manager", 70);         // Middle rank 
        Bureaucrat lowRank("Intern", 150);         // Lowest rank
        
        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;

        // Testing ShrubberyCreationForm (sign: 145, exec: 137)
        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        ShrubberyCreationForm shrubForm("garden");
        std::cout << shrubForm << std::endl;
        
        // Low rank bureaucrat should be able to sign but not execute
        std::cout << "Low rank trying to sign and execute:" << std::endl;
        lowRank.signForm(shrubForm);
        lowRank.executeForm(shrubForm);
        
        // Mid rank should be able to execute after it's signed
        std::cout << "Mid rank trying to execute:" << std::endl;
        midRank.executeForm(shrubForm);

        // Testing RobotomyRequestForm (sign: 72, exec: 45)
        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        RobotomyRequestForm robotForm("subject");
        std::cout << robotForm << std::endl;
        
        // Low rank can't sign
        std::cout << "Low rank trying to sign:" << std::endl;
        lowRank.signForm(robotForm);
        
        // Mid rank can sign but not execute
        std::cout << "Mid rank trying to sign and execute:" << std::endl;
        midRank.signForm(robotForm);
        midRank.executeForm(robotForm);
        
        // High rank can execute
        std::cout << "High rank trying to execute:" << std::endl;
        highRank.executeForm(robotForm);
        
        // Testing PresidentialPardonForm (sign: 25, exec: 5)
        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        PresidentialPardonForm pardonForm("citizen");
        std::cout << pardonForm << std::endl;
        
        // Mid rank can't sign
        std::cout << "Mid rank trying to sign:" << std::endl;
        midRank.signForm(pardonForm);
        
        // High rank can sign and execute
        std::cout << "High rank trying to sign and execute:" << std::endl;
        highRank.signForm(pardonForm);
        highRank.executeForm(pardonForm);
        
        // Test executing without signing
        std::cout << "\n--- Testing execution without signature ---" << std::endl;
        PresidentialPardonForm unsignedForm("criminal");
        std::cout << "High rank trying to execute unsigned form:" << std::endl;
        highRank.executeForm(unsignedForm);
        
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n========== TESTS COMPLETED ==========\n" << std::endl;
}

int	main() {
	testCPP05Ex02();
	return (0);
}
*/


void	sectionTitle(const std::string& title) {
	std::cout	<< std::endl
				<< "*** " << title << " ***"
				<< std::endl << std::endl;
}

void	testForm(const Bureaucrat& bureaucrat, AForm& form) {
	std::cout << form;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int	main() {
	Bureaucrat	burro("burro", 1);
	Bureaucrat	burretto("burretto", 42);
	std::cout << burro << burretto;

	try {
		{
			sectionTitle("shrubbery creation");
			ShrubberyCreationForm form("home");
			testForm(burro, form);
		}
		{
			sectionTitle("robotomy request");
			RobotomyRequestForm form("Bender");
			testForm(burro, form);
		}
		{
			sectionTitle("presidential pardon");
			PresidentialPardonForm form("lrocca");
			testForm(burro, form);
		}
		PresidentialPardonForm form("lrocca");
		{
			sectionTitle("execute unsigned form");
			std::cout << form;
			burro.executeForm(form);
		}
		{
			sectionTitle("too low to execute");
			burro.signForm(form);
			burretto.executeForm(form);
		}
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
