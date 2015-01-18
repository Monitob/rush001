/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:17:29 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 06:27:00 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Module.class.hpp"
#include <sstream>
#include <iostream>

/*
Module::Module(Module const &instance)
{

}

Module& Module::operator=(Module const &rhs)
{
	return *this;
}*/

Module::Module(): _data(""), _value_L(""), _value_R(""), _is_slider(false){
}

Module::Module(int min, int max, int value): _name("JAMES"), _is_slider(true), _min(min), _max(max){
	std::cout << "init slider class" << std::endl;
	this->store_int(value);
}

Module::~Module()
{

}

std::string Module::get_data(){
	return this->_data;
}

std::string Module::get_name(){
	return	this->_name;
}


void Module::get_value(){
}

void Module::store_int(int i){
	std::stringstream value_of_data;
	value_of_data << i;
	this->_data = value_of_data.str();
}

void Module::store_string(std::string str){
	this->_data = str;
}

void Module::set_L_value(std::string str){
	this->_value_L = str;
}
void Module::set_R_value(std::string str){
	this->_value_R = str;
}

std::string Module::get_R_value(){
	return this->_value_R;
}

std::string Module::get_L_value(){
	return this->_value_L;
}

int Module::is_LR_value()
{
	return _value_L.size() + _value_R.size();
}

int Module::get_min(){
	return this->_min;
}

int Module::get_max(){
	return this->_max;
}

bool Module::is_slider(){
	return this->_is_slider;
}
