/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:53:47 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 16:06:52 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fp(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer): _fp(integer << Fixed::_width) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floating): _fp(roundf(floating * (1 << Fixed::_width))) {
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other): _fp(other._fp) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_fp = other._fp;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::toInt(void) const {
	return (this->_fp >> Fixed::_width);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fp / (1 << Fixed::_width));
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp);
}

void	Fixed::setRawBits(int const raw) {
	this->_fp = raw;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& point) {
	float ret = point.toFloat();
	os << ret;
	return (os);
}
