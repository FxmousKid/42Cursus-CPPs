/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:02:19 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 10:18:28 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

void testRPNCalculator()
{
    RPN calculator;
    
    // Test case 1: Basic addition
    std::cout << "Test 1: 3 4 + (Expected: 7)" << std::endl;
    calculator.calculate("3 4 +");
    
    // Test case 2: Basic subtraction
    std::cout << "\nTest 2: 5 2 - (Expected: 3)" << std::endl;
    calculator.calculate("5 2 -");
    
    // Test case 3: Basic multiplication
    std::cout << "\nTest 3: 3 4 * (Expected: 12)" << std::endl;
    calculator.calculate("3 4 *");
    
    // Test case 4: Basic division
    std::cout << "\nTest 4: 8 2 / (Expected: 4)" << std::endl;
    calculator.calculate("8 2 /");
    
    // Test case 5: Complex expression
    std::cout << "\nTest 5: 3 4 + 2 * 7 / (Expected: 2)" << std::endl;
    calculator.calculate("3 4 + 2 * 7 /");
    
    // Test case 6: Another complex expression
    std::cout << "\nTest 6: 5 1 2 + 4 * + 3 - (Expected: 14)" << std::endl;
    calculator.calculate("5 1 2 + 4 * + 3 -");
    
    // Test case 7: Error handling - insufficient operands
    std::cout << "\nTest 7: 1 + (Expected: Invalid input)" << std::endl;
    calculator.calculate("1 +");
    
    // Test case 8: Error handling - too many operands
    std::cout << "\nTest 8: 1 2 3 + (Expected: Invalid input)" << std::endl;
    calculator.calculate("1 2 3 +");
    
    // Test case 9: Error handling - invalid character
    std::cout << "\nTest 9: 1 2 ? (Expected: Invalid input)" << std::endl;
    calculator.calculate("1 2 ?");
    
    // Test case 10: Empty input
    std::cout << "\nTest 10: Empty string (Expected: Invalid input)" << std::endl;
    calculator.calculate("");
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
		std::cout << "Invalid Arg count\n";
        std::cout << "Usage: RPN [expression]" << std::endl;
        return (EXIT_FAILURE);
    }

	std::cout << "Launching tests" << std::endl;
	testRPNCalculator();
	std::cout << "Tests completed" << std::endl;
	
    std::string input = argv[1];
    RPN calculator;

	std::cout << "Input: " << input << std::endl;
    calculator.calculate(input);

    return (EXIT_SUCCESS);
}

