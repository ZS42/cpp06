/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:40:37 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/26 18:29:40 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool check_is_char(std::string literal, char charValue)
{
    int literalLen = literal.size();
    if (literalLen == 1)
    {
        if ((literal[0] >= 32 && literal[0] < 48) || (literal[0] >= 58 && literal[0] < 127))
        {
            charValue = literal[0];
            std::cout << GREEN << "char: " << charValue << RESET << std::endl;
            std::cout << BLUE << "int: impossible" << RESET << std::endl;
            std::cout << BLUE << "float: impossible" <<  RESET << std::endl;
            std::cout << BLUE << "double: impossible" << RESET << std::endl;
            return (true);
        }
    }
    return (false);
}

// std::fixed sets the floatfield format flag for the str stream to fixed.
// When floatfield is set to fixed, floating-point values are written using fixed-point notation: 
// the value is represented with exactly as many digits in the decimal part as specified by the 
// precision field (precision) and with no exponent part.

// std::setprecision sets the decimal precision to be used to format floating-point values on output operations.
bool check_is_int(std::string literal, int intValue, float floatValue, double doubleValue)
{
    int literalLen = literal.size();
    int i = 0;
    while( i < literalLen)
    {
        if (!isdigit(literal[i]))
            return (false);
        i++;
    }
    intValue = std::atoi(literal.c_str());
    // c_str() converts to c type string so can use atoi but pointer returned should only be used once
    std::cout << BLUE << "char:  Non displayable" << RESET << std::endl;
    std::cout << GREEN << "int: " << intValue << RESET << std::endl;
    floatValue = static_cast<float>(intValue);
    std::cout << GREEN  << "float: "  << std::fixed << std::setprecision(1) <<  floatValue << "f" <<RESET << std::endl;
    doubleValue = static_cast<double>(intValue);
    std::cout << GREEN  << "double: " << doubleValue << RESET << std::endl;
    return (true);
    
}

bool check_is_float(std::string literal, int intValue, float floatValue, double doubleValue)
{
    int literalLen = literal.size();
    int i = 0;
    if (literal == "-inff" || literal == "+inff"||literal == "nanf")
    {
        std::cout << BLUE << "char:  Non displayable" << RESET << std::endl;
        std::cout << BLUE  << "int: impossible" << RESET << std::endl;
        floatValue = std::atof(literal.c_str());
        std::cout << GREEN << "float: "  << std::fixed << std::setprecision(1) <<  floatValue << "f" <<RESET << std::endl;
        doubleValue = static_cast<double>(floatValue);
        std::cout << GREEN  << "double: " << doubleValue << RESET << std::endl;
        return(true);
    }
    if (literal.at(literalLen - 1) != 'f')
        return (false);
    if (literal.at(0) == '+' || literal.at(0) == '-')
        i = 1;
    while( i < literalLen - 1)
    {
        if (!isdigit(literal[i]) && literal[i] != '.')
            {std::cout <<"float"<< std::endl;
            return (false);}
        i++;
    }
    floatValue = std::atof(literal.c_str());
    // c_str() converts to c type string so can use atoi but pointer returned should only be used once
    std::cout << GREEN << "char:  '" << static_cast<char>(floatValue) << "'"<< RESET << std::endl;
    intValue = static_cast<int>(floatValue);
    std::cout << GREEN  << "int: " << intValue << RESET << std::endl;
    floatValue = (intValue);
    std::cout << GREEN << "float: "  << std::fixed << std::setprecision(1) <<  floatValue << "f" <<RESET << std::endl;
    doubleValue = static_cast<double>(floatValue);
    std::cout << GREEN  << "double: " << doubleValue << RESET << std::endl;
    return (true);
}

bool check_is_double(std::string literal, int intValue, float floatValue, double doubleValue)
{
    int literalLen = literal.size();
    int i = 0;
    if (literal == "-inf" || literal == "+inf"||literal == "nan")
    {
        std::cout << BLUE << "char:  impossible" << RESET << std::endl;
        std::cout << BLUE  << "int: impossible" << RESET << std::endl;
        doubleValue = std::atof(literal.c_str());
        floatValue = static_cast<double>(doubleValue);
        std::cout << GREEN << "float: "  << std::fixed << std::setprecision(1) <<  floatValue << "f" <<RESET << std::endl;
        doubleValue = static_cast<double>(floatValue);
        std::cout << GREEN  << "double: " << doubleValue << RESET << std::endl;
        return(true);
    }
    if (literal.at(0) == '+' || literal.at(0) == '-')
        i = 1;
    while( i < literalLen - 1)
    {
        if (!isdigit(literal[i]) && literal[i] != '.')
            {std::cout <<"float"<< std::endl;
            return (false);}
        i++;
    }
    doubleValue = std::atof(literal.c_str());
    // c_str() converts to c type string so can use atoi but pointer returned should only be used once
    std::cout << BLUE << "char:  Non displayable" << RESET << std::endl;
    intValue = static_cast<int>(doubleValue);
    std::cout << GREEN  << "int: " << intValue << RESET << std::endl;
    floatValue = static_cast<double>(doubleValue);
    std::cout << GREEN << "float: "  << std::fixed << std::setprecision(1) <<  floatValue << "f" <<RESET << std::endl;
    std::cout << GREEN  << "double: " << doubleValue << RESET << std::endl;
    return (true);
}

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Please enter a scalar value to be converted" << std::endl;
    else
    {
        // coverting av[1] to c++type string
        std::string literal(av[1]); 
        ScalarConverter::convert(literal);
    }
}

// sample output
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0