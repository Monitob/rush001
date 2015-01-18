/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:17:47 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/18 17:36:21 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/gkrellm.class.hpp"
#include "../inc/Get_clock.class.hpp"
#include "../inc/TerminalDisplay.class.hpp"
#include "../inc/GraphicDisplay.class.hpp"
#include "../inc/IMonitorModule.interface.hpp"
#include "../inc/IMonitorDisplay.interface.hpp"
#include "../inc/ramModule.class.hpp"
#include "../inc/CpuModule.class.hpp"
#include "../inc/CpuModuleIndicator.hpp"
#include <list>
#include <unistd.h>

void interface(IMonitorModule *toto)
{
	std::cout << toto->get_data() << std::endl;
}

int main(){
	/*std::cout << "coucouc" << std::endl;*/
	//Get_clock *tata = new Get_clock();

	Gkrellm *gk = new		Gkrellm();
	bool		runnig =	true;
	std::string				input;
	IMonitorDisplay *inter;

	std::cout << "Tapez G pour mode graphique et T pour mode terminal." << std::endl;
	std::cin >> input;
	if (input.compare("G") == 0)
	{
		std::cout << "Mode Graphique !" << std::endl;
		inter = new GraphicDisplay();
	}
	else if(input.compare("T") == 0)
	{
		std::cout << "Mode Terminal !" << std::endl;
		inter = new TerminalDisplay(gk->getName(), gk->getNodeName(), gk->getSysName(), gk->getNbCore());
	}
	else
	{
		std::cout << "Pas de mode choisi !" << std::endl;
		return 1;
	}

	IMonitorModule *ram = new RamModule();
	IMonitorModule *ramu = new RamModule("RAM Used");

	inter->init();
	inter->get_data(ram);

	inter->get_data(ramu);

	CpuModule *cpu_m = new CpuModule("CPU Frequency");
	CpuModuleIndicator *cpu_i = new CpuModuleIndicator("CPU Indicator");
	std::cout << cpu_i->getCpuLoadAvareage() << std::endl;
	inter->get_data(cpu_m);
	inter->get_data(cpu_i);
	while (runnig)
	{
		inter->refresh_data();
		inter->refresh();
		inter->print_data();
		runnig = inter->ubreak();
	}
	inter->destroy();
	return (0);
}
