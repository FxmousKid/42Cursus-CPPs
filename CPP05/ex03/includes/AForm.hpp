/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:30:36 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 20:27:10 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

typedef std::string str;

class AForm {

public:
	AForm(AForm const & rhs);
	virtual ~AForm();
	AForm & operator=(AForm const & rhs);

	str		getName() const;
	int		getReqGradeSign() const;
	int		getReqGradeExec() const;
	str		getTarget() const;
	bool	getSign() const;

	void	beSigned(const Bureaucrat& b);
	bool	isSigned() const;

	void execute(Bureaucrat const & executor) const;

	class FormAlreadySignedException : public std::exception {
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		virtual const char* what() const throw();
	};

protected:
	AForm();
	AForm(str name, str target, int req_grade_sign, int req_grade_exec);
	virtual void executeConcrete() const = 0;

private:
	const str	_name;
	const int	_req_grade_sign;
	const int	_req_grade_exec;
	const str	_target;
	bool		_sign;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);
