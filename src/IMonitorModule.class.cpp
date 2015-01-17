/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:42:57 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:13:00 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMonitorModule.class.hpp"

IMonitorModule::IMonitorModule()
{

}
/*
IMonitorModule::IMonitorModule(IMonitorModule const &instance)
{

}

IMonitorModule& IMonitorModule::operator=(IMonitorModule const &rhs)
{
	return *this;
}*/

IMonitorModule::~IMonitorModule()
{

}

int IMonitorModule::get_data(){
	return this->_data;
}

std::string IMonitorModule::get_name(){
	return	this->_name;
}
