/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:43:07 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:17:50 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
#define IMONITORMODULE_CLASS_HPP

#include <ostream>
class	IMonitorModule
{
public:
	IMonitorModule();
	//IMonitorModule(IMonitorModule const & src);
	//IMonitorModule& operator=(IMonitorModule const &);
	virtual ~IMonitorModule();
	int get_data();
	std::string get_name();
	virtual void get_value() = 0;


protected:
	int			_data;
	std::string _name;
};

#endif /* !IMONITORMODULE_CLASS_HPP*/