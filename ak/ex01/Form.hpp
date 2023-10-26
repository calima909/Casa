/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:41:35 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/18 16:47:31 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include"Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_exec;

	public:
		Form(std::string name, int grtosig, int grtoex);
		Form(const Form &src);
		virtual ~Form();
		
		Form &operator=(const Form &rhs);
		std::string getName() const;
		bool getSign() const;
		int getGrToSig() const;
		int getGrToEx() const;
		void beSigned(Bureaucrat stalin);
	
	
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

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
