/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:37:44 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 17:16:25 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	checkGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
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
void Bureaucrat::incrementGrade(int incr) {
	checkGrade(this->grade - incr);
	this->grade -= incr;
}

void Bureaucrat::decrementGrade(int decr) {
	checkGrade(this->grade + decr);
	this->grade += decr;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

str Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

std::ostream &operator<<(std::ostream& os, Bureaucrat const& bur) {
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return (os);
}
