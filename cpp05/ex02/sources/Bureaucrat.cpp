/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:47 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/21 18:20:46 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	//std::cout << this->_name << " Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	//std::cout << this->_name << " grade: " << this->_grade << " Constructor called" << std::endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		_grade = copy.getGrade();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const std::string Bureaucrat::getName() const
{
	//std::cout << "getName function called" << std::endl;
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[1;31mGrade too high\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[1;31mGrade too low\033[0m";
}

void Bureaucrat::upGrade()
{
	this->_grade--;
	if (this->_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::downGrade()
{
	this->_grade++;
	if (this->_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\033[1;32m" << this->_name << " signs " << form.getName() << "\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[1;31m" << this->_name << " cannot sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "\033[1;32m" << this->_name << " executes " << form.getName() << "\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[1;31m" << this->_name << " cannot execute " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}
