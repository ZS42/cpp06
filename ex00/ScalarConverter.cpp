/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:14:42 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/26 18:00:51 by zsyyida          ###   ########.fr       */
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
	char charValue = '\0';
	int intValue = 0;
	float floatValue = 0.0;
	double doubleValue = 0.0;

	if (check_is_char(literal, charValue))
		return ;
	if (check_is_int(literal, intValue, floatValue, doubleValue))
		return ;
	if (check_is_float(literal, intValue, floatValue, doubleValue))
		return ;
	if (check_is_double(literal, intValue, floatValue, doubleValue))
		return ;
	std::cout << RED << "Literal is not a char or an int or a float or a double" << RESET << std::endl;	
}