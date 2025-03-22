/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:47:11 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 22:03:51 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern;

typedef std::string str;
typedef AForm* (Intern::*Cf)(const str&) const;

class Intern {
public:
	Intern();
	Intern(Intern const &obj);
	Intern &operator=(Intern const &obj);
	~Intern();

	class FormNotFoundException: public std::exception {
		virtual const char* what() const throw();
	};

	AForm	*makeForm(const str& formName, const str& target) const;

private:

	static const std::string	names[3];
	static const Cf				forms[3];

	AForm*	ShrubberyCreation(const str& target) const;
	AForm*	RobotomyRequest(const str& target) const;
	AForm*	PresidentialPardon(const str& target) const;
};
