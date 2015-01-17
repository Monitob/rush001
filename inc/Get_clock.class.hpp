/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_clock.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:50:25 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:21:51 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CLOCK_CLASS_HPP
#define GET_CLOCK_CLASS_HPP

#include "IMonitorModule.class.hpp"

class Get_clock: public IMonitorModule
{
public:
	Get_clock();
	virtual ~Get_clock();
	virtual void get_value() {
		//recurere l'heure
		this->_data = 42;
	};
};

#endif /* !GET_CLOCK_CLASS_HPP*/

