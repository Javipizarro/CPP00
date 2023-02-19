/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:12:19 by jpizarro          #+#    #+#             */
/*   Updated: 2023/02/19 22:15:32 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <iostream>
# include "Contact.class.hpp"

# define MAX_CONTACTS 8

class	Phonebook {

public:

	Phonebook( void );
	~Phonebook( void );

	std::string	command( void ) const;
	void		add( void );
	int			requestIndex();
	void		search() const;
	void		wrongCommand(std::string command) const;


private:

	int _index;
	Contact _contacts[MAX_CONTACTS];
	std::string _column(int width, std::string str) const;
	
};

#endif