/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:33:04 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 12:34:59 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << RED_BG << "Usage: ./btc input.txt" << NC << std::endl;
        return (EXIT_FAILURE);
    }
    
    try
    {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv"); // DB du sujet
        exchange.processInput(argv[1]); // input
    }
    catch (const std::exception& e)
    {
        std::cerr << NC << RED_BG << e.what() << NC << std::endl;
        return (EXIT_FAILURE);
    }
    
    return (EXIT_SUCCESS);
}
