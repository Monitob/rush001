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

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

class Gkrellm{

public:
	Gkrellm();
	Gkrellm(Gkrellm const &  src);
	std::string getName() const;
	Gkrellm & operator=(Gkrellm const & f);
	void setName();
	virtual ~Gkrellm();

private:
	std::string _name;
	u_int getTotalRamAvailable();
	void getRamCurrentlyUser();
	u_int getAvailableCore();
	std::string dateData();


};

#endif
