/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:01:46 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 12:26:05 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Setup.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setFirstName(str fname)
{
	this->firstName = fname;
}

void Contact::setLastName(str lname)
{
	this->lastName = lname;
}

void Contact::setNickname(str nickname)
{
	this->nickname = nickname;
}

void Contact::setDarkestSecret(str darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(str phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

str Contact::getFirstName(void)
{
	return (this->firstName);
}

str Contact::getLastName(void)
{
	return (this->lastName);
}

str Contact::getNickname(void)
{
	return (this->nickname);
}

str Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

str Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}
