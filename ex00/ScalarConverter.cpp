/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:14:42 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/25 00:49:13 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called." << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &object)
{
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = object;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &object)
{
	if (this != &object)
    {
        
    }
    return (*this);
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called." << std::endl;
}

// use static storage class only in class definition
void ScalarConverter::convert(std::string literal)
{
	char charValue= static_cast<char>(literal);
	int intValue= static_cast<int>(literal);
	float floatValue= static_cast<float>(literal);
	double doubleValue = static_cast<double>(literal);
}