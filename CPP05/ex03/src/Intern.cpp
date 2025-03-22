/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:32:27 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 21:50:01 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const str Intern::names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const Cf Intern::forms[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

Intern::Intern() {
}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

AForm*	Intern::ShrubberyCreation(const str &target) const {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::RobotomyRequest(const str &target) const {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::PresidentialPardon(const str &target) const {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const str& form, const str& target) const {
	for (int i = 0; i < 3; i++)
		if (names[i] == form)
			return (this->*(forms[i]))(target);
	throw FormNotFoundException();
}

const char*	Intern::FormNotFoundException::what() const throw() {
	return "<Intern> Form not found! May I bring you a coffee instead?";
}
