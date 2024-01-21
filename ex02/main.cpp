/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:28:59 by mario             #+#    #+#             */
/*   Updated: 2024/01/01 20:50:50 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int     main(int argc, char *argv[])
{
    try 
    {
        if(argc !=2)
            throw ft_exception("Wrong Number of Arguments");
        else
            std::cout << argv[1] << std::endl;
    } 
    catch (const ft_exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
}