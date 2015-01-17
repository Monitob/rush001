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


#include "../inc/gkrellm.class.hpp"

Gkrellm::Gkrellm(){

}

  Gkrellm::Gkrellm(std::string name){
    setName(name);
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
  return _name;
}

void Gkrellm::setName(std::string name){
  this->_name = name;
}
