
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/times.h"
#include <sstream>
#include "../inc/CpuModule.class.hpp"


CpuModule::CpuModule(): Module("CPU module", 0, 0) {
  this->store_int(this->getFrequency());
}

CpuModule::CpuModule(std::string const & str): Module(str){
  //this->_name = str;
  this->set_R_value("Hz");
}

CpuModule::CpuModule(CpuModule const & src): Module(src){
  *this = src;
}

CpuModule & CpuModule::operator=(CpuModule const & src){
  (void)src;
  return *this;
}

void CpuModule::get_value(){
  std::stringstream value_of_data;
  value_of_data << this->getFrequency();
  store_string(value_of_data.str());
}

CpuModule::~CpuModule(){}


uint64_t CpuModule::getFrequency(){

  uint64_t freq = 0;
  size_t size = sizeof(freq);

  if (sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0){
  }
  return freq;
}
//
// float	CpuModule::calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
// {
//   unsigned long long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
//   unsigned long long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;
//
//   float ret = 1.0f - ((totalTicksSinceLastTime > 0) ?
//   static_cast<float>(idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);
//
//   m_previousTotalTicks = totalTicks;
//   m_previousIdleTicks  = idleTicks;
//   return ret;
// }
//
//
//
// float CpuModule::getCpuLoadAvareage(){
//   host_cpu_load_info_data_t cpuinfo;
//   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
//
//   if (host_statistics(
//         mach_host_self(),
//         HOST_CPU_LOAD_INFO,
//         (host_info_t)&cpuinfo, &count) == KERN_SUCCESS) {
//
//         unsigned long long totalTicks = 0;
//
//         for(int i = 0 ; i < CPU_STATE_MAX ; i++) {
//           totalTicks += cpuinfo.cpu_ticks[i];
//         }
//     return (calculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks));
//   }
//   return -1.0f;
// }
