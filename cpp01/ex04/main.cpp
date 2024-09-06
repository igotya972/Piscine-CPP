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

std::string ft_replace(std::string line, std::string s1, std::string s2)
{
	std::string result;
	size_t pos = 0;
	size_t pos_len = line.find(s1);
	while (pos_len != std::string::npos)
	{
		result += line.substr(pos, pos_len - pos);
		result += s2;
		pos = pos_len + s1.length();
		pos_len = line.find(s1, pos);
	}
	result += line.substr(pos);
	return (result);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace [file_name] [string1] [string2]" << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string line;
	std::ofstream output_file((filename + ".replace").c_str());
	if (!output_file.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		return (1);
	}
	while (std::getline(file, line))
	{
		output_file << ft_replace(line, s1, s2);
		if (!file.eof())
			output_file << std::endl;
	}
	file.close();
	output_file.close();
	return (0);
}