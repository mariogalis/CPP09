/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:39:35 by mario             #+#    #+#             */
/*   Updated: 2024/01/01 20:40:19 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe (){}
PmergeMe::PmergeMe (const PmergeMe &other)
{
        this->operator=(other);
}
PmergeMe::~PmergeMe (){}

PmergeMe & PmergeMe::operator = (const PmergeMe &other)
{
        (void)other;
        return(*this);
}

