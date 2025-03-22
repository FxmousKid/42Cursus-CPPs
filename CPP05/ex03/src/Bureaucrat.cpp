/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:37:44 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 20:27:35 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

void	checkGrade(int grade) {
	if (grade < MINGRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MAXGRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(str name, int grade) : name(name) {
	checkGrade(grade);	
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : name(obj.name) {
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
		this->grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

void Bureaucrat::incrementGrade(int incr) 
{
	checkGrade(this->grade - incr);
	this->grade -= incr;
}

void Bureaucrat::decrementGrade(int decr) 
{
	checkGrade(this->grade + decr);
	this->grade += decr;
}

bool	Bureaucrat::signForm(AForm& form) const
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception& e) {
		std::cout << this->name << " cannot sign " << form.getName() << " because "
		<< e.what() << std::endl;
		return (false);
	}
	std::cout << this->name << " signs " << form.getName() << std::endl;
	return (true);
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try {
		form.execute(*this);
		std::cout << name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << name << " cannot execute " << form.getName() << " because "
		<< e.what() << std::endl;
	}
}

str Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bur) {
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (os);
}
