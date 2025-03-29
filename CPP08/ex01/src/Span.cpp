/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:50:37 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/29 13:26:47 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cfloat>
#include <stdexcept>
#include <vector>
#include <limits.h>
#include <algorithm>

Span::Span(): _vec(std::vector<int>(0))
{
}

Span::Span(unsigned int N): _vec(std::vector<int>(0))
{
	_vec.reserve(N);
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs) {
		_vec = rhs._vec;
	}
	return (*this);
}

Span::Span(const Span& rhs)
{
	*this = rhs;
}

Span::~Span()
{
}

void	Span::addNumber(int num)
{
	if (_vec.size() >= _vec.capacity())
		throw std::runtime_error("container is full !");
	_vec.push_back(num);
}

static void	verify_size_span(std::vector<int> vec)
{
	if (vec.size() <= 1)
		throw std::runtime_error("container too small for spans");
}

int	Span::shortestSpan() const
{
	verify_size_span(_vec);

	std::vector<int> vec_sorted = _vec;
	std::sort(vec_sorted.begin(), vec_sorted.end());

	double shortest = vec_sorted[1] - vec_sorted[0];

	for (size_t i = 1; i < vec_sorted.size(); i++)
		if (vec_sorted[i] - vec_sorted[i - 1] < shortest)
			shortest = vec_sorted[i] - vec_sorted[i - 1];

	return (shortest);
}

int	Span::longestSpan() const 
{
	verify_size_span(_vec);

	std::vector<int> vec_sorted = _vec;
	std::sort(vec_sorted.begin(), vec_sorted.end());

	double longest = vec_sorted[1] - vec_sorted[0];

	for (size_t i = 1; i < vec_sorted.size(); i++)
		if (vec_sorted[i] - vec_sorted[i - 1] > longest)
			longest = vec_sorted[i] - vec_sorted[i - 1];

	return (longest);

}

void	Span::addNumbersIter(std::vector<int> vec2) 
{
	if (vec2.size() + _vec.size() > _vec.capacity())
		throw std::runtime_error("container too small to add ");
	_vec.insert(_vec.end(), vec2.begin(), vec2.end());
}


