/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:41:14 by inazaria          #+#    #+#             */
/*   Updated: 2025/03/22 19:03:31 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void testForms() {
    std::cout << "===== Testing Form Class =====" << std::endl;

    // ✅ **Valid Form Creation**
    try {
        Form taxForm("Tax Declaration", 50, 25);
        std::cout << taxForm << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing Invalid Form Creation =====" << std::endl;

    // ❌ **Grade Too High**
    try {
        Form invalidForm1("Impossible Form", 0, 10);  // Invalid: sign grade too high
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ❌ **Grade Too Low**
    try {
        Form invalidForm2("Useless Form", 151, 100);  // Invalid: sign grade too low
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing Form Signing =====" << std::endl;

    // ✅ **Successful Signing**
    try {
        Bureaucrat alice("Alice", 30);
        Form report("Quarterly Report", 50, 25);
        std::cout << report << std::endl;
        alice.signForm(report);
        std::cout << report << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing Signing with Insufficient Grade =====" << std::endl;

    // ❌ **Bureaucrat Can't Sign (Grade Too Low)**
    try {
        Bureaucrat bob("Bob", 100);
        Form contract("Business Contract", 50, 25);
        std::cout << contract << std::endl;
        bob.signForm(contract);  // Should fail
        std::cout << contract << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}


int main() {
    testForms();
    return 0;
}
