/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:15 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/28 19:37:10 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

typedef std::string str;

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& rhs);
	Span&	operator=(const Span& rhs);
	~Span();

	//throws std::runtime_error if N elements are already in container
	void	addNumber(int num);
	int		shortestSpan() const;
	int		longestSpan() const;
	void	addNumbersIter(std::vector<int> vec2);

private:
	std::vector<int> _vec;
	Span();
};
