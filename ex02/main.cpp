/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:28:59 by mario             #+#    #+#             */
/*   Updated: 2024/01/21 18:56:26 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

unsigned int tmp;

template <typename T, typename S, typename V>
void FJAlgorithm(int argc, T &container, S &cont, V &conta, char choice, bool flag) 
{
    typedef typename T::iterator TIterator;
    typedef typename S::iterator SIterator;
    typedef typename V::iterator VIterator;

    std::clock_t start = std::clock();

	// Cogemos por parejas y los ordenamos
    for (TIterator it = container.begin(); it != container.end(); ++it) 
	{
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }

	// Metemos el pequenio en el container 'conta' y el mas grande en el 'cont'
    for (TIterator it = container.begin(); it != container.end(); ++it) 
	{
        conta.push_back((*it).first);
        cont.push_back((*it).second);
    }
	
    std::sort(conta.begin(), conta.end());

    // Mergeamos el segundo contenedor en el primero ya ordena
    for (SIterator it = cont.begin(); it != cont.end(); ++it) 
	{
        VIterator vit = std::lower_bound(conta.begin(), conta.end(), *it);
        conta.insert(vit, *it);
    }

    // Si son impares metemos el que sobra
    if (flag) 
	{
        VIterator vit = std::lower_bound(conta.begin(), conta.end(), tmp);
        conta.insert(vit, tmp);
    }

    std::clock_t end = std::clock();
    long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;

    if (!flag)
        argc--;

    if (choice == 'v')
	{
        std::cout << "\nAfter  : ";
        size_t outputSize = std::min<size_t>(5, conta.size());
        for (size_t i = 0; i < outputSize; i++)
            std::cout << conta[i] << " ";
        if (conta.size() > 5)
            std::cout << "[...]\n";
    }

    std::string containerType = (choice == 'v') ? "std::vector" : "std::deque";
    std::cout << "\nTime to process a range of " << argc << " elements with " << containerType << " : " << duration << " us\n\n";
}


void	VectorMode(int argc, char *argv[], bool flag)
{
	std::vector<std::pair<unsigned int, unsigned int> > vec;
	
	for (int i = 1; i < argc; i+=2)
		vec.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
	std::vector<unsigned int> vec_a, vec_b;
	FJAlgorithm(argc, vec, vec_a, vec_b, 'v', flag);
}

void	DequeMode(int argc, char *argv[], bool flag)
{
	std::deque<std::pair<unsigned int, unsigned int> > dec;
	for (int i = 1; i < argc; i+=2)
		dec.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
	std::deque<unsigned int> dec_a, dec_b;
	FJAlgorithm(argc, dec, dec_a, dec_b, 'd', flag);
}

void	checkfirst(int argc, char *argv[])
{
	if(argc > 1)
		argc -= 1;
	if(argc == 1)
		throw ft_exception("Wrong Number of Arguments, numbers must be in diferent arguments");
	for(int i = 1; i <= argc; i++)
	{
		for(int j = 0; j <= (int)strlen(argv[i]) - 1; j++)
			if((argv[i][j] < '0' || argv[i][j] > '9'))
				if(argv[i][j] != ' ')
					throw ft_exception("Wrong Arguments");
	}
}

int		main(int argc, char *argv[])
{
	bool flag = false;
	
	try 
	{
		checkfirst(argc, argv);
	} 
	catch (const ft_exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		exit(0);
	}

	std::cout << "\nBefore : "; 
	
	if (argc < 7)
		for (int i = 1; i < argc; i++)
			std::cout << argv[i] << " ";
	else
	{
		for (int i = 1; i < 6; i++)
			std::cout << argv[i] << " ";
		std::cout << "[...]";
	}
	
	if ((argc - 1) % 2 != 0)
	{
		flag = true;
		tmp = std::atoi(argv[argc - 1]);
		argc-=1;
	}

	VectorMode(argc, argv, flag);
	DequeMode(argc, argv, flag);
}
