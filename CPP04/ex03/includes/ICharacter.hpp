/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:50:10 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 14:59:39 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

typedef std::string str;

class ICharacter {
public:

	virtual ~ICharacter();
	virtual const str& getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(AMateria *m) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
