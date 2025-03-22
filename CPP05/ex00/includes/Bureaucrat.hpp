/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:38:00 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 17:09:13 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

#define MINGRADE 1
#define MAXGRADE 150

typedef std::string str;

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat(str name, int grade);

	void	incrementGrade(int incr = 1);
	void	decrementGrade(int decr = 1);

	class GradeTooHighException: public std::exception {
		virtual const char	*what()	const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char *what() const throw();
	};

	str			getName() const;
	int			getGrade() const;

private:
	const str name;
	int grade;
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bur);	

#define CHECK_GRADE_THROW(grade) \
	if (grade < MINGRADE) \
		throw Bureaucrat::GradeTooLowException(); \
	if (grade > MAXGRADE) \
		throw Bureaucrat::GradeTooHighException();
