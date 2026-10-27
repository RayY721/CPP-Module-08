/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:51:31 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/27 08:48:28 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"
#include <cassert>
#include <iostream>
#include <stack>

int main()
{
	MutantStack<int> mstack;
	assert(mstack.begin() == mstack.end());
	mstack.push(5);
	mstack.push(17);
	assert(mstack.top() == 17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	assert(mstack.size() == 1 && mstack.top() == 5);
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	int expected[] = {5, 3, 5, 737, 0};
	int index = 0;
	++it;
	--it;
	while (it != ite)
	{
		assert(index < 5 && *it == expected[index]);
		std::cout << *it << std::endl;
		++it;
		++index;
	}
	assert(index == 5);
	std::stack<int> s(mstack);
	assert(s.size() == mstack.size() && s.top() == mstack.top());
	MutantStack<int> copied(mstack);
	const MutantStack<int> const_stack(copied);
	MutantStack<int>::const_iterator cit = const_stack.begin();
	assert(cit != const_stack.end() && *cit == 5);
	MutantStack<int> assigned;
	assigned = mstack;
	MutantStack<int> &self = assigned;
	assigned = self;
	assert(copied.size() == 5 && copied.top() == 0);
	assert(assigned.size() == 5 && assigned.top() == 0);
	mstack.pop();
	assert(mstack.top() == 737);
	assert(copied.top() == 0 && assigned.top() == 0);
	return 0;
}
