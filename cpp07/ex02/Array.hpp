/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:32:58 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/05 02:41:18 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ctime>
#include <iostream>
#include <cstdlib>

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
		Array(Array const &copy) : _size(copy.size())
		{
			_size = copy.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		};
		~Array()
		{
			delete[] _array;
		};
		Array &operator=(Array const &copy)
		{
			if (this != &copy)
			{
				delete[] _array;
				_size = copy.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = copy._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int n)
		{
			if (n >= this->_size)
				throw ArrayException();
			return _array[n];
		};
		unsigned int size() const
		{
			return _size;
		};
		class ArrayException : public std::exception
		{
			const char *what() const throw()
			{
				return "Error: out of range";
			}
		};
};