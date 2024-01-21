/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:01:07 by mario             #+#    #+#             */
/*   Updated: 2024/01/21 18:23:35 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Usamos el container map para tener una clave y un valor, en este caso la clave sera la fecha y el valor, el precio del btc

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
