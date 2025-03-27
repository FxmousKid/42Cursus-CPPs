/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:35:16 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 22:37:05 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "iter.hpp"


int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print_item);
	std::cout << std::endl;

	int arr2[2] = {-1, -2};
	iter(arr2, 2, print_item);
	std::cout << std::endl;

	std::string arr3[] = {"one", "two", "three", "four", "five"};
	iter(arr3, 5, print_item);
	std::cout << std::endl;

	std::string arr4[2] = {"minus one", "minus two"};
	iter(arr4, 2, print_item);
	std::cout << std::endl;
		
	
	return (EXIT_SUCCESS);
}
