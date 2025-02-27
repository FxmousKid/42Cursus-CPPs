/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:42:18 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 20:54:05 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y) {}

Point::Point(Point const& other): _x(other._x), _y(other._y) {}

Point&	Point::operator=(const Point& other) {
	if (this != &other) {
		this->_x = other._x;
		this->_y = other._y;
	}
	return (*this);
}

Point::~Point() {}

Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}
