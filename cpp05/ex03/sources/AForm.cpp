/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:43:06 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/22 15:17:28 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _nameForm("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	_signed = false;
}

AForm::AForm(const AForm& copy) : _nameForm(copy.getName()), _signed(copy.getSigned()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute())
{
	*this = copy;
}

AForm::~AForm() {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _nameForm(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << this->_nameForm << " grade: " << this->_gradeToSign << " Constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
	_signed = false;
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		_signed = copy.getSigned();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute();
	return os;
}

const std::string AForm::getName() const
{
	//std::cout << "getName function called" << std::endl;
	return this->_nameForm;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "\033[1;31mGrade of Form is too high\033[0m";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "\033[1;31mGrade of Form is too low\033[0m";
}

const char* AForm::FormNotUnsigned::what() const throw()
{
	return "\033[1;31mForm is not signed\033[0m";
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
		throw AForm::FormNotUnsigned();
}