/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.interface.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:43:07 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 06:40:12 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_INTERFACE_HPP
#define IMONITORMODULE_INTERFACE_HPP

#include <ostream>
class	IMonitorModule
{
public:
	virtual std::string get_data() = 0;
	virtual std::string get_name() = 0;
	virtual void get_value() = 0;
	virtual void store_int(int i) = 0;
	virtual void store_string(std::string) = 0;
	virtual void set_L_value(std::string str) = 0;
	virtual void set_R_value(std::string str) = 0;
	virtual std::string get_L_value() = 0;
	virtual std::string get_R_value() = 0;
	virtual int is_LR_value() = 0;
	virtual int get_min() = 0;
	virtual int get_max() = 0;
	virtual bool is_slider() = 0;
};

#endif /* !IMONITORMODULE_INTERFACE_HPP */