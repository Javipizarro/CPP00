/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:31:16 by jpizarro          #+#    #+#             */
/*   Updated: 2023/02/19 21:43:39 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		main(void){
	
	Phonebook	phonebook;
	std::string	command;

	while ((command = phonebook.command()) != "EXIT") {
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			phonebook.wrongCommand(command);
	}
return (0);
}