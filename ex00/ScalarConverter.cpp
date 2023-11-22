/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:14:42 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/22 11:18:34 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void convert(std::string string)
{
	char charValue= static_cast<char>(string);
	int intValue= static_cast<int>(string);
	float floatValue= static_cast<float>(string);
	double doubleValue = static_cast<double>(string);
}