/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:57:17 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/26 02:22:42 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(str level)
{
	str lst[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlFunction funcs[4] =  {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (level == lst[i]) {
			(this->*funcs[i])();
			return ;
		}
	}
    std::cout << "[ Probably complaining about insignificant problems ]\n";
}

int main(void)
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("NOTHING");
		
	return (0);
}
