/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:17:35 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 18:42:59 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_CLASS_HPP
# define MODULE_CLASS_HPP

#include "IMonitorModule.class.hpp"

class	Module: public IMonitorModule
{
public:
	Module();
	virtual ~Module();
	virtual int get_data();
	virtual std::string get_name();
	virtual void get_value();


protected:
	int			_data;
	std::string _name;
};

#endif