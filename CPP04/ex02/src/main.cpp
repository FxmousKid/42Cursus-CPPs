/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:37:19 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/16 15:34:59 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <cstdio>

void	brainCopy(Brain *b1, Brain *b2)
{
	for (size_t i = 0; i < 100; i++) {
		b1->ideas[i] = b2->ideas[i];
	}
}

void	printIdeas(str ideas[100]) {
	std::cout << "ideas : [";
	for (size_t i = 0; i < 100; i++) {
		if (ideas[i] != "")
			std::cout << ideas[i] << ", ";
	}
	std::cout << "]" << std::endl;
}

void	testArray(void) {
	Animal *arr[100];

	int i = 0;
	while (i < 50)
		arr[i++] = new Dog();
	while (i < 100)
		arr[i++] = new Cat();

	arr[12]->makeSound();
	arr[78]->makeSound();

	i--;
	while (i >= 0) {
		delete arr[i];
		i--;
	}
}

int main(void)
{
	Cat *c1 = new Cat();

	c1->getBrain()->ideas[0] = "Idea 0";
	printIdeas(c1->getBrain()->ideas);
	
	Cat c2 = *c1;
	printIdeas(c2.getBrain()->ideas);

	c1->getBrain()->ideas[0] = "New Idea !";
	printIdeas(c1->getBrain()->ideas);

	delete c1;
	printIdeas(c2.getBrain()->ideas);

	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << "\n\n" << std::endl;
	testArray();

	return (0);
}
