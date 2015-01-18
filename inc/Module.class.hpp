/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:17:35 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 07:04:23 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_CLASS_HPP
# define MODULE_CLASS_HPP

#include "IMonitorModule.interface.hpp"

class	Module: public IMonitorModule
{
public:
	Module();
	Module(int min, int max, int value);
	virtual ~Module();
	virtual std::string get_data();
	virtual std::string get_name();
	virtual void get_value(); // USE THIS FONTION TO GET DATA !!!!!!
	virtual void store_int(int i);
	virtual void store_string(std::string str);
	virtual void set_L_value(std::string str);
	virtual void set_R_value(std::string str);
	virtual std::string get_L_value();
	virtual std::string get_R_value();
	virtual int is_LR_value();
	virtual int get_min();
	virtual int get_max();
	virtual bool is_slider();


protected:
	std::string			_data;
	std::string			_name;
	std::string			_value_L;
	std::string			_value_R;
	bool				_is_slider;
	int					_min;
	int					_max;
};

#endif
