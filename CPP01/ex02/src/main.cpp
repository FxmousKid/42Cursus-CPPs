/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:27:31 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 18:35:35 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef std::string str;

int main(void)
{
	str word = "HI THIS IS BRAIN";
	str *stringPTR = &word;
	str &stringREF = word;

	std::cout << "addr of word: " << &word << std::endl;
	std::cout << "addr of stringPTR: " << stringPTR << std::endl;
	std::cout << "addr of stringREF: " << &stringREF << std::endl;

	std::cout << "\n";

	std::cout << "value of word: " << word << std::endl;
	std::cout << "value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of stringREF: " << stringREF << std::endl;
	
	return (0);
}
