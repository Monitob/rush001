/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:25 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 14:30:33 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "gkrellm.class.hpp"

Gkrellm::Gkrellm(){
  this->setName();
}

Gkrellm::Gkrellm(Gkrellm const & src){
    *this = src;
}

Gkrellm::~Gkrellm(){
}

Gkrellm & Gkrellm::operator=(Gkrellm const& f){

  this->_name = f.getName();
  return (*this);
}

std::string Gkrellm::getName() const{
  return this->_name;
}

void Gkrellm::setName(){
  #ifdef _WIN32
  _name = "Windows 32-bit";
  #elif _WIN64
  _name = "Windows 64-bit";
  #elif __unix || __unix__
  _name = "Unix";
  #elif __APPLE__ || __MACH__
  _name = "Mac OSX";
  #elif __linux__
  reutnr "Linux";
  #elif __FreeBSD__
  _name = "FreeBSD";
  #else
  _name = "Other";
  #endif
}
