/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:40:15 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 01:29:09 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string str;

class Animal {
public:
	Animal(const Animal &src); // copy constructor
	Animal &operator=(const Animal &src); // copy assingment operator
	virtual ~Animal(); // destructor

	Animal(str type);
	virtual void makeSound() const;

	str getType() const;

protected:
	Animal(); // default constructor
	str _type;
};
