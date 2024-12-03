/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:42:09 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 18:02:07 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <stdint.h>

struct Data
{
	std::string	_name;
	int			_value;
	Data(std::string name, int value);
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer &operator=(const Serializer &);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};
