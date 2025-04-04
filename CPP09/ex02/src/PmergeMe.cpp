/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:20:09 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 18:49:41 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::~PmergeMe(void)
{
	return;
}

/*Getters*******************************/

VecInt const& PmergeMe::getVec(void) const
{
	return (this->_vec);
}

DeqInt const& PmergeMe::getDeq(void) const
{
	return (this->_deq);
}

/***********************************/

// ################ CODE FOR VECTOR CONTAINER ####################

void PmergeMe::parseInputVec(char** input)
{
	char*   endptr = NULL;
	long    tmpValue;
	int     numValue;
	
	while (*input && **input)
	{
		tmpValue = strtol(*input, &endptr, 10);
		if (*endptr)
			throw std::invalid_argument("Error: not a number.");
		if (tmpValue <= 0)
			throw std::invalid_argument("Error: accepts only strictly positive numbers.");
		if (tmpValue > INT_MAX)
			throw std::invalid_argument("Error: int overflow.");
		
		numValue = static_cast<int>(tmpValue);
		this->_vec.push_back(numValue);
		input++;
	}
	
	if (this->_vec.size() == 0)
		throw std::invalid_argument("Error: empty sequence.");
		
	return;
}

void PmergeMe::printVec(VecInt const& vec)
{
	VecIntConstIter it;
	
	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
		
	std::cout << std::endl;
	return;
}

void PmergeMe::sortVec(void)
{
	VecInt vecCopy = this->_vec;
	
	// needed for recursion information
	VecInt indexSequence; 
	
	PmergeMe::recursiveSortVec(vecCopy, indexSequence);
	this->_vec = vecCopy;	
	return;
}

/* Virtually split into two equal-length segments (odd element unused if any)
 * Virtually pair i-th element of each segment and make comparison
 * Swap to have elements in first segment >= corresponding elements in second segment 
*/
void PmergeMe::recursiveSortVec(VecInt& vec, VecInt& indexes)
{
	bool isFirstCall = indexes.empty();

	if (vec.size() == 1)
		return;

	VecIntIter it1 = vec.begin();          
	VecIntIter it2 = it1 + vec.size() / 2;

	VecIntIter indexIt1;                   
	VecIntIter indexIt2;
	
	if (!isFirstCall)
	{
		indexIt1 = indexes.begin();
		indexIt2 = indexIt1 + indexes.size() / 2;
	}
	
	for (size_t j = 0; j < vec.size() / 2; j++)
	{
		if (*it2 > *it1)
		{
			std::iter_swap(it1, it2);
			if (!isFirstCall)
				std::iter_swap(indexIt1, indexIt2);
		}
		it1++;
		it2++;
		if (!isFirstCall)
		{
			indexIt1++;
			indexIt2++;
		}
	}
	
	// Split main and pending parts for both vec and indexes
	VecInt mainChain(vec.begin(), vec.begin() + vec.size() / 2);
	VecInt pendChain(vec.begin() + vec.size() / 2, vec.end());
	VecInt mainIndexes;
	VecInt pendIndexes;
	
	if (!isFirstCall)
	{
		mainIndexes.insert(mainIndexes.end(), indexes.begin(), indexes.begin() + indexes.size() / 2);
		pendIndexes.insert(pendIndexes.end(), indexes.begin() + indexes.size() / 2, indexes.end());
	}

	// Create index sequence for recursive sort
	VecInt subIndexes;
	for (size_t i = 0; i < mainChain.size(); i++)
		subIndexes.push_back(i);
		
	// Recursively sort main chain
	PmergeMe::recursiveSortVec(mainChain, subIndexes);
	
	// Rearrange other sequences based on the sort
	PmergeMe::rearrangeVec(pendChain, subIndexes);
	if (!isFirstCall)
	{
		PmergeMe::rearrangeVec(mainIndexes, subIndexes);
		PmergeMe::rearrangeVec(pendIndexes, subIndexes);
	}

	// Merge chains using binary insertion
	PmergeMe::binaryInsertVec(mainChain, pendChain, mainIndexes, pendIndexes);
	
	// Update original containers
	vec = mainChain;
	indexes = mainIndexes;

	return;	
}

