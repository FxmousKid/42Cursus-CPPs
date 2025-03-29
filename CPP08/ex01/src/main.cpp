/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:51:33 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/29 13:29:02 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return (0);
// }

void testSpan() {
    std::cout << "--- Testing basic Span functionality ---\n";

    // Test 1: Basic addNumber and span calculations
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test 2: addNumbersIter functionality
    {
        Span sp(10);
        std::vector<int> numbers;
        numbers.push_back(5);
        numbers.push_back(10);
        numbers.push_back(15);
        numbers.push_back(20);

        sp.addNumbersIter(numbers);
        
        std::cout << "After addNumbersIter - Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "After addNumbersIter - Longest span: " << sp.longestSpan() << std::endl;

        // Try adding more numbers
        std::vector<int> moreNumbers;
        moreNumbers.push_back(25);
        moreNumbers.push_back(30);
        sp.addNumbersIter(moreNumbers);

        std::cout << "After second addNumbersIter - Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "After second addNumbersIter - Longest span: " << sp.longestSpan() << std::endl;
    }

	// Test 3: Big arrays
	{
		Span sp(25000);
		std::vector<int> bigVec(25000, 12);

		sp.addNumbersIter(bigVec);
		// sp should be at full capacity
		try {
			std::cout << "Trying to add one more number to a full array of cpaacity 25 000: " << std::endl;
			sp.addNumber(12);
		}
		catch (std::runtime_error& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

    // Test 4: Edge cases
    {
        Span sp(3);
        try {
            std::cout << "Trying shortestSpan on empty span: ";
            std::cout << sp.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        sp.addNumber(42);
        try {
            std::cout << "Trying longestSpan with single number: ";
            std::cout << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        try {
            std::vector<int> bigVec(10, 42);
            std::cout << "Trying to add too many numbers: ";
            sp.addNumbersIter(bigVec);
            std::cout << "Success (this is not good)" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
}

int main() {
    testSpan();
    return 0;
}
