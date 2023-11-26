/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:14:47 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/25 18:23:02 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// When a member function of a class is declared as static, it means that the function is 
// associated with the class rather than with instances of the class. 
// Some key points about static member functions are:
// They can be called on the class itself, rather than an instance of the class.
// They cannot access non-static data members or member functions directly because they don't have a specific instance to work with.
// They are not bound to any particular object, so they don't have a 'this' pointer.
// It can be called using MyClass::staticFunction();

// In C++, you can make a class not instantiable by making its constructor private.
// remember default is private

#pragma once

# define RED "\033[0;31m"
# define GREEN "\033[38:5:2m"
# define BLUE    "\033[34m"
# define RESET "\033[0m"

#include <iostream>
#include <cstring>
// #include <cmath>
#include <iomanip> // for std::fixed and std::setprecision 
#include <stdlib.h> // for atoi

// put all constructors destructors private so can't instantiate
class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter &object);
	ScalarConverter &operator=(const ScalarConverter &object);
	~ScalarConverter();
	public:
		static void convert(std::string literal);
};

bool check_is_char(std::string literal, char charValue);
bool check_is_int(std::string literal, int intValue, float floatValue, double doubleValue);
bool check_is_float(std::string literal, int intValue, float floatValue, double doubleValue);
bool check_is_double(std::string literal, int intValue, float floatValue, double doubleValue);