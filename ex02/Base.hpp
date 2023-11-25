/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:15:25 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/25 02:28:46 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# define RED_LIGHT "\033[1;38:5:131m"
# define RED "\033[0;31m"
# define GREEN "\033[38:5:2m"
# define MUSTARD "\033[38:5:136m"
# define RESET "\033[0m"

#include <iostream>
#include <stdlib.h> //for new 
#include <stdexcept> //for exceptions
// #include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"

class Base
{
    public:
        virtual ~Base();
};

class A : virtual public Base
{
    
};

class B : virtual public Base
{
    
};

class C : virtual public Base
{
    
};
#endif