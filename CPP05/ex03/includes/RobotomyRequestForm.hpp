/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:36:32 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 21:45:13 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

class RobotomyRequestForm: public AForm {
public:
	RobotomyRequestForm(str target);
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
	virtual ~RobotomyRequestForm();
	
private:
	RobotomyRequestForm();
	virtual void executeConcrete() const;
};
