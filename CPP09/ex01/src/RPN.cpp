/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:03:07 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 10:16:26 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::~RPN()
{
	return;
}

RPN::RPN(std::stack<double> number)
{
	this->numbers = number;
}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &var)
{
	this->numbers = var.numbers;
	return (*this);
}

void RPN::performOperation(char op)
{
    double b = numbers.top();
    numbers.pop();
    double a = numbers.top();
    numbers.pop();
    
    switch (op) {
        case '+': numbers.push(a + b); break;
        case '-': numbers.push(a - b); break;
        case '*': numbers.push(a * b); break;
        case '/': numbers.push(a / b); break;
        default: return ;
    }
}

void RPN::calculate(std::string input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        char c = input[i];

        if (c == ' ')
            continue;
        else if (isdigit(c))
            numbers.push(c - '0');
        else if ((c == '+' || c == '-' || c == '*' || c == '/') && numbers.size() >= 2)
            performOperation(c);
        else
        {
            std::cout << "Invalid input !" << std::endl;
            return;
        }
    }
    
    if (numbers.size() == 1)
    {
        double result = numbers.top();
        numbers.pop();
        std::cout << "Result: " << result << std::endl;
    }
    else
        std::cout << "Invalid input !" << std::endl;
}
