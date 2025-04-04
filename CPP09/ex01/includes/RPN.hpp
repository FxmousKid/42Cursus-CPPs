/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:02:41 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 10:16:19 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN &var);
	RPN &operator=(const RPN &var);
	~RPN();

	RPN(std::stack<double> number);
	void calculate(std::string input);

private:
	std::stack<double> numbers;
	void performOperation(char op);
};
