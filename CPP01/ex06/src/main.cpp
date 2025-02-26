/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:57:17 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/26 02:45:40 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(str level)
{
	str lst[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int idx = -1;
	for (int i = 0; i < 4; i++) {
		if (level == lst[i]) {
			idx = i;
		}
	}
	switch (idx)
	{
		case (0):
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case (1):
			this->info();
			this->warning();
			this->error();
			break;
		case (2):
			this->warning();
			this->error();
			break;
		case (3):
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return (1);
	}

	Harl().complain(str(argv[1]));
	return (0);
}
