
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/times.h"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <sstream>
#include "../inc/CpuModuleIndicator.hpp"

static unsigned long long m_previousTotalTicks = 0;
static unsigned long long m_previousIdleTicks = 0;

CpuModuleIndicator::CpuModuleIndicator(): Module("CPU module", 0, 0) {
}

CpuModuleIndicator::CpuModuleIndicator(std::string const & str): Module(str), last(0){
    this->set_R_value("%");
}

CpuModuleIndicator::CpuModuleIndicator(CpuModuleIndicator const & src): Module(src){
  *this = src;
}

CpuModuleIndicator & CpuModuleIndicator::operator=(CpuModuleIndicator const & src){
  (void)src;
  return *this;
}

void CpuModuleIndicator::get_value(){

    float tmp = this->getCpuLoadAvareage();
    tmp = tmp;
    tmp = (last + tmp) / 2;
    last = tmp;
    //std::cout << tmp << " indicator " << std::endl;
    std::stringstream value_of_data;
    value_of_data << tmp;
    store_string(value_of_data.str());
}

CpuModuleIndicator::~CpuModuleIndicator(){}


float	CpuModuleIndicator::calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;

  float ret = 1.0f - ((totalTicksSinceLastTime > 0) ?
  static_cast<float>(idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

  m_previousTotalTicks = totalTicks;
  m_previousIdleTicks  = idleTicks;
  return ret;
}

float CpuModuleIndicator::getCpuLoadAvareage(){
  host_cpu_load_info_data_t cpuinfo;
  mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;

  if (host_statistics(
        mach_host_self(),
        HOST_CPU_LOAD_INFO,
        (host_info_t)&cpuinfo, &count) == KERN_SUCCESS) {

        unsigned long long totalTicks = 0;

        for(int i = 0 ; i < CPU_STATE_MAX ; i++) {
          totalTicks += cpuinfo.cpu_ticks[i];
        }
    return (calculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks));
  }
  return -1.0f;
}
