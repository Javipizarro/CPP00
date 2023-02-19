/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:39:34 by jpizarro          #+#    #+#             */
/*   Updated: 2023/02/19 22:26:54 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(int init) : _init(init) {

	if (init == NO)
		return;
		
	std::cout << "--->| ADDING NEW CONTACT |<---" << std::endl;
	std::cout << "Please expecify the following:" << std::endl;

	std::cout << "First Name: ";
	std::cin >> this->firstName;
	std::cout << std::endl;

	std::cout << "Last Name: ";
	std::cin >> this->lastName;
	std::cout << std::endl;

	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << std::endl;

	std::cout << "Phone Number: ";
	std::cin >> this->number;
	std::cout << std::endl;

	std::cout << "Darkest Secret: ";
	std::cin >> this->darkestSecret;
	std::cout << std::endl;

	std::cout << "Contact for " << this->nickname << " created" << std::endl;
	return;
}

Contact::~Contact(void){
	return;
}

int	Contact::getInit( void ) const {
	return (this->_init);
}