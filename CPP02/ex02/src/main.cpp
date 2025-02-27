/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:52:58 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 20:36:58 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cassert> // For assert()

void test_fixed_class() {
    // Test 1: Default Constructor
    {
        Fixed a;
        assert(a.getRawBits() == 0); // Default value should be 0
        std::cout << "Test 1 Passed: Default Constructor" << std::endl;
    }

    // Test 2: Int Constructor
    {
        Fixed a(42);
        assert(a.getRawBits() == (42 << 8)); // Check raw bits for int 42
        std::cout << "Test 2 Passed: Int Constructor" << std::endl;
    }

    // Test 3: Float Constructor
    {
        Fixed a(3.14f);
        assert(a.getRawBits() == static_cast<int>(roundf(3.14f * (1 << 8)))); // Check raw bits for float 3.14
        std::cout << "Test 3 Passed: Float Constructor" << std::endl;
    }

    // Test 4: Copy Constructor
    {
        Fixed a(10);
        Fixed b(a);
        assert(b.getRawBits() == a.getRawBits()); // b should be a copy of a
        std::cout << "Test 4 Passed: Copy Constructor" << std::endl;
    }

    // Test 5: Copy Assignment Operator
    {
        Fixed a(20);
        Fixed b;
        b = a;
        assert(b.getRawBits() == a.getRawBits()); // b should now be a copy of a
        std::cout << "Test 5 Passed: Copy Assignment Operator" << std::endl;
    }

    // Test 6: toInt() Function
    {
        Fixed a(123);
        assert(a.toInt() == 123); // toInt() should return 123
        std::cout << "Test 6 Passed: toInt() Function" << std::endl;
    }

    // Test 8: getRawBits() and setRawBits()
    {
        Fixed a;
        a.setRawBits(12345);
        assert(a.getRawBits() == 12345); // getRawBits() should return 12345
        std::cout << "Test 8 Passed: getRawBits() and setRawBits()" << std::endl;
    }

    // Test 9: Comparison Operators
    {
        Fixed a(10);
        Fixed b(20);
        assert(a < b);  // a < b
        assert(b > a);  // b > a
        assert(a <= b); // a <= b
        assert(b >= a); // b >= a
        assert(a != b); // a != b
        assert(a == a); // a == a
        std::cout << "Test 9 Passed: Comparison Operators" << std::endl;
    }

    // Test 10: Arithmetic Operators
    {
        Fixed a(10);
        Fixed b(20);
        Fixed c = a + b;
        assert(c.toInt() == 30); // 10 + 20 = 30
        Fixed d = b - a;
        assert(d.toInt() == 10); // 20 - 10 = 10
        Fixed e = a * b;
        assert(e.toInt() == 200); // 10 * 20 = 200
        Fixed f = b / a;
        assert(f.toInt() == 2); // 20 / 10 = 2
        std::cout << "Test 10 Passed: Arithmetic Operators" << std::endl;
    }

    // Test 12: min() and max() Functions
    {
        Fixed a(10);
        Fixed b(20);
        Fixed& smaller = Fixed::min(a, b);
        assert(&smaller == &a); // a is smaller than b
        Fixed& larger = Fixed::max(a, b);
        assert(&larger == &b); // b is larger than a

        const Fixed c(5);
        const Fixed d(15);
        const Fixed& smallerConst = Fixed::min(c, d);
        assert(&smallerConst == &c); // c is smaller than d
        const Fixed& largerConst = Fixed::max(c, d);
        assert(&largerConst == &d); // d is larger than c
        std::cout << "Test 12 Passed: min() and max() Functions" << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}
int main(void)
{
	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	test_fixed_class();

	return (0);
}
