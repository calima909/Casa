/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:50:32 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/18 16:41:53 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		virtual ~Bureaucrat();
		
		Bureaucrat &operator=(const Bureaucrat &rhs);
		std::string getName() const;
		int getGrade() const;
		
		void incrGrade();
		void decrGrade();
		void signForm(AForm *form);
		void executeForm(AForm const &form);
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Grade too High"; }
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};
};


std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
