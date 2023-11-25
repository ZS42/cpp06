/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:15:07 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/24 23:23:45 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std:: endl;
}

Serializer::Serializer(Serializer const &object)
{
    std::cout << "Serializer copy constructor called" << std:: endl;
    *this = object;
    
}

Serializer & Serializer::operator=(Serializer const & object)
{
    std::cout << "Serializer copy assignment operator called" << std:: endl;
    if (this != &object)
    {
        
    }
    return (*this);
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std:: endl;
    
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}