void PmergeMe::rearrangeVec(VecInt& vec, VecInt& indexes)
{
	VecInt vecCopy = vec;
	
	for (size_t i = 0; i < indexes.size(); i++)
		vec[i] = vecCopy[indexes[i]];
		
	return;
}

// Binary insert with Jacobsthal sequence
void PmergeMe::binaryInsertVec(
	VecInt& mainChain, 
	VecInt& pendChain,
	VecInt& mainIndexes, 
	VecInt& pendIndexes)
{
	bool isFirstCall = mainIndexes.empty();

	JacobSeq jacobSequence;              // Jacobsthal number sequence
	SizeVec  maxInsertChainSize;         // To determine insertion window
	unsigned long jacobPrevious = 1;
	long insertWindow;                   // Size of chain to insert into
	VecIntIter insertPosition;           // Position before which to insert
	
	// Initialize sequences
	jacobSequence.push_back(1);
	maxInsertChainSize.push_back(1);
	
	// Generate needed Jacobsthal sequence and maxInsertChainSize
	while (jacobSequence.back() < pendChain.size())
	{
		jacobSequence.push_back(jacobSequence.back() + 2 * jacobPrevious);
		jacobPrevious = *(jacobSequence.end() - 2);
		maxInsertChainSize.push_back((maxInsertChainSize.back() + 1) * 2 - 1); // 2^n - 1
	}

	// Perform insertions according to Jacobsthal sequence
	for (size_t j = 0; j < jacobSequence.size(); j++)
	{
		jacobPrevious = (jacobSequence[j] == 1) ? 0 : jacobSequence[j - 1];
		
		for (unsigned long i = jacobSequence[j]; i > jacobPrevious; i--)
		{
			if (i > pendChain.size())
				continue;
			
			insertWindow = std::min(static_cast<long>(mainChain.size()), maxInsertChainSize[j]);
			
			// First element needs no binary search
			if (i == 1)
			{
				insertPosition = mainChain.begin();	
			}
			else
			{
				// Use binary search (lower_bound) to find insertion point
				insertPosition = std::lower_bound(
					mainChain.begin(), 
					mainChain.begin() + insertWindow, 
					pendChain[i - 1]
				);
			}

			// Insert element into main chain
			if (!isFirstCall)
			{
				mainIndexes.insert(
					mainIndexes.begin() + std::distance(mainChain.begin(), insertPosition), 
					pendIndexes[i - 1]
				);
			}
			
			mainChain.insert(insertPosition, pendChain[i - 1]);
		}
	}
	
	return;
}

/* Code for Deque */
void PmergeMe::parseInputDeq(char** input)
{
	char*   endptr = NULL;
	long    tmpValue;
	int     numValue;
	
	while (*input && **input)
	{
		tmpValue = strtol(*input, &endptr, 10);
		if (*endptr)
			throw std::invalid_argument("Error: not a number.");
		if (tmpValue <= 0)
			throw std::invalid_argument("Error: accepts only strictly positive numbers.");
		if (tmpValue > INT_MAX)
			throw std::invalid_argument("Error: int overflow.");
		
		numValue = static_cast<int>(tmpValue);
		this->_deq.push_back(numValue);
		input++;
	}
	
	if (this->_deq.size() == 0)
		throw std::invalid_argument("Error: empty sequence.");
		
	return;
}

