/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 08:52:00 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/22 08:52:37 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(10);

	try
	{
		std::vector<int>::iterator found = easyfind(numbers, 20);
		std::cout << "First match: " << *found << std::endl;
		std::cout << "Index: " << (found - numbers.begin()) << std::endl;
		easyfind(numbers, 42);
	}
	catch (const NotFoundException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> values;
	values.push_back(3);
	values.push_back(7);
	std::cout << "List match: " << *easyfind(values, 7) << std::endl;

	return (0);
}
