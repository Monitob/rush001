/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:50:20 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 06:26:05 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ramModule.class.hpp"


RamModule::RamModule(): _is_slider(true), _name("RAM used"), _min(0), _max(100){
//max ram available
//ram user in store_int()
store_int(getRamCurrentLyUser());

}

RamModule::RamModule(std::string str)
{
  this->store_string(str);
}


void RamModule::get_value(){
  store_int(getRamCurrentLyUser());
  
}

int Gkrellm::getRamCurrentlyUser(){
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
  /*
  * Warning!: Nasty code.
  */
  if (
    KERN_SUCCESS == host_page_size(mach_port, &page_size)
    && KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO, (host_info64_t)&vm_stats, &count)
    )
  {
    long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
    long long used_memory = ((int64_t)vm_stats.active_count + (int64_t)vm_stats.inactive_count + (int64_t)vm_stats.wire_count) *  (int64_t)page_size;
    //std::cout << RED <<  "free memory RAM: " << RESET << free_memory <<  BOLDYELLOW << "  unused RAM memory: "<<  RESET << used_memory << std::endl;
    percentageUsed = (used_memory * 100.00) / static_cast<long long>getTotalRAmAvailable;
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

u_int Gkrellm::getTotalRamAvailable(){

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
    std::cout << "Total ram:   " << size << " bytes"<< std::endl;
    return size;
  }
}

RamModule & RamModule::operator=(RamModule & src){
  (void)src;
  return *this;
}

RamModule::~RamModule()
{

}
