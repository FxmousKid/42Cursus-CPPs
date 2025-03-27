/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:54:16 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 14:58:17 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdint.h>

typedef std::string str;

typedef struct s_Data
{
	str		name;
	int		id;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& rhs);
	Serializer&	operator=(const Serializer& rhs);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);	
	static Data	*deserialize(uintptr_t raw);
};
