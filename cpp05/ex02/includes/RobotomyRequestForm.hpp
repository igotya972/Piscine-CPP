/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:23:12 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/21 18:37:06 by dferjul          ###   ########.fr       */
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
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	virtual void execute(const Bureaucrat& executor) const;
};