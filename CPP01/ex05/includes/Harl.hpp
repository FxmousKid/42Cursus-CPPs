/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:57:33 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/26 02:19:29 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

typedef std::string str;

class Harl {
public:
	Harl();
	~Harl();
	void	complain(str level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

typedef void (Harl::*HarlFunction)(void);
