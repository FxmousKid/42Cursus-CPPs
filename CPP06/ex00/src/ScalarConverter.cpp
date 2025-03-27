/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:28:29 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 12:52:08 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	if (this == &src)
		return *this;
	return *this;
}

bool ScalarConverter::isChar(str literal)
{
    if (isalpha(literal[0]) && literal.length() == 1)
        return true;
    return false;
}

bool ScalarConverter::isInt(str literal)
{
    size_t i;
    long int temp;

    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (literal[i] != '\0')
    {
        if (!std::isdigit(literal[i]) || i > 10)
            return (false);
        i++;
    }
    temp = atol(literal.c_str());
    if (temp <= std::numeric_limits<int>::max() && temp >= std::numeric_limits<int>::min())
        return (true);
    else
        return (false);
}

bool ScalarConverter::isFloat(str literal)
{
    size_t i;
    size_t dot_count;

    dot_count = 0;
    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (literal[i] != '\0')
    {
        if (!std::isdigit(literal[i]))
        {
            if (literal[i] == '.')
            {
                dot_count++;
                if (dot_count > 1 || std::isdigit(literal[i + 1]) == 0 || literal[i + 1] == '\0')
                    return (false);
            }
            else if ((literal[i] == 'F' || literal[i] == 'f') && dot_count == 1 && literal[i + 1] == '\0')
                return (true);
            else
                return (false);
        }
        i++;
    }
    return (false);
}

bool ScalarConverter::isDouble(str literal)
{
    size_t i;
    size_t dot_count;

    dot_count = 0;
    i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (literal[i] != '\0')
    {
        if (!std::isdigit(literal[i]))
        {
            if (literal[i] == '.')
            {
                dot_count++;
                if (dot_count > 1 || std::isdigit(literal[i + 1]) == 0 || literal[i + 1] == '\0')
                    return (false);
            }
            else if ((literal[i] == 'D' || literal[i] == 'd') && dot_count == 1 && literal[i + 1] == '\0')
                return (true);
            else
                return (false);
        }
        i++;
    }
    return(dot_count == 1 ? true : false);
}

void    ScalarConverter::findType(str literal)
{
    if (convertPseudoLiterals(literal) == false)
    {
        if (isChar(literal))
            convertToChar(literal);
        if (isInt(literal))
            convertToInt(literal);
        if (isDouble(literal))
            convertToDouble(literal);
        if (isFloat(literal))
            convertToFloat(literal);   
    }
}

bool ScalarConverter::convertPseudoLiterals(str literal)
{
    str charMsg = "char: impossible";
    str intMsg = "int: impossible";
    
    if (literal == "nanf" || literal == "nan")
    {
        std::cout << charMsg << std::endl << intMsg << std::endl;
        std::cout << "float: nanf\n" << "double: nan" << std::endl;
        return (true);
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << charMsg << std::endl << intMsg << std::endl;
        std::cout << "float: -inff\n" << "double: -inf" << std::endl;
        return (true);
    }
    else if (literal == "inff" || literal == "inf" || literal == "+inff" || literal == "+inf")
    {
        std::cout << charMsg << std::endl << intMsg << std::endl;
        std::cout << "float: inff\n" << "double: inf" << std::endl;
        return (true);
    }
    return (false);
}

void    ScalarConverter::convertToChar(str literal)
{
    char c;

    c = literal[0];
    if (literal.length() == 1)
    {
        std::cout << "char: " << "'" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

void    ScalarConverter::convertToInt(str literal)
{
    long i;

    i = atoll(literal.c_str());
    std::cout << "char: ";
    if ((i >= 0 && i < 32) || (i == 127))
        std::cout << "Non displayable\n";
    else if (i < 0 || i > 127)
        std::cout << "impossible\n";
    else 
        std::cout << "'" << static_cast<char>(i) << "'\n";
    if (i <= llimits::max() && i >= llimits::min() &&  literal.length() < 10)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible\n";
    if (std::abs(i) <= flimits::max())
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
    else
        std::cout << "float: impossible\n";
    if (std::abs(i) <= dlimits::max())
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
    else
        std::cout << "double: impossible\n";
    return ;
}

void    ScalarConverter::convertToDouble(str literal)
{
    double d;
    
    if (convertPseudoLiterals(literal) == true)
        return ;
    d = atof(literal.c_str());
    std::cout << "char: ";
    if ((d >= 0 && d < 32) || (d == 127))
		PRINTLN("Non pritable");
    else if (d < 0 || d > 127)
        std::cout << "impossible\n";
    else 
        std::cout << "'" << static_cast<char>(d) << "'\n";
    if (d <= llimits::max() && d >= llimits::min() &&  literal.length() < 10)
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
		PRINTLN("Int not displayable");
    if (std::abs(d) <= flimits::max())
    {
        if (static_cast<float>(d) == static_cast<int>(d))
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
        else
            std::cout << "float: " << static_cast<float>(d) << "f\n";
    }
    else
		PRINTLN("Float not displayable");
    if (std::abs(d) <= dlimits::max())
        std::cout << "double: " << static_cast<double>(d) << std::endl;
    else
        std::cout << "double: impossible\n";
    return ;
}

void    ScalarConverter::convertToFloat(str literal)
{
    float f;

    if (convertPseudoLiterals(literal) == true)
        return ;
    f = strtof(literal.c_str(), NULL);
    std::cout << "char: ";
    if ((f >= 0 && f < 32) || (f == 127))
        std::cout << "Non displayable\n";
    else if (f < 0 || f > 127)
        std::cout << "impossible\n";
    else 
        std::cout << "'" << static_cast<char>(f) << "'\n";
    if (f <= llimits::max() && f >= llimits::min() &&  literal.length() < 10)
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int: impossible\n";
    if (std::fabs(f) <= flimits::max())
    {
        if (static_cast<float>(f) == static_cast<int>(f))
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f\n";
        else
            std::cout << "float: " << static_cast<float>(f) << "f\n";
    }
    else
        std::cout << "float: impossible\n";
    if (std::fabs(f) <= dlimits::max())
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    else
        std::cout << "double: impossible\n";
    return ;
}
