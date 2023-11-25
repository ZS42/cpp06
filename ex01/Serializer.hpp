/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:15:16 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/25 00:02:32 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define RED "\033[0;31m"
# define GREEN "\033[38:5:2m"
# define BLUE    "\033[34m"
# define RESET "\033[0m"

#include <iostream>
// Dont use <cstdint> bc not std c++98
#include <stdint.h>
#include "Data.hpp"

// class can be uninstaciable by putting constructor in private
// usually put destructor also as private
// Can put copy constructor and copy assignemnet operator as protected
// if we want to access them from the derived classes. Here unnecessary.
class Serializer
{
    private:
        Serializer();
	    Serializer(Serializer const &object);
	    Serializer & operator=(Serializer const & object);
	    ~Serializer(void);
    public:
        // static functions can be called without instantiating the class
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};