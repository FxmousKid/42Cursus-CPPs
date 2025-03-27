/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:08:49 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/27 15:42:18 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream> 
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::time_t	tmp = std::time(0);
	std::tm	*now = std::localtime(&tmp);
	if (now->tm_sec % 3 == 0) {
		A *obj = new A();
		std::cout << "A created\n";
		return dynamic_cast<Base*>(obj);
	}
	else if (now->tm_sec % 3 == 1) {
		B *obj = new B();
		std::cout << "B created\n";
		return dynamic_cast<Base*>(obj);
	}
	else {
		C *obj = new C();
		std::cout << "C created\n";
		return dynamic_cast<Base*>(obj);
	}
}

void	Identify(Base *p)
{
	if (dynamic_cast<A*>(p)) {
		std::cout << "the actual type of the object is A";
		return ;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "the actual type of the object is B";
		return ;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "the actual type of the object is C";
		return ;
	}	
}

void	Identify(Base& p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "the type of the reference is A\n"; return ;}
	catch (std::exception& e) {(void)0;}

	try { (void)dynamic_cast<B&>(p); std::cout << "the type of the reference is B\n"; return ;}
	catch (std::exception& e) {(void)0;}

	try { (void)dynamic_cast<C&>(p); std::cout << "the type of the reference is C\n"; return ;}
	catch (std::exception& e) {(void)0;}

	std::cout << "the type of the reference is unknown\n";
}

int main(void)
{
	Base *obj = generate();	

	Identify(obj);
	std::cout << std::endl;
	Identify(*obj);
	std::cout << std::endl;
	delete obj;
	
	return (EXIT_SUCCESS);
}
