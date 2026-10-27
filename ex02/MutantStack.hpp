/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:51:33 by kuyu              #+#    #+#             */
/*   Updated: 2026/10/27 08:58:12 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		
			MutantStack() {}
			MutantStack(const MutantStack &other) : std::stack<T>(other) {}
			MutantStack &operator=(const MutantStack &other)
			{
				if (this != &other)
					std::stack<T>::operator=(other);
				return *this;
			}
			~MutantStack() {}

			iterator	begin() { return this->c.begin(); }
			iterator	end() { return this->c.end(); }
			const_iterator	begin() const { return this->c.begin(); }
			const_iterator	end() const { return this->c.end(); }
};

#endif
