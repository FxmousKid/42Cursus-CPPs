/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:55:51 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 14:38:02 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice: public AMateria {
public:
	Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	virtual ~Ice();


	virtual AMateria *clone() const;
	//virtual void use(ICharacter& target);
};
