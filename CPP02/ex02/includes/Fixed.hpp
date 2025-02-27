/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:51:05 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 20:12:14 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

typedef std::string str;	

class Fixed {
public:

	Fixed(); // Default Constructor
	Fixed(const Fixed& other); // Copy constructor
	Fixed & operator=(const Fixed& other); // Copy assignement operator
	~Fixed(); // Destructor
	
	Fixed(int const integer); // Int Constructor
	Fixed(float const floating); // Float Constructor

	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// comparison operators overload
	bool	operator==(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// Arithmetic operators overload
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;

	// increment/decrement operators overload
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	// public overlaoded functions
	static Fixed&			min(Fixed& n1, Fixed& n2);
	static const Fixed&		min(const Fixed& n1, const Fixed& n2);
	static Fixed&			max(Fixed& n1, Fixed& n2);
	static const Fixed&		max(const Fixed& n1, const Fixed& n2);
	

private:
	static const int	_width = 8;
	int					_fp;

};

std::ostream&	operator<<(std::ostream& os,const Fixed& point);

