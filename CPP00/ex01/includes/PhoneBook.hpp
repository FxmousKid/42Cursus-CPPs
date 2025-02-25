/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:01:51 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 12:06:29 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Setup.hpp"

class PhoneBook {
public:
	PhoneBook();
	void	addContact();
	void	searchContact();

private:
	Contact	contacts[8];
	int		contactCount;
};
