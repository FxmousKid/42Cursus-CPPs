/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:38:00 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 20:27:19 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "AForm.hpp"
class AForm;

#define MINGRADE 1
#define MAXGRADE 150

typedef std::string str;

class Bureaucrat {

public:
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat(str name, int grade);

	void		incrementGrade(int incr = 1);
	void		decrementGrade(int decr = 1);
	bool		signForm(AForm& form) const;
	void		executeForm(const AForm& form) const;

	str			getName() const;
	int			getGrade() const;


public:
	class GradeTooHighException: public std::exception {
		virtual const char	*what()	const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char *what() const throw();
	};

private:
	Bureaucrat();

private:
	const str name;
	int grade;
};

void	checkGrade(int grade);
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
