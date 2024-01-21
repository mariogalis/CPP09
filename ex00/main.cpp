/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:01:07 by mario             #+#    #+#             */
/*   Updated: 2023/12/09 13:07:58 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
    BitcoinExchange btc;
    
    if(argc != 2)
    {
        std::cerr << RED << "ERROR : Bad number of arguments" << std::endl << RESET;
        return(-1);
    }
    
    btc.loadDataBase();
    btc.readFile(argv[1]);
    return 0;
}