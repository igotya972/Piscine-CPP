/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:18 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/11 15:02:15 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <limits>

class Bureaucrat
{
	private:
	   const std::string _name;
	   int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();
		const std::string getName() const;
		void setGrade(int grade);
		int getGrade() const;
		void upGrade();
		void downGrade();
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
		// void signForm(bool sign);
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
