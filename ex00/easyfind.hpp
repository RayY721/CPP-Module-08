/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 23:32:48 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/22 08:48:59 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("The target is not found");
		}
};

template <typename T>
typename T::iterator	easyfind(T &t, int i)
{
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), i);
	if (it == t.end())
		throw NotFoundException();
	return (it);
}

#endif
