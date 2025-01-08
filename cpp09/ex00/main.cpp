/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:59 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/08 02:15:18 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc [filename]" << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	(void)av;
	try
	{
		btc.loadDatabase(std::string("data/data.csv"));
		
		btc.loadInputFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	return (0);
}