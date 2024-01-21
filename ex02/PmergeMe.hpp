/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:39:33 by mario             #+#    #+#             */
/*   Updated: 2024/01/21 16:20:38 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# define RESET				"\x1b[0m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE 				"\x1b[34m"

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h> 

class PmergeMe
{
	private:
	
	public:
		PmergeMe ();
		PmergeMe (const PmergeMe &other);
		~PmergeMe ();
		PmergeMe & operator = (const PmergeMe &other);
};

class ft_exception : public std::exception 
{
private:
    const char* message;

public:
    ft_exception(const char* msg) : message(msg) {}

    const char* what() const throw() 
	{
        return message;
    }
};

#endif
