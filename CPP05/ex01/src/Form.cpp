/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:31:34 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 18:59:42 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(str name, int const gradeToSign, int const gradeToExecute) :
	_name(name),
	_req_grade_sign(gradeToSign),
	_req_grade_exec(gradeToExecute),
	_sign(false)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form&	Form::operator=(Form const &rhs) 
{
	if (this != &rhs)
		_sign = rhs._sign;
	return (*this);
}

Form::Form(Form const &src) :
	_name(src._name),
	_req_grade_sign(src._req_grade_sign),
	_req_grade_exec(src._req_grade_exec),
	_sign(src._sign) 
{
}

Form::~Form()
{
}

str	Form::getName() const { return (_name); }
int	Form::getReqGradeSign() const { return (_req_grade_sign); }
int	Form::getReqGradeExec() const { return (_req_grade_exec); }
bool	Form::isSigned() const { return (_sign); }


void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_req_grade_sign)
		throw Bureaucrat::GradeTooLowException();
	this->_sign = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "form [" << form.getName() << "]" 
	<< (form.isSigned() ? " is signed" : " is not signed") << " and requires grade " 
	<< form.getReqGradeSign() << " to sign and grade " << form.getReqGradeExec() 
	<< " to execute" << std::endl;
	return (os);
}
