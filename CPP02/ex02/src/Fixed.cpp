/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:53:47 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 20:26:03 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fp(0) {}

Fixed::Fixed(int const integer): _fp(integer << Fixed::_width) {}

Fixed::Fixed(float const floating): _fp(roundf(floating * (1 << Fixed::_width))) {};

Fixed::Fixed(const Fixed& other): _fp(other._fp) {}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_fp = other._fp;
	return (*this);
}

Fixed::~Fixed() {}

int		Fixed::toInt(void) const {
	return (this->_fp >> Fixed::_width);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fp / (1 << Fixed::_width));
}

int		Fixed::getRawBits(void) const {
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

/* Comparison operators overload*/

bool	Fixed::operator==(const Fixed& other) const {
	return (this->_fp == other._fp);
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->_fp < other._fp);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (!(*this == other) && !(*this < other));
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (!(*this > other));
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (!(*this < other));
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (!(*this == other));
}

/* Arithmetic operators overload */

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed sum;
	sum._fp = this->_fp + other._fp;
	return (sum);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed sub;
	sub._fp = this->_fp - other._fp;
	return (sub);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed mult;
	long long tmp;
	tmp = (long long)this->_fp * (long long)other._fp;
	mult._fp = tmp >> Fixed::_width;
	return (mult);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed div;
	long long tmp;
	tmp = (long long)this->_fp / (long long)other._fp;
	div._fp = tmp << Fixed::_width;
	return (div);
}

/* Increment/Decrement operators overload */
Fixed&	Fixed::operator++(void) {
	this->_fp += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed&	Fixed::operator--(void) {
	this->_fp -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;
	--*this;
	return (tmp);
}


/* public functions overload */
Fixed&	Fixed::min(Fixed& n1, Fixed& n2) {
	if (n1 <= n2)
		return (n1);
	return (n2);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2) {
	if (n1 <= n2)
		return (n1);
	return (n2);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)  {
	if (n1 >= n2)
		return (n1);
	return (n2);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2)  {
	if (n1 >= n2)
		return (n1);
	return (n2);
}
