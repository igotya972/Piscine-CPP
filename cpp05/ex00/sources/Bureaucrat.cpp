/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:47 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/22 15:23:05 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	// std::cout << "Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	// std::cout << "Constructor with name and grade called" << std::endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
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
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
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
