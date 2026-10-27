/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:48:14 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/27 17:02:07 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	private:
		unsigned int	_N;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int i);
		void	addNumbers(std::vector<int>::iterator first,
				std::vector<int>::iterator second);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();

};

#endif
