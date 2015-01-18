/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:17:47 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/18 13:36:24 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/gkrellm.class.hpp"
#include "../inc/Get_clock.class.hpp"
#include "../inc/TerminalDisplay.class.hpp"
#include "../inc/GraphicDisplay.class.hpp"
#include "../inc/IMonitorModule.interface.hpp"
#include <list>
#include <unistd.h>

void interface(IMonitorModule *toto)
{
	std::cout << toto->get_data() << std::endl;
}

int main(){
	/*std::cout << "coucouc" << std::endl;*/
	Get_clock *tata = new Get_clock();
	Gkrellm *gk = new Gkrellm();
	bool		runnig = true;
	IMonitorDisplay *inter = new TerminalDisplay(gk->getName(), gk->getNodeName(), gk->getSysName(), gk->getNbCore());
	//std::string Sysname, std::string Nodename, std::string sys, int core
	//IMonitorDisplay *inter = new GraphicDisplay();

	inter->init();
	inter->get_data(tata);
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
