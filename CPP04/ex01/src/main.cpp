/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:37:19 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/01 01:14:53 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

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

int main(void)
{
	Cat		c1;
	Cat		c2;
	Brain	b;

	b.ideas[0] = "idea0";
	b.ideas[1] = "idea1";

	brainCopy(c1.getBrain(), &b);
	Brain c1b = *c1.getBrain();
	printIdeas(c1b.ideas);

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return (0);
}
