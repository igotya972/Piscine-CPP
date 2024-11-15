/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:43:06 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/15 01:05:41 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _nameForm("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
	//std::cout << this->_nameForm << " Constructor called" << std::endl;
}

Form::Form(const Form& copy) : _nameForm(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Form::~Form()
{
	//std::cout << "Destructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _nameForm(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << this->_nameForm << " grade: " << this->_gradeToSign << " Constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		_signed = copy.getSigned();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute();
	return os;
}

const std::string Form::getName() const
{
	//std::cout << "getName function called" << std::endl;
	return this->_nameForm;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Form::signForm(Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		std::cout << bureaucrat.getName() << " signs " << this->_nameForm << std::endl;
	}
	else
	{
		std::cout << bureaucrat.getName() << " cannot sign " << this->_nameForm << " because his grade is too low" << std::endl;
	}
}