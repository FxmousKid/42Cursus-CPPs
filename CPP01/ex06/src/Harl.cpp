/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:57:05 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/26 02:23:09 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	return ;
}

Harl::~Harl() {
	return ;
}

void	Harl::info(void) {
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t";
	std::cout << "be asking for more!" <<std::endl;
}

void	Harl::debug(void) {
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you started working";
	std::cout << "here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR] This is unacceptable! I want to speak to";
	std::cout << "the manager now." << std::endl;
}
