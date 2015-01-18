
#ifndef CPUMODULEINDICATOR_CLASS_HPP
# define CPUMODULEINDICATOR_CLASS_HPP

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

class CpuModuleIndicator: public Module{

public:
  CpuModuleIndicator();
  CpuModuleIndicator(CpuModuleIndicator const & src);
  CpuModuleIndicator(std::string const & str);
  CpuModuleIndicator & operator=(CpuModuleIndicator const & src);
  virtual ~CpuModuleIndicator();
  virtual void get_value();
  float	calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
  float getCpuLoadAvareage();

private:
  std::string _name;
  float last;

};

#endif /* !CPUMODULEINDICATOR_CLASS_HPP */
