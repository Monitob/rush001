/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:17:29 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 18:40:52 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Module.class.hpp"


/*
Module::Module(Module const &instance)
{

}

Module& Module::operator=(Module const &rhs)
{
	return *this;
}*/

Module::Module(): _data(0){
}

Module::~Module()
{

}

int Module::get_data(){
	return this->_data;
}

std::string Module::get_name(){
	return	this->_name;
}


void Module::get_value(){
}