void PmergeMe::printDeq(DeqInt const& deq)
{
	DeqIntConstIter it;
	
	for (it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
		
	std::cout << std::endl;
	return;
}

void PmergeMe::sortDeq(void)
{
	DeqInt deqCopy = this->_deq;
	DeqInt indexSequence;
	
	PmergeMe::recursiveSortDeq(deqCopy, indexSequence);
	this->_deq = deqCopy;
	
	return;
}

void PmergeMe::recursiveSortDeq(DeqInt& deq, DeqInt& indexes)
{
	bool isFirstCall = indexes.empty();

	if (deq.size() == 1)
		return;

	DeqIntIter it1 = deq.begin();          
	DeqIntIter it2 = it1 + deq.size() / 2; 
	
	DeqIntIter indexIt1;                	
	DeqIntIter indexIt2;
	
	if (!isFirstCall)
	{
		indexIt1 = indexes.begin();
		indexIt2 = indexIt1 + indexes.size() / 2;
	}
	
	for (size_t j = 0; j < deq.size() / 2; j++)
	{
		if (*it2 > *it1)
		{
			std::iter_swap(it1, it2);
			if (!isFirstCall)
				std::iter_swap(indexIt1, indexIt2);
		}
		it1++;
		it2++;
		if (!isFirstCall)
		{
			indexIt1++;
			indexIt2++;
		}
	}
	
	// Split main and pending parts for both deq and indexes
	DeqInt mainChain(deq.begin(), deq.begin() + deq.size() / 2);
	DeqInt pendChain(deq.begin() + deq.size() / 2, deq.end());
	DeqInt mainIndexes;
	DeqInt pendIndexes;
	
	if (!isFirstCall)
	{
		mainIndexes.insert(mainIndexes.end(), indexes.begin(), indexes.begin() + indexes.size() / 2);
		pendIndexes.insert(pendIndexes.end(), indexes.begin() + indexes.size() / 2, indexes.end());
	}

	// Create index sequence for recursive sort
	DeqInt subIndexes;
	for (size_t i = 0; i < mainChain.size(); i++)
		subIndexes.push_back(i);
		
	// Recursively sort main chain
	PmergeMe::recursiveSortDeq(mainChain, subIndexes);
	
	// Rearrange other sequences based on the sort
	PmergeMe::rearrangeDeq(pendChain, subIndexes);
	if (!isFirstCall)
	{
		PmergeMe::rearrangeDeq(mainIndexes, subIndexes);
		PmergeMe::rearrangeDeq(pendIndexes, subIndexes);
	}

	// Merge chains using binary insertion
	PmergeMe::binaryInsertDeq(mainChain, pendChain, mainIndexes, pendIndexes);
	
	// Update original containers
	deq = mainChain;
	indexes = mainIndexes;

	return;	
}

void PmergeMe::rearrangeDeq(DeqInt& deq, DeqInt& indexes)
{
	DeqInt deqCopy = deq;
	
	for (size_t i = 0; i < indexes.size(); i++)
		deq[i] = deqCopy[indexes[i]];
		
	return;
}

// Binary insert with Jacobsthal sequence
void PmergeMe::binaryInsertDeq(
	DeqInt& mainChain, 
	DeqInt& pendChain,
	DeqInt& mainIndexes, 
	DeqInt& pendIndexes)
{
	bool isFirstCall = mainIndexes.empty();

	std::vector<unsigned long> jacobSequence;
	std::vector<long> maxInsertChainSize;
	unsigned long jacobPrevious = 1;
	long insertWindow;                        
	DeqIntIter insertPosition;
	
	// Initialize sequences
	jacobSequence.push_back(1);
	maxInsertChainSize.push_back(1);
	
	// Generate needed Jacobsthal sequence and maxInsertChainSize
	while (jacobSequence.back() < pendChain.size())
	{
		jacobSequence.push_back(jacobSequence.back() + 2 * jacobPrevious);
		jacobPrevious = *(jacobSequence.end() - 2);
		maxInsertChainSize.push_back((maxInsertChainSize.back() + 1) * 2 - 1); // 2^n - 1
	}

	// Perform insertions according to Jacobsthal sequence
	for (size_t j = 0; j < jacobSequence.size(); j++)
	{
		jacobPrevious = (jacobSequence[j] == 1) ? 0 : jacobSequence[j - 1];
		
		for (unsigned long i = jacobSequence[j]; i > jacobPrevious; i--)
		{
			if (i > pendChain.size())
				continue;
			
			insertWindow = std::min(static_cast<long>(mainChain.size()), maxInsertChainSize[j]);
			
			// First element needs no binary search
			if (i == 1)
			{
				insertPosition = mainChain.begin();	
			}
			else
			{
				// Use binary search (lower_bound) to find insertion point
				insertPosition = std::lower_bound(
					mainChain.begin(), 
					mainChain.begin() + insertWindow, 
					pendChain[i - 1]
				);
			}

			// Insert element into main chain
			if (!isFirstCall)
			{
				mainIndexes.insert(
					mainIndexes.begin() + std::distance(mainChain.begin(), insertPosition), 
					pendIndexes[i - 1]
				);
			}
			
			mainChain.insert(insertPosition, pendChain[i - 1]);
		}
	}
	
	return;
}
