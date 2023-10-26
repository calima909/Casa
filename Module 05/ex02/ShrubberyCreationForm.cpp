/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:36:49 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/26 17:05:01 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Base Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
	this->target = src.getTarget();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = toCopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget()const
{
	return target;
}

void ShrubberyCreationForm::setTarget(const std::string &target)
{
    this->target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
		this->setTarget(rhs.getTarget());
	return(*this);
}

/* void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(!this->getIsSigned())
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    std::ofstream file(this->target + "_shrubbery", std::ios::out | std::ios::trunc);
    if (!file)
        throw AForm::GradeTooLowException();
    file << "      .d8888b.   .d8888b.  .d8888b.  .d8888b.  .d8888b.  .d8888b.  .d8888b. " << std::endl;
    file << "      d88P  Y88b d88P  Y88b d88P  Y88b d88P  Y88b d88P  Y88b d88P  Y88b" << std::endl;
    file << "      888    888 888    888 888    888 888    888 888    888 888    888" << std::endl;
    file << "      888    888 888    888 888    888 888    888 888    888 888    888" << std::endl;
    file << "      888    888 888    888 888    888 888    888 888    888 888    888" << std::endl;
    file.close();
    
} */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getGradeExec() && getGradeSign())
	{
		std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
		ofs << "my-app/\n├─ node_modules/\n├─ public/\n├─ favicon.ico\n│  ├─ index.html\n│  ├─ robots.txt\n├─ src/\n│  ├─ README.md\n│  ├─ index.css\n│  ├─ index.js\n├─ .gitignore\n├─ package.json\n"<<"\n";
		ofs << std::endl;
		for (int i = 0; i < 3; i++)
		{
			ofs << std::endl;
			ofs << "   ^" << std::endl;
			ofs << "  ^^^" << std::endl;
			ofs << " ^^^^^" << std::endl;
			ofs << "^^^^^^^" << std::endl;
			ofs << "   |" << std::endl;
			ofs << std::endl;
		}
		ofs.close();
	}
	else if (!getSign())
		throw ShrubberyCreationForm::NotSignedException();
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}
