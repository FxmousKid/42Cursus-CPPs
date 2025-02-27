/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:52:58 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 21:02:38 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

int main() {

    Point a(0, 0);
    Point b(10, 10);
    Point c(10, 0);

    Point point(6, 6);

    if (bsp(a, b, c, point)) {
        std::cout << "The point is inside the triangle." << std::endl;
    } else {
        std::cout << "The point is outside the triangle." << std::endl;
    }

    return 0;
}
