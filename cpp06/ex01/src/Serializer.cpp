/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:42:20 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 02:19:48 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &)
{
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}