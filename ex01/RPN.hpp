/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:39:00 by mario             #+#    #+#             */
/*   Updated: 2024/01/01 20:51:59 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# define RESET				"\x1b[0m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE 				"\x1b[34m"

# include <iostream>
# include <fstream>
# include <sstream>
# include <stack>
# include <cctype>

class rpn
{

	private:
	
		class BadArgumentException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class BigNumberException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};		
		class TwoNumsException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};		
		class BadOperatorsException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};


	public:
	
	// Constructor and Destructor
	
		rpn();
		rpn(const rpn &a);
		~rpn();
		rpn &operator = (const rpn &a);

	// Functions
	
		static	void	checkinput(const std::string &expression);
		static	void	calculator (const std::string &expression);
		static	void	applyOperator(char op,std::stack<int> &stck);
	
};

#endif