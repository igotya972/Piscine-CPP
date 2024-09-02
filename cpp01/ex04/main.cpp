/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:37:27 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/26 22:37:27 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace [filename] [string1] [string2]" << std::endl;
		return 1;
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string line;
	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << "Error: could not create output file" << std::endl;
		return 1;
	}
	while (std::getline(file, line))
	{
		std::size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		output << line << std::endl;
	}
	file.close();
	output.close();
	return 0;
}