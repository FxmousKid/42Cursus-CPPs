/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:01:05 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 20:38:41 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(str target) :
	AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) :
	AForm("ShrubberyCreationForm", rhs.getTarget(), rhs.getReqGradeSign(), rhs.getReqGradeExec())
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::executeConcrete() const
{

	std::fstream	outfile;

	outfile.open((this->getTarget() + str("_shrubbery")).c_str(), std::fstream::out | std::fstream::trunc);
	if (!outfile.is_open() || outfile.bad())
	{
		std::cerr << "Error: could not open file for writing" << std::endl;
		return ;
	}
	
	outfile << "      /\\      " << std::endl;
	outfile << "     /\\*\\     " << std::endl;
	outfile << "    /\\O\\*\\    " << std::endl;
	outfile << "   /*/\\/\\/\\   " << std::endl;
	outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
	outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << "      ||      " << std::endl;
	outfile << std::endl;
	outfile.close();
}
