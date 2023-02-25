/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:02:41 by jpizarro          #+#    #+#             */
/*   Updated: 2023/02/05 21:30:08 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using namespace std;

int		main(int argc, char *argv[])
{
	if (argc > 1)
		for (int i = 1; argv[i]; i++)
			for (int j = 0; argv[i][j]; j++)
				cout << (char) toupper(argv[i][j]);
	else
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	cout << endl;
	return (0);
}
