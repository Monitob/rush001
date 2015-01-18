/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_clock.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:50:25 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 05:57:46 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CLOCK_CLASS_HPP
#define GET_CLOCK_CLASS_HPP

#include "Module.class.hpp"

class Get_clock: public Module
{
public:
	Get_clock();
	Get_clock(int min, int max, int value);
	virtual ~Get_clock();
	virtual void get_value() {
		this->store_int(2500);
		this->_name = "clock";
		this->set_R_value("M");
		this->set_L_value("toto");
	};
};

#endif /* !GET_CLOCK_CLASS_HPP*/

