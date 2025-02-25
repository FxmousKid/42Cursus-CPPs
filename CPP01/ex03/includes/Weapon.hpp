/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:42:01 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 19:20:36 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class Weapon {
public:
	Weapon();
	Weapon(str type);
	~Weapon();
	str		const &getType() const ;
	void	setType(str newType);
	
private:
	str _type;
};
