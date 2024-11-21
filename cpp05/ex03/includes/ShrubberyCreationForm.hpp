/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:13:59 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/21 18:38:17 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	virtual void execute(const Bureaucrat& executor) const;
};