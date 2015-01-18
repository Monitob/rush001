/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramModule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:56 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 14:30:32 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_CLASS_HPP
# define RAMMODULE_CLASS_HPP

#include <stdexcept>
#include <iostream>
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
#include <ctime>
#include "Module.class.hpp"

class RamModule: public Module{

public:
	RamModule();
	RamModule(RamModule const & src);
	RamModule & operator=(RamModule const & src);
	virtual ~RamModule();
	virtual void get_value();
	int getRamCurrentlyUser();
	u_int getTotalRamAvailable();

};

#endif /* !RAMMODULE_CLASS_HPP */
