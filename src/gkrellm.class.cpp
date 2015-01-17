/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:25 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 12:37:30 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/gkrellm.class.hpp"


  GKrellm::Gkrellm(){

  }

  GKrellm::Gkrellm(std::string name){
    setName(name);
  }

  GKrellm::Gkrellm(GKrellm & const src){
    *this = src;
  }

  GKrellm::~Gkrellm(){
    
  }

  Gkrellm & GKrellm::operator=(Gkrellm & f){

    this->_name = f.getName();
    return (*this;)
  }

  std::string GKrellm::getName(){
    return _name;
  }

  void GKrellm::setName(std::string name){
    _name = name
  }
