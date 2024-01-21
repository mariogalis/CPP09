/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:38:57 by mario             #+#    #+#             */
/*   Updated: 2024/01/21 18:50:15 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructor and Destructor

rpn::rpn(){}

rpn::rpn(const rpn &a)
{
	this->operator=(a);
}

rpn::~rpn(){}

rpn & rpn::operator =(const rpn &a)
{
	(void)a;
	return(*this);
}

// Aux Functions

bool     goodoperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == ' ')
		return(true);
	return(false);
}

// Exceptions

const char* rpn::BadArgumentException::what(void) const throw(){ 	return ("Error : BAD ARGUMENT");}
const char* rpn::BigNumberException::what(void) const throw(){ 		return ("Error : NUMBER HIGHER THAN 10");}
const char* rpn::TwoNumsException::what(void) const throw(){ 		return ("Error : OPERATION MUST START WITH TWO NUMBERS FIRST");}
const char* rpn::BadOperatorsException::what(void) const throw(){	return ("Error : BAD NUMBER OF OPERATORS OR NUMBERS");}

// Functions

void	rpn::checkinput(const std::string &expression)
{
	int dig = 0, op = 0;

	for(int i = 0; expression[i] ; i++)
	{
		if (!isdigit(expression[i]) && !goodoperator(expression[i]))
			throw(BadArgumentException());

		if (isdigit(expression[i]) && isdigit(expression[i + 1]))
			throw(BigNumberException());
			
		if (isdigit(expression[i]))
			dig++;

		if (goodoperator(expression[i]) && expression[i] != ' ')
		{
			if (dig < 2)
				throw (TwoNumsException());
			else 
				op++;
		} 
	}
	if(dig != op + 1)
		throw(BadOperatorsException());
}

 void 	rpn::applyOperator(char op, std::stack<int> &stck) 
 {
		int res = stck.top();
		stck.pop();

		switch (op) 
		{
			case '+':
				res = stck.top() + res;
				break;
			case '-':
				res = stck.top() - res;
				break;
			case '*':
				res = stck.top() * res;
				break;
			case '/':
				if (res == 0) 
					throw (BadArgumentException());
				res = stck.top() / res;
				break;
			default:
				throw (BadArgumentException());
		}

		stck.pop();
		stck.push(res);
	}
	
	void rpn::calculator(const std::string &input) 
	{
		std::stack<int> stck;
		std::string operators = "+-*/";
		size_t num = 0;

		for (size_t i = 0; i < input.length(); ++i) 
		{
			if (isdigit(input[i]))
			{
				num++;
				stck.push(input[i] - '0');
			}
			else if (operators.find(input[i]) != std::string::npos) 
				applyOperator(input[i], stck);
			else if (!isspace(input[i])) 
				throw (BadArgumentException());
		}

		if (num == 0 || num == stck.size() - 1) 
			throw std::invalid_argument("Invalid Input");
			
		std::cout << stck.top() << std::endl;
	}
