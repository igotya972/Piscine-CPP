/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:32:58 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/04 02:18:13 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		Array()
		{
			_array = new T[0];
			_size = 0;
		};
		Array(unsigned int n)
		{
			_array = new T[n];
			_size = n;
		};
		Array(Array const &src) : _size(src.size())
		{
			_size = src.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		};
		~Array()
		{
			delete[] _array;
		};
		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete[] _array;
				_size = rhs.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int n)
		{
			if (n >= this->_size)
				throw std::exception();
			return _array[n];
		};
		unsigned int size() const
		{
			return _size;
		};
};