/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:41:24 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/25 17:14:24 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grtosig, int grtoex) : _name(name), _grade_to_sign(grtosig), _grade_to_exec(grtoex)
{
	if ((grtosig >= 1 && grtosig <= 150) && (grtoex >= 1 && grtoex <= 150))
		_signed = false;
	else if (grtosig < 1 || grtoex < 1)
		throw Form::GradeTooHighException();
	else
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName()), _grade_to_sign(src.getGrToSig()), _grade_to_exec(src.getGrToEx())
{
	_signed = src.getSign();
}

Form::~Form() 
{
	
}


Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs.getSign();
	return(*this);
}

std::string Form::getName() const
{
	return _name;
}

int Form::getGrToEx() const 
{
	return _grade_to_exec;
}

int Form::getGrToSig() const 
{
	return _grade_to_sign;
}

bool Form::getSign() const
{
	return(_signed);
}

void Form::beSigned(Bureaucrat stalin)
{
	if (stalin.getGrade() <= getGrToSig() )
		_signed = true;
	else
		throw Form::GradeTooLowException();
}



std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o  << "Name: " << rhs.getName() << std::endl;
	o  << "Grade to Sign: " << rhs.getGrToSig() << std::endl;
	o  << "Grade to exec: " << rhs.getGrToEx() << std::endl;
	return(o);
}
