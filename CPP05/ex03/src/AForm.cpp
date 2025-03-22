/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:31:34 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 20:24:51 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(str name, const str target, int const gradeToSign, int const gradeToExecute) :
	_name(name),
	_req_grade_sign(gradeToSign),
	_req_grade_exec(gradeToExecute),
	_target(target),
	_sign(false)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm&	AForm::operator=(AForm const &rhs) 
{
	if (this != &rhs)
		_sign = rhs._sign;
	return (*this);
}

AForm::AForm(AForm const &rhs) :
	_name(rhs._name),
	_req_grade_sign(rhs._req_grade_sign),
	_req_grade_exec(rhs._req_grade_exec),
	_target(rhs._target),
	_sign(rhs._sign)
{
	checkGrade(rhs.getReqGradeSign());
	checkGrade(rhs.getReqGradeExec());
}

AForm::~AForm()
{
}

str	AForm::getName() const { return (_name); }
int	AForm::getReqGradeSign() const { return (_req_grade_sign); }
int	AForm::getReqGradeExec() const { return (_req_grade_exec); }
str	AForm::getTarget() const { return (_target); }
bool	AForm::isSigned() const { return (_sign); }


void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_req_grade_sign)
		throw Bureaucrat::GradeTooLowException();
	this->_sign = true;
}

void	AForm::execute(const Bureaucrat& executor) const 
{
	if (!_sign)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_req_grade_exec)
		throw Bureaucrat::GradeTooLowException();
	executeConcrete();
}

const char	*AForm::FormAlreadySignedException::what() const throw() {
	return ("Form has already been signed");
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return ("Form has not been signed yet");
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "form [" << form.getName() << "]" 
	<< (form.isSigned() ? " is signed" : " is not signed") << " and requires grade " 
	<< form.getReqGradeSign() << " to sign and grade " << form.getReqGradeExec() 
	<< " to execute" << std::endl;
	return (os);
}
