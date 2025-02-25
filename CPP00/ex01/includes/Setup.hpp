/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Setup.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:03:03 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/25 14:18:05 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <string>

#define MAX_CONTACTS 8
#define MAX_WIDTH 10

#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"
#define END "\033[0m"

typedef std::string str;

#include "Contact.hpp"
#include "PhoneBook.hpp"

