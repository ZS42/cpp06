/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:41:58 by zsyyida           #+#    #+#             */
/*   Updated: 2023/11/25 00:41:08 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// The reinterpret_cast operator in C++ is a powerful but potentially dangerous casting 
// mechanism that allows you to convert any pointer type to any other pointer type. 
// It can also be used to convert between pointer types and integral types. The size in memory of both should be the same. However, 
// its use should be approached with caution because it can lead to undefined behavior if not used carefully.
// The data address is the same. The data memory is the same . We are just calling it something else using serialise (reinterpret_data cast)
// if the low level casting between unrelated types involves polymorphism use dynamic cast.
// Static_cast is also safer
// https://www.youtube.com/watch?v=pWZS1MtxI-A
int main(void)
{
    Data data;
    data.number_students = 12;
    Data *data_ptr = &data;
    uintptr_t intptr;

    std::cout << RED << "[DATAPTR] is " << data_ptr << RESET <<std::endl;
    std::cout << BLUE << "[DATAPTR] value is " << data_ptr->number_students << RESET <<std::endl;
    intptr = Serializer::serialize(data_ptr);
    std::cout << BLUE << "[uintptr] is " << intptr << RESET << std::endl;
    data_ptr = Serializer::deserialize(intptr);
    std::cout << RED << "[DATAPTR] is now " << data_ptr << RESET <<std::endl;
    std::cout << BLUE << "[DATAPTR] value is " << data_ptr->number_students << RESET <<std::endl;
    intptr = Serializer::serialize(data_ptr);
    std::cout << BLUE << "[uintptr] is " << intptr << RESET << std::endl;
    return (0);
}

// Sample output:
// [DATAPTR] is 0x16f6db358
// [DATAPTR] value is 12
// [uintptr] is 6164427608
// [DATAPTR] is now 0x16f6db358
// [DATAPTR] value is 12


// 6164427608 is decimal representation of 16f6db358
// showing both point to the same address