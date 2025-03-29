/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:33:56 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/29 19:14:27 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
	MutantStack &operator=(const MutantStack &copy)
	{
		if (this == &copy)
			return (*this);
		std::stack<T>::operator=(copy);
		return (*this);
	}
	~MutantStack() {}

	// container::container_type is a type for the underlying type
	// making a typedef for the underlying container
	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator begin() {return (this->c.begin());}
	iterator end() {return (this->c.end());}
	reverse_iterator rbegin() {return (this->c.rbegin());}
	reverse_iterator rend() {return (this->c.rend());}

	const_iterator cbegin() const {return (this->c.begin());}
	const_iterator cend() const {return (this->c.end());}
	const_reverse_iterator rbegin() const {return (this->c.rbegin());}
	const_reverse_iterator rend() const {return (this->c.rend());}
};
