/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:54:17 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 21:00:51 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"


Fixed crossProduct(const Point& a, const Point& b, const Point& p) {
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) - 
           (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
    // Calculate the orientation of the point relative to each edge
    Fixed d1 = crossProduct(a, b, point);
    Fixed d2 = crossProduct(b, c, point);
    Fixed d3 = crossProduct(c, a, point);

    // Check if all orientations are either positive or negative
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    // If the point is on the same side of all edges, it's inside the triangle
    if (!(has_neg && has_pos)) {
        return true;
    }

    // Otherwise, it's outside
    return false;
}
