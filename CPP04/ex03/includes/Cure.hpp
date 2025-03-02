/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:55:51 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 14:40:03 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure: public AMateria {
	Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	virtual ~Cure();


	virtual AMateria *clone() const;
	//virtual void use(ICharacter& target);
};
