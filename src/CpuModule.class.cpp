
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
#include "../inc/CpuModule.class.hpp"

CpuModule::CpuModule(): Module("CPU module", 0, 0) {
  this->store_int(this->getFrequency());
}

CpuModule::CpuModule(std::string const & str): Module(str){
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
