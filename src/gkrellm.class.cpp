/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:25 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 14:30:33 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include "gkrellm.class.hpp"

struct utsname unameData;


Gkrellm::Gkrellm(){
  uname(&unameData);
  this->setName();

  std::cout << GREEN << "Welcome to the Gkrellm. Best version 2.0.0.3000!" << RESET << std::endl;
  std::cout << "system name:" << unameData.sysname << std::endl;
  std::cout << "node name   :"<< unameData.nodename << std::endl;
  std::cout << "release    :" << unameData.release << std::endl;
  std::cout << "version    :" << unameData.version << std::endl;
  std::cout << "machine    :" << unameData.machine << std::endl;
  getTotalRamAvailable();
  getRamCurrentlyUser();
  getAvailableCore();
  std::cout <<  "return of dateData()  " << dateData() << std::endl;
}

Gkrellm::Gkrellm(Gkrellm const & src){
    *this = src;
}

Gkrellm::~Gkrellm(){
}

Gkrellm & Gkrellm::operator=(Gkrellm const& f){

  this->_name = f.getName();
  return (*this);
}

std::string Gkrellm::getName() const{
  return this->_name;
}



void Gkrellm::getRamCurrentlyUser(){
  /*
  * this function has to return a pair vector to get free_memory and used_memory
  * or only return free memory
  */
  vm_size_t page_size;
  mach_port_t mach_port;
  mach_msg_type_number_t count;
  vm_statistics64_data_t vm_stats;

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
        std::cout << RED <<  "free memory RAM: " << RESET << free_memory <<  BOLDYELLOW << "  unused RAM memory: "<<  RESET << used_memory << std::endl;
      }
}

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

u_int Gkrellm::getAvailableCore(){

  uint32_t numCPU = sysconf( _SC_NPROCESSORS_ONLN );
  int mib[4];
  size_t len = sizeof(numCPU);

  /* set the mib for hw.ncpu */
  mib[0] = CTL_HW;
  mib[1] = HW_AVAILCPU;  // alternatively, we can try HW_NCPU;

  /* get the number of CPUs from the system */
  sysctl(mib, 2, &numCPU, &len, NULL, 0);

  if( numCPU < 1 )
  {
    mib[1] = HW_NCPU;
    sysctl( mib, 2, &numCPU, &len, NULL, 0 );

    if( numCPU < 1 )
    {
      numCPU = 1;
    }
  }
  std::cout << BOLDCYAN << "my cores: " << RESET << numCPU << RESET << std::endl;
  return numCPU;
}
/*
*links
http://stackoverflow.com/questions/150355/programmatically-find-the-number-of-cores-on-a-machine
http://mogproject.blogspot.fr/2014/09/c-how-to-get-per-core-cpu-usage-in-mac.html
http://stackoverflow.com/questions/8782228/retrieve-ram-info-on-a-mac
https://developer.apple.com/library/ios/documentation/System/Conceptual/ManPages_iPhoneOS/man3/sysctl.3.html
http://nadeausoftware.com/articles/2012/09/c_c_tip_how_get_physical_memory_size_system
http://man7.org/linux/man-pages/man2/uname.2.html
https://developer.apple.com/library/mac/documentation/Darwin/Reference/ManPages/man3/sysctlbyname.3.html
http://www.opensource.apple.com/source/xnu/xnu-1456.1.26/libkern/libkern/sysctl.h
https://cdn.intrav2.42.fr/pdf/pdf/78/6e6d36b67d95fbca71ab0a85e4e77d2c-rush01.en.pdf
*
*/


void Gkrellm::setName(){
  #ifdef _WIN32
  _name = "Windows 32-bit";
  #elif _WIN64
  _name = "Windows 64-bit";
  #elif __unix || __unix__
  _name = "Unix";
  #elif __APPLE__ || __MACH__
  _name = "Mac OSX";
  #elif __linux__
  reutnr "Linux";
  #elif __FreeBSD__
  _name = "FreeBSD";
  #else
  _name = "Other";
  #endif
}
