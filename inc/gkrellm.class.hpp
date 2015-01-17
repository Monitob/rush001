/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:56 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 14:30:32 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_CLASS_HPP
#define GKRELLM_CLASS_HPP

#include <iostream>

class Gkrellm {

public:
	Gkrellm(std::string name);
	std::string getName() const;
	void setName(std::string name);


private:
	std::string _name;

	Gkrellm();
	Gkrellm(Gkrellm const &  src);
	~Gkrellm();
	Gkrellm & operator=(Gkrellm const & f);

};

#endif