/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:28:06 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 13:54:32 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string str;

class AMateria {

public:
	AMateria();
	AMateria(const AMateria& other);
	AMateria&	operator=(const AMateria& other);
	virtual ~AMateria();

	AMateria(const str& type);

	const str& getType(void) const;

	virtual AMateria *clone() const = 0;
	// virtual void use(ICharacter& target);
	

protected:
	str	_type;
};
