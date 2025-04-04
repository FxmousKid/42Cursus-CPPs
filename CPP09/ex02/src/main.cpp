/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:18:39 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 18:50:12 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char *argv[])
{
	if (argc == 1 || !argv[1])
	{
		std::cout << "Error: empty input sequence." << std::endl;
		exit(EXIT_FAILURE);
	}
	 
	PmergeMe FJ_test;
	PmergeMe FJ;
	try
	{
		FJ_test.parseInputVec(++argv);
		std::cout << "Before: ";
		PmergeMe::printVec(FJ_test.getVec());
		FJ_test.sortVec();
		std::cout << "After: ";
		PmergeMe::printVec(FJ_test.getVec());


		// Testing for std::vector
		clock_t beginVec = std::clock();
		FJ.parseInputVec(++argv);
		FJ.sortVec();
  		clock_t endVec = clock();
  		double us = double(endVec - beginVec) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time taken using std::vector for " << argc - 1 << " elements: ";
		std::cout << us << " us" << std::endl;
	

		// Testing for std::deque
		clock_t beginDeq = std::clock();
		FJ.parseInputDeq(argv);
		FJ.sortDeq();
  		clock_t endDeq = clock();
  		us = double(endDeq - beginDeq) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time taken using std::deque for " << argc - 1 << " elements: ";
		std::cout << us << " us" << std::endl;
	}

	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}

