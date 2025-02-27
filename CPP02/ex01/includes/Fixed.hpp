/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:51:05 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/27 16:04:08 by inazaria         ###   ########.fr       */
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
	

private:
	static const int	_width = 8;
	int					_fp;
};


std::ostream&	operator<<(std::ostream& os,const Fixed& point);
