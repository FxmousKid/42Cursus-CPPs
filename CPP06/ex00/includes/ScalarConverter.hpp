/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:27:29 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 12:51:51 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>
#include <climits>
#include <limits.h>

typedef std::string str;
typedef std::numeric_limits<float> flimits;
typedef std::numeric_limits<double> dlimits;
typedef std::numeric_limits<long> llimits;


class ScalarConverter {

public:
	~ScalarConverter();

	ScalarConverter & operator=(ScalarConverter const & src);

	void convert();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	static bool isFloatingPoint(str literal, char suffix);
	static void findType(str literal);
	static bool isChar(str literal);
	static bool isFloat(str literal);
	static bool isDouble(str literal);
	static bool isInt(str literal);

	static void convertToChar(str literal);
	static void convertToInt(str literal);
	static void convertToFloat(str literal);
	static void convertToDouble(str literal);
	static bool	convertPseudoLiterals(str literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & src);
};

#define PRINTLN(x) std::cout << x << std::endl
