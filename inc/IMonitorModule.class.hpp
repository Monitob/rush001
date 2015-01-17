/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:43:07 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 18:44:12 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
#define IMONITORMODULE_CLASS_HPP

#include <ostream>
class	IMonitorModule
{
public:
	virtual int get_data() = 0;
	virtual std::string get_name() = 0;
	virtual void get_value() = 0;
};

#endif /* !IMONITORMODULE_CLASS_HPP*/