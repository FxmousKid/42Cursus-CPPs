/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:21:47 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 14:49:06 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
// 	str input;

// 	if (argc != 2)
// 	{
// 		std::cout << "Invalid arg count\nUsage : ./convert [literal]\n";
// 		return (1);
// 	}
// 	input = argv[1];
// 	ScalarConverter::findType(input);
// 	return (0);
// }

void runTest(const str &literal) {
    std::cout << "\nTesting: " << literal << "\n";
    ScalarConverter::findType(literal);
    std::cout << "--------------------------------------\n";
}

int main() {
    // Character Tests
    runTest("a");
    runTest("Z");
    runTest("1"); // Should not be a char
    
    // Integer Tests
    runTest("42");
    runTest("-42");
    runTest("2147483647"); // INT_MAX
    runTest("-2147483648"); // INT_MIN
    runTest("2147483648"); // Out of int range
    
    // Float Tests
    runTest("42.0f");
    runTest("-42.42f");
    runTest("3.40282e+38f"); // FLT_MAX approx
    runTest("1.17549e-38f"); // FLT_MIN approx
    runTest("inff");
    runTest("-inff");
    runTest("nanf");
    
    // Double Tests
    runTest("42.0");
    runTest("-42.42");
    runTest("1.79769e+308"); // DBL_MAX approx
    runTest("2.22507e-308"); // DBL_MIN approx
    runTest("inf");
    runTest("-inf");
    runTest("nan");
    
    // Edge Cases
    runTest(".");
    runTest(".f");
    runTest("1.");
    runTest("1.f");
    runTest("1.0.0"); // Invalid
    runTest("abc"); // Invalid
    runTest("123abc"); // Invalid
    runTest("--42"); // Invalid
    
    return 0;
}
