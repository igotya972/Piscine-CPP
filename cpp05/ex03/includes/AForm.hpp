/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:03:26 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/22 15:16:33 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm 
{
private:
	const std::string _nameForm;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	AForm();
	virtual ~AForm();
	AForm(const AForm& copy);
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm& operator=(const AForm& copy);
	const std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class FormNotUnsigned : public std::exception
	{
		public:
			const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const AForm& form);