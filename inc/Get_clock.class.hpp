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

#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <ctime>
#include <stdexcept>
#include <fstream>
#include <string>
#include <stdint.h>
#include <unistd.h>
#include <mach/mach.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include "Module.class.hpp"

class Get_clock: public Module
{
public:
	Get_clock();
	virtual ~Get_clock();
	Get_clock(std::string str);
	virtual void get_value();
	Get_clock & operator=(Get_clock & src);

};

#endif /* !GET_CLOCK_CLASS_HPP*/
