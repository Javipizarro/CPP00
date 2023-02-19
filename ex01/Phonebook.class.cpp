/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:10:11 by jpizarro          #+#    #+#             */
/*   Updated: 2023/02/19 22:26:25 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook(void){

	this->_index = 0;

	std::cout
		<< "Welcome to:" << std::endl
		<< "        --------------------------" << std::endl
		<< "           MY AWESOME PHONEBOOK   " << std::endl
		<< "        -------------------------- v2.0" << std::endl
		<< std::endl;

	return;
}

Phonebook::~Phonebook(void){
	std::cout
		<< "Thanks for using!" << std::endl
		<< "My Awesome Phonebook 1984 by PHONEBOOK Corp" << std::endl
		<< std::endl;
	return;
}

std::string	Phonebook::command(void) const{
	
	std::string command;

	std::cout
		<< "Please write one of the following:" << std::endl
		<< "\"ADD\"  - - > Add new contact!" <<std::endl
		<< "\"SEARCH\" - > Search one contact" <<std::endl
		<< "\"EXIT\" - - > If you don't need MY AWESOME PHONEBOOK anymore" <<std::endl
		<< std::endl
		<< "Your choice: ";
	std::cin >> command;
	std::cout << std::endl;
	
	for (int i = 0; command[i]; i++)
		command[i] = toupper(command[i]);

	return command;
}

int		Phonebook::requestIndex(void) {
	return ((this->_index++) % MAX_CONTACTS);
}

void	Phonebook::add(void){
	int index = this->requestIndex();
	std::cout
		<< "Adding new contact to index " << index << std::endl;
	Contact newContact(YES);
	this->_contacts[index] = newContact;
	std::cout
		<< "Contact " << newContact.nickname << " added." << std::endl
		<< std::endl;
	return;
}

void	Phonebook::search(void) const{

	int index;

	if (!this->_contacts[0].getInit()) {
		std::cout
			<< "NO CONTACTS ON THE AWESOME PHONEBOOK YET." << std::endl
			<< "Please add any with the ADD command." << std::endl
			<< std::endl;
		return;
	}

	for (int i = 0; this->_contacts[i].getInit() && i < MAX_CONTACTS; i++) {
		std::cout << this->_column(10, std::to_string(i + 1)) << '|'
			<< this->_column(10, this->_contacts[i].firstName) << '|'
			<< this->_column(10, this->_contacts[i].lastName) << '|'
			<< this->_column(10, this->_contacts[i].nickname) << std::endl;
	}
	std::cout
		<< std::endl
		<< "Please, enter the index of the contact to display:" << std::endl
		<< "--> ";
	std::cin >> index;
 	if (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please, introduce a valid index." << std::endl
		<< std::endl;
		return;
	 } else
	 	index--;

	if (index >= 0 && index < MAX_CONTACTS && this->_contacts[index].getInit()) {
		std::cout
			<< "First Name:     " << this->_contacts[index].firstName << std::endl
			<< "Last Name:      " << this->_contacts[index].lastName << std::endl
			<< "Nickname:       " << this->_contacts[index].nickname << std::endl
			<< "Phone Number:   " << this->_contacts[index].number << std::endl
			<< "Darkest Secret: " << this->_contacts[index].darkestSecret << std::endl
			<< std::endl;
	} else {
		std::cout
			<< "The contact " << index << " is not available." << std::endl
			<< std::endl;
	}
	return;
}

void	Phonebook::wrongCommand(std::string command)  const{
	std::cout << command << " --> IS NOT A CORRECT COMMAND!!" << std::endl;
	return;
}

std::string	Phonebook::_column(int width, std::string str) const {

	std::string ret(width, ' ');
	int len = str.length();

	for (int i = 0; i < len && i < width; i++)
		ret[i] = str[i];
	if (len > width)
		ret[width - 1] = '.';
	return (ret);
}