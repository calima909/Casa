/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:05:31 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/21 13:22:24 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src) : AForm(src.getName(), src.getGrToSig(), src.getGrToEx())
{
	this->_target = src.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		this->setTarget(rhs.getTarget());
	return(*this);
}

std::string RobotomyRequestForm::getTarget()const
{
	return _target;
}

void RobotomyRequestForm::setTarget(std::string target)
{
	_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(0));
	if (executor.getGrade() <= getGrToEx() && getSign())
	{
		std::cout << "some drilling noises" << std::endl;
		if (( rand() % 2) == 1)
			std::cout << getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "robotomy failed" << std::endl;
	}
	else if (!getSign())
		throw RobotomyRequestForm::NotSignedException();
	else
	{
		throw RobotomyRequestForm::GradeTooLowException();
	}
}
