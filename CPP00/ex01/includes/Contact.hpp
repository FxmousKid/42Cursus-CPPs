/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:01:49 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 12:26:01 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Setup.hpp"

class Contact {
public:
	Contact();
	~Contact();
	
	void	setFirstName(str firstName);
	void	setLastName(str lastName);
	void	setNickname(str nickname);
	void	setPhoneNumber(str phoneNumber);
	void	setDarkestSecret(str darkestSecret);

	str		getFirstName();
	str		getLastName();
	str		getNickname();
	str		getPhoneNumber();
	str		getDarkestSecret();

private:
	str		firstName;
	str		lastName;
	str		nickname;
	str		phoneNumber;
	str		darkestSecret;
};
