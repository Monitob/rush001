/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:05:19 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 16:41:06 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/TerminalDisplay.class.hpp"
#include "../inc/IMonitorModule.interface.hpp"
#include "../inc/Module.class.hpp"
#include "../inc/Get_clock.class.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

TerminalDisplay::TerminalDisplay(): is_init(false), _y(5),
									_Sysname("Darwin"), _Nodename("e3r10p21.42.fr"), _sys("MAC OSX")
									, _nb_core(4), _clock(new Get_clock())
{
}

TerminalDisplay::TerminalDisplay(std::string Sysname, std::string Nodename, std::string sys, int core): is_init(false), _y(5),
									_Sysname(Sysname), _Nodename(Nodename), _sys(sys)
									, _nb_core(core), _clock(new Get_clock())
{
}

TerminalDisplay::TerminalDisplay(TerminalDisplay const &instance)
{
	*this = instance;
}

TerminalDisplay& TerminalDisplay::operator=(TerminalDisplay const &rhs)
{
	(void)rhs;
	return *this;
}

TerminalDisplay::~TerminalDisplay()
{
	if (is_init)
	{
		this->destroy();
	}
}


void TerminalDisplay::init(){
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	is_init = true;
	this->win = newwin(50, 100, 0, 0);
	this->refresh();
	nodelay(stdscr, TRUE);
	curs_set(0);
}

bool TerminalDisplay::ubreak(){
	return getch() != 'q';
}

void TerminalDisplay::refresh(){
	wborder(this->win, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwaddstr(this->win, 1, 40, "ft_gkrellm");
	mvwaddstr(this->win, 1, 2, "Sysname : ");
	mvwaddstr(this->win, 1, 12, + this->_Sysname.c_str());
	mvwaddstr(this->win, 2, 2, "Nodename : ");
	mvwaddstr(this->win, 2, 13, + this->_Nodename.c_str());
	mvwaddstr(this->win, 3, 2, "Systeme : ");
	mvwaddstr(this->win, 3, 12, this->_sys.c_str());
	mvwaddstr(this->win, 3, 40, "Time : ");
	mvwaddstr(this->win, 3, 48, this->_clock->get_data().c_str());
	this->draw_line(4);
	wrefresh(this->win);
	this->_y = 5;
}

void TerminalDisplay::destroy(){
	delwin(this->win);
	endwin();
	is_init = false;
}

void TerminalDisplay::get_data(IMonitorModule *src){
	modules.push_back(src);
}

void TerminalDisplay::refresh_data(){
	IMonitorModule *current;
	std::list<IMonitorModule *>::iterator start = this->modules.begin();
	std::list<IMonitorModule *>::iterator end = this->modules.end();
	while (start != end)
	{
		current = *start;
		current->get_value();
		++start;
	}
	this->_clock->get_value();
}

void TerminalDisplay::print_data(){
	if (modules.size() == 0)
		return;
	this->print_sliders();
	int x = 2;
	int xy = x;
	unsigned int data_size = 0;
	std::stringstream value_to_print;
	IMonitorModule *toto;
	std::list<IMonitorModule *>::iterator start = this->modules.begin();
	std::list<IMonitorModule *>::iterator end = this->modules.end();
	while (start != end)
	{
		toto = *start;
		if (!toto->is_slider())
		{
			value_to_print.str("");
			value_to_print << toto->get_data();
			data_size = value_to_print.str().size() + toto->is_LR_value() + 2;
			if (toto->get_name().size() + x > 95 || data_size + x > 95)
			{
				this->draw_line(this->_y + 3);
				this->_y += 4;
				x = 2;
			}
			//std::cout << toto->get_name() << std::endl;
			xy = x;
			if (toto->is_LR_value())
			{
				if (toto->get_L_value().size() != 0)
				{
					mvwaddstr(this->win, this->_y + 1, xy, toto->get_L_value().c_str());
					xy += toto->get_L_value().size() + 1;
				}
			}
			mvwaddstr(this->win, this->_y, x, toto->get_name().c_str());
			mvwaddstr(this->win, this->_y + 1, xy, value_to_print.str().c_str());
			if (toto->is_LR_value())
			{
				if (toto->get_R_value().size() != 0)
				{
					xy += value_to_print.str().size() + 1;
					mvwaddstr(this->win, this->_y + 1, xy, toto->get_R_value().c_str());
				}
			}

			if (data_size > toto->get_name().size()){
				x += data_size + 1;
			}
			else{
				x += toto->get_name().size() + 1;
			}
			mvwaddch(this->win, this->_y , x, '|');
			mvwaddch(this->win, this->_y + 1, x, '|');
			mvwaddch(this->win, this->_y , x + 1, ' ');
			x += 2;
		}
		++start;
	}
	wrefresh(this->win);
}

void TerminalDisplay::print_sliders(){
	if (modules.size() == 0)
		return;
	int size = 0;
	float tmp = 2;
	IMonitorModule *current;
	std::list<IMonitorModule *>::iterator start = this->modules.begin();
	std::list<IMonitorModule *>::iterator end = this->modules.end();
	while (start != end)
	{
		current = *start;
		if (current->is_slider())
		{
			mvwaddstr(this->win, this->_y, 2, current->get_name().c_str());
			size = 94 - current->get_name().size();
			tmp = (current->get_max() - current->get_min()) / size;
			this->fill(this->_y, size, std::atoi(current->get_data().c_str()) / tmp);
			mvwaddch(this->win, this->_y, 3 + current->get_name().size() , '[');
			mvwaddch(this->win, this->_y, 97 , ']');
			this->_y++;
		}
		++start;
	}
	this->_y++;
	this->draw_line(this->_y);
	this->_y++;
}

void TerminalDisplay::fill(int y, int size, int amount)
{
	int x = 97 - size;
	for (int i = 1; i < size; ++i)
	{
		if (i < amount)
			mvwaddch(this->win, y , i + x, '#');
		else
			mvwaddch(this->win, y , i + x, ' ');
	}
}

void TerminalDisplay::draw_line(int y){
	for (int i = 1; i < 99; ++i)
	{
		mvwaddch(this->win, y , i, '-');
	}
}
