/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:25:56 by dferjul           #+#    #+#             */
/*   Updated: 2024/09/29 21:33:10 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();
		Brain& operator=(const Brain& copy);
};