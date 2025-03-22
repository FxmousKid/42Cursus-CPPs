/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:00:12 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 21:53:39 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm {

public:
	ShrubberyCreationForm(str target);
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	virtual ~ShrubberyCreationForm();

private:
	ShrubberyCreationForm();
	virtual void executeConcrete() const;
};
