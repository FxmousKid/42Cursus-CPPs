/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:30:36 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 18:56:03 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

typedef std::string str;

class Form {
public:
	Form(str name, int req_grade_sign, int req_grade_exec);
	Form(Form const & src);
	~Form();
	Form & operator=(Form const & src);

	str		getName() const;
	bool	getSign() const;
	int		getReqGradeSign() const;
	int		getReqGradeExec() const;

	void	beSigned(const Bureaucrat& b);
	bool	isSigned() const;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		virtual const char* what() const throw();
	};


private:
	const str	_name;
	const int	_req_grade_sign;
	const int	_req_grade_exec;
	bool		_sign;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);
