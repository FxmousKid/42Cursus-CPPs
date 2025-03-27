/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:49:25 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 14:58:15 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdlib>

int main(void)
{
	str	name = "abc";	
	int	id = 123456;

	Data d = {name, id};	
	std::cout << "original Data ptr:   " << &d << "\n";
	
	uintptr_t serialized_data = Serializer::serialize(&d);
	std::cout << "serialized data ptr: " << serialized_data << "\n";

	Data *deserialized_data = Serializer::deserialize(serialized_data);
	std::cout << "deserialized data ptr: " << deserialized_data << "\n";

	return (EXIT_SUCCESS);
}
