/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:35:48 by jpizarro          #+#    #+#             */
/*   Updated: 2023/02/19 22:21:40 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>

# define NO 0
# define YES 1

class	Contact {

public:

	Contact( int init = NO);
	~Contact( void );

	std::string
		firstName,
		lastName,
		nickname,
		number,
		darkestSecret;

	int	getInit( void ) const;

private:
	
	int _init;
};

#endif