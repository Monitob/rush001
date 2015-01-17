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

#include <vector>
#include <iostream>

class Gkrellm {

public:
	Gkrellm();
	Gkrellm(Gkrellm const &  src);
	std::string getName() const;
	Gkrellm & operator=(Gkrellm const & f);
	void setName();
	virtual ~Gkrellm();

private:
	std::string _name;

};

#endif
