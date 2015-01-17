/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:42:04 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:18:32 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Interface.class.hpp"

Interface::Interface()
{

}

Interface::Interface(bool graphic_on):	_graphic_on(graphic_on)
{

}

Interface::Interface(Interface const &instance)
{

}

Interface& Interface::operator=(Interface const &rhs)
{
	return *this;
}

Interface::~Interface()
{

}


void Interface::init(){
	if (this->_graphic_on)
	{
		//init STDL 2
	}
	else
	{
		//init ncurses
	}
}


void Interface::destroy(){
	if (this->_graphic_on)
	{
		//destroy STDL 2
	}
	else
	{
		//destroy ncurses
	}
}


