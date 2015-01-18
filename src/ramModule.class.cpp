/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ramModule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:50:20 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 06:26:05 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ramModule.class.hpp"
#include <iostream>
RamModule::RamModule(): Module("RAM used", 0, 100) {

this->store_int(this->getRamCurrentlyUser());

}

RamModule::RamModule(RamModule const & src): Module(src){
	*this = src;
}

RamModule & RamModule::operator=(RamModule const & src){
	(void)src;
	return *this;
}

void RamModule::get_value(){
	store_int(this->getRamCurrentlyUser());
}

template <class T>
std::string numTostr(const T& num, unsigned int prec = 12) {
  std::string ret;
  std::stringstream ss;
  std::ios_base::fmtflags ff = ss.flags();
  ff |= std::ios_base::floatfield;
  ff |= std::ios_base::fixed;
  ss.flags(ff);
  ss.precision(prec);
  ss << num;
  ret = ss.str();
  return ret;
};

int RamModule::getRamCurrentlyUser(){
  /*
  * this function has to return a pair vector to get free_memory and used_memory
  * or only return free memory
  */
  vm_size_t page_size;
  mach_port_t mach_port;
  mach_msg_type_number_t count;
  vm_statistics64_data_t vm_stats;
  int percentageUsed;

  mach_port = mach_host_self();
  count = sizeof(vm_stats) / sizeof(natural_t);
  int mib[2] = { CTL_HW, HW_MEMSIZE };
  u_int namelen = sizeof(mib) / sizeof(mib[0]);
  uint64_t size;
  size_t len = sizeof(size);

  if (sysctl(mib, namelen, &size, &len, NULL, 0) < 0)
  {
    throw std::exception();
  }
  else
  {
    if (
      KERN_SUCCESS == host_page_size(mach_port, &page_size)
      && KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO, (host_info64_t)&vm_stats, &count)
      )
    {
    long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
    //  long long used_memory = ((int64_t)vm_stats.active_count + (int64_t)vm_stats.inactive_count + (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
      //std::cout << RED <<  "free memory RAM: " << RESET << free_memory <<  BOLDYELLOW << "  unused RAM memory: "<<  RESET << used_memory << std::endl;
       percentageUsed = (static_cast<float>(free_memory) * 100.00)/ size;
    }
  }
  return percentageUsed;
}
//
// int Gkrellm::getRamFreeUser(){
//   /*
//   * this function has to return a pair vector to get free_memory and used_memory
//   * or only return free memory
//   */
//   vm_size_t page_size;
//   mach_port_t mach_port;
//   mach_msg_type_number_t count;
//   vm_statistics64_data_t vm_stats;
//   int percentageUsed;
//
//   mach_port = mach_host_self();
//   count = sizeof(vm_stats) / sizeof(natural_t);
//   /*
//   * Warning!: Nasty code.
//   */
//   if (
//     KERN_SUCCESS == host_page_size(mach_port, &page_size)
//     && KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO, (host_info64_t)&vm_stats, &count)
//     )
//   {
//     long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
//     long long used_memory = ((int64_t)vm_stats.active_count + (int64_t)vm_stats.inactive_count + (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
//     //std::cout << RED <<  "free memory RAM: " << RESET << free_memory <<  BOLDYELLOW << "  unused RAM memory: "<<  RESET << used_memory << std::endl;
//     percentageUsed = (free_memory * 100.00) / static_cast<long long>getTotalRAmAvailable;
//   }
//   return percentageUsed;
// }

u_int RamModule::getTotalRamAvailable(){

  int mib[2] = { CTL_HW, HW_MEMSIZE };
  u_int namelen = sizeof(mib) / sizeof(mib[0]);
  uint64_t size;
  size_t len = sizeof(size);

  if (sysctl(mib, namelen, &size, &len, NULL, 0) < 0)
  {
    throw std::exception();
  }
  else
  {
    //std::cout << "Total ram:   " << size << " bytes"<< std::endl;
    return size;
  }
}


RamModule::~RamModule()
{

}
