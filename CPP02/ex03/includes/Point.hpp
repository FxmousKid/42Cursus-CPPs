/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:42:56 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 20:53:40 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const Point& other);
	Point & operator=(const Point& other);
	~Point();

	Point(Fixed const x, Fixed const y);

	Fixed getX(void) const;
	Fixed getY(void) const;

private:
	Fixed _x;
	Fixed _y;
};
