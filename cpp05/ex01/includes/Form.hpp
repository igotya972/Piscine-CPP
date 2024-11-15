/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:03:26 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/14 20:53:50 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form 
{
private:
	const std::string _nameForm;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	Form();
	~Form();
	Form(const Form& copy);
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form& operator=(const Form& copy);
	const std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void signForm(Bureaucrat& Bureaucrat) const;
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Form& form);