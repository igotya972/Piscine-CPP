/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:45:45 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 17:52:47 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
class Base
{
public:
	virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);