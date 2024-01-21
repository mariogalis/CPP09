/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:01:10 by mario             #+#    #+#             */
/*   Updated: 2023/12/09 14:05:21 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

# define RESET				"\x1b[0m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE 				"\x1b[34m"

class BitcoinExchange
{
    public:
    
    // Constructor and Destructor
    
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        
    // Functions

        void loadDataBase();
        void readFile(std::string file);
        void calculate(std::string date, float bitcoins);
        int  checkData(int year, int month, int day, float bitcoins, std::string line);       
         
    private:
        std::map<std::string, float> _data;
};


#endif