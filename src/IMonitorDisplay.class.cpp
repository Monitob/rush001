/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:25:38 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:49:40 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMonitorDisplay.class.hpp"

IMonitorDisplay::IMonitorDisplay()
{

}

IMonitorDisplay::IMonitorDisplay(bool graphic_on):	_graphic_on(graphic_on)
{

}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const &instance)
{

}

IMonitorDisplay& IMonitorDisplay::operator=(IMonitorDisplay const &rhs)
{
	return *this;
}

IMonitorDisplay::~IMonitorDisplay()
{

}


void IMonitorDisplay::init(){
	if (this->_graphic_on)
	{
		//init STDL 2
	}
	else
	{
		//init ncurses
	}
}


void IMonitorDisplay::destroy(){
	if (this->_graphic_on)
	{
		//destroy STDL 2
	}
	else
	{
		//destroy ncurses
	}
}


