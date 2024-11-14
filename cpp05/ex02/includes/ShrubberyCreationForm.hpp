/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:13:59 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/08 16:53:15 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
    virtual void execute(const Bureaucrat& executor) const;
};