/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:48:09 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/26 21:38:26 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl; // 2
    std::cout << sp.longestSpan() << std::endl;  // 14

    try
    {
        sp.addNumber(20);
        std::cout << "ERROR: full Span accepted a number\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Full Span: " << e.what() << std::endl;
    }

    try
    {
        Span empty(2);
        empty.shortestSpan();
        std::cout << "ERROR: empty Span returned a distance\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Empty Span: " << e.what() << std::endl;
    }

    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i)
        numbers.push_back(i);

    Span large(10000);
    large.addNumbers(numbers.begin(), numbers.end());
    std::cout << "10,000 numbers: "
              << large.shortestSpan() << ", "
              << large.longestSpan() << std::endl; // 1, 9999

    return 0;
}
