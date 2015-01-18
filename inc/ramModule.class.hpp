/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:56 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 14:30:32 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_CLASS_HPP
#define GKRELLM_CLASS_HPP

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


class RamModule{

public:
  RamModule();
  RamModule(RamModule const &  src);
  RamModule & operator=(RamModule const & src);
  virtual ~RamModule();

  int getRamCurrentlyUser();

};

#endif
