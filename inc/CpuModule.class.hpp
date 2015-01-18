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

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
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

class CpuModule: public Module{

public:
  CpuModule();
  CpuModule(CpuModule const & src);
  CpuModule(std::string const & str);
  CpuModule & operator=(CpuModule const & src);
  virtual ~CpuModule();
  virtual void get_value();
  uint64_t getFrequency();


private:
  std::string _name;

};

#endif /* !CPUMODULE_CLASS_HPP */
