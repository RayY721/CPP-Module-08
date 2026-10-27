/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:48:12 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/27 17:08:59 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span() :_N(0) {}

Span::Span(unsigned int n) : _N(n) {}

Span::Span(const Span &other) :_N(other._N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_N = other._N;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int i) 
{
	if (this->_numbers.size() >= _N)
		throw std::length_error("Span is full");
	this->_numbers.push_back(i);
}

void	Span::addNumbers(std::vector<int>::iterator first,
		std::vector<int>::iterator second)
{
	std::vector<int>	pending(first, second);

	if (pending.size() > _N - this->_numbers.size())
		throw std::length_error("Span is full");
	_numbers.insert(_numbers.end(), pending.begin(), pending.end());
}

unsigned int	Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::logic_error("Need at least two numbers");
	std::vector<int>	temvec = this->_numbers;
	std::sort(temvec.begin(), temvec.end());
	unsigned int	shortest =
		static_cast<unsigned int>(temvec[1]) -
		static_cast<unsigned int>(temvec[0]);
	for (unsigned int i = 1; i < temvec.size(); i++)
	{
		unsigned int	distance =
			static_cast<unsigned int>(temvec[i]) -
			static_cast<unsigned int>(temvec[i - 1]);
		if (distance < shortest)
			shortest = distance;
	}
	return shortest;
}

unsigned int	Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::logic_error("Need at least two numbers");
	std::vector<int>	temvec = this->_numbers;
	std::sort(temvec.begin(), temvec.end());
	return static_cast<unsigned int>(temvec[temvec.size() - 1]) -
			static_cast<unsigned int>(temvec[0]);
}
