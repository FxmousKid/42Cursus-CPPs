/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:20:37 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 18:50:00 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <algorithm>
# include <climits>

typedef std::vector<int>					VecInt;
typedef std::vector<int>::iterator			VecIntIter;
typedef std::vector<int>::const_iterator	VecIntConstIter;

typedef std::deque<int>						DeqInt;
typedef std::deque<int>::iterator			DeqIntIter;
typedef std::deque<int>::const_iterator		DeqIntConstIter;

typedef std::vector<unsigned long>			JacobSeq;
typedef std::vector<long>					SizeVec;


class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe(void);
		
		// VECTOR
		void                parseInputVec(char** input);
		void                sortVec(void);
		VecInt const&       getVec(void) const;
		static void         printVec(VecInt const& vec);
		
		// DEQUE
		void                parseInputDeq(char** input);
		void                sortDeq(void);
		DeqInt const&       getDeq(void) const;
		static void         printDeq(DeqInt const& deq);
	
	private:
		PmergeMe(PmergeMe const&);
		PmergeMe& operator=(PmergeMe const&);
		
		// VECTOR
		static void recursiveSortVec(VecInt& vec, VecInt& indexes);
		static void rearrangeVec(VecInt& vec, VecInt& indexes);
		static void binaryInsertVec(
			VecInt& mainChain, 
			VecInt& pendChain,
			VecInt& mainIndexes,
			VecInt& pendIndexes
		);
		
		// DEQUE
		static void recursiveSortDeq(DeqInt& deq, DeqInt& indexes);
		static void rearrangeDeq(DeqInt& deq, DeqInt& indexes);
		static void binaryInsertDeq(
			DeqInt& mainChain, 
			DeqInt& pendChain,
			DeqInt& mainIndexes, 
			DeqInt& pendIndexes
		);
		
		VecInt _vec;
		DeqInt _deq;
};
