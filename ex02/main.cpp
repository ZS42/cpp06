/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:05:39 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/25 02:36:00 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.
// If the cast fails and new-type is a reference type, it throws an
// exception that matches a handler of type std::bad_cast.
void identify(Base& p)
{
    
    try
    {
        A &concrete = dynamic_cast<A&>(p);
        std::cout << GREEN << "Object is type A" << RESET << std::endl;
        (void)concrete;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        B &concrete = dynamic_cast<B&>(p);
        std::cout << GREEN << "Object is type B" << RESET << std::endl;
        (void)concrete;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        C &concrete = dynamic_cast<C&>(p);
        std::cout << GREEN << "Object is type C" << RESET << std::endl;
        (void)concrete;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << MUSTARD << "Object is type A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << MUSTARD << "Object is type B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << MUSTARD << "Object is type C" << RESET << std::endl;
    
}

// // It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// // to use anything you like for the random choice implementation.
Base* generate(void)
{
    Base *base = NULL;
    
	srand(time(NULL));
    int randomValue = std::rand() % 3 + 1; // Generate random number between 1 and 3

    switch (randomValue) {
        case 1: {
            base = new A;
            break;
        }
        case 2: {
            base = new B;
            break;
        }
        case 3: {
            base = new C;
            break;
        }
        default:
            std::cerr << "Unexpected random value." << std::endl;
            break;
    }
    return base;
}

int main(void)
{
    Base *base = NULL;
    try
    {
        base = generate();
        identify(base);
        identify(*base);
        delete(base);   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
