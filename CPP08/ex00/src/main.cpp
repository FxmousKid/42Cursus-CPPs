/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:22:21 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/28 17:48:34 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iterator>
#include <vector>
#include <iostream>

int main(void)
{
	int arr[] = {1,2,3,4,5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));


	easyfind(vec, 3);
	try { easyfind(vec, -1); }
	catch (std::runtime_error& e) { std::cout << e.what() << std::endl; }
}
