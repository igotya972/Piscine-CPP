/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:23:12 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/08 16:42:29 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
    void execute(const Bureaucrat& executor) const;
};