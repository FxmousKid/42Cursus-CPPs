/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:36:17 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 19:59:01 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(str target) :
	AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) :
	AForm("RobotomyRequestForm", rhs.getTarget(), rhs.getReqGradeSign(), rhs.getReqGradeExec())
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::executeConcrete() const
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	if (now->tm_sec % 2)
		std::cout << " has been successfully robotimized!" << std::endl;
	else
		std::cout << " had some problems and its robotomy failed!" << std::endl;
}
