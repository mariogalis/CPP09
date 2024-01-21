/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:01:12 by mario             #+#    #+#             */
/*   Updated: 2024/01/21 18:20:45 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors and Destructor

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->operator=(copy);
}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	(void)copy;
	return (*this);
}

// Functions

void BitcoinExchange::loadDataBase()
{

	std::ifstream input;
	std::string database;

	input.open("./data.csv");

	if (input.fail())
	{
		std::cerr << RED << "Error: data.csv not found." << std::endl << RESET;
		exit(0);
	}
	while (!input.eof())
	{
		input >> database;
		std::string fulldate = database.substr(0, 10).erase(4, 1).erase(6, 1);
		float rate = 0.0;
		std::stringstream convert;
		convert << database.substr(11);
		convert >> rate;
		_data.insert(std::make_pair(fulldate, rate));
	}
	input.close();
}

void BitcoinExchange::readFile(std::string file)
{
	std::ifstream infile;
	std::string line;

	infile.open(file);

	if (infile.fail())
		std::cerr << RED << "Error: " << file << " not found." << std::endl << RESET;

	while (!infile.eof())
	{
		std::string fulldate;
		std::getline(infile, line);

		if (line == "" || line.length() < 14)
		{
			std::cerr << RED << "Error: bad line => " << line << std::endl << RESET;
			continue;
		}

		int year, month, day = 0;

		year = std::stoi(line.substr(0, 4));
		month = std::stoi(line.substr(5, 2));
		day = std::stoi(line.substr(8, 2));
		fulldate = line.substr(0, 10).erase(4, 1).erase(6, 1);
		
		std::string bitcoins = line.substr(13, line.find('\0'));
		float bitcoinsf = std::stof(bitcoins);

		if (checkData(year, month, day, bitcoinsf, line) == 0)
			calculate(fulldate, bitcoinsf);
	}
	infile.close();
	exit(0);
}

int BitcoinExchange::checkData(int year, int month, int day, float bitcoins, std::string line)
{
	int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	size_t idx = line.find("|");

	if (line[idx + 1] != ' ' || line[idx - 1] != ' ')
	{
		std::cerr << RED << "Invalid Pipe" << std::endl << RESET;
		return (-1);
	}

	if (line.substr(4, 1) != "-" && line.substr(7, 1) != "-")
	{
		std::cerr << RED << "Invalid Date Format" << std::endl << RESET;
		return (-1);
	}

	if (year < 2009 || month < 1 || month > 12)
	{
		std::cerr << RED << "Invalid Date Format" << std::endl << RESET;
		return (-1);
	}

	if (day > month_limits[month - 1] || day < 1)
	{
		std::cerr << RED << "Out of month range" << std::endl << RESET;
		return (-1);
	}
	
	if (bitcoins < 0.00 || bitcoins > 1000.00)
	{
		std::cerr << RED << "Error: too large a number." << std::endl << RESET;
		return (-1);
	}
	
	return (0);
}

void BitcoinExchange::calculate(std::string date, float bitcoins)
{

    std::map<std::string, float>::iterator it = this->_data.find(date);

    if (it != this->_data.end())
    {
        std::cout << GREEN << date.insert(4, "-").insert(7, "-") << " => " << bitcoins << " = " << std::fixed << std::setprecision(2) << bitcoins * it->second << std::endl << RESET;
    }
    else
    {
        it = this->_data.lower_bound(date);
        std::cout << GREEN << date.insert(4, "-").insert(7, "-") << " => " << bitcoins << " = " << std::fixed << std::setprecision(2) << bitcoins * it->second << std::endl << RESET;
    }
}
