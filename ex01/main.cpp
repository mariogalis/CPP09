/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:38:54 by mario             #+#    #+#             */
/*   Updated: 2024/01/01 19:24:38 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << RED << "ERROR : BAD NUMBER OF ARGUMENTS\n" << RESET; 
		return (-1);
	}
		
	try
	{
	   rpn::checkinput(argv[1]);
	   rpn::calculator(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(-1);
	}
	
}