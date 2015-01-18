/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:05:08 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 13:18:07 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALDISPLAY_INTERFACE_HPP
# define TERMINALDISPLAY_INTERFACE_HPP

# include "IMonitorDisplay.interface.hpp"
# include "IMonitorModule.interface.hpp"
# include <ncurses.h>
# include <curses.h>
# include <list>

class	TerminalDisplay: public IMonitorDisplay
{
public:
	TerminalDisplay();
	/*TerminalDisplay(TerminalDisplay const &);
	TerminalDisplay& operator=(TerminalDisplay const &);*/
	~TerminalDisplay();
	virtual void	init();
	virtual void	destroy();
	virtual void	refresh_data();
	virtual void	refresh();
	virtual void	get_data(IMonitorModule *src);
	virtual void	print_data();
	virtual void	print_sliders();
	void			draw_line(int y);
	void			fill(int y, int size, int amount);
	virtual bool	ubreak();

private:
	bool is_init;
	WINDOW *win;
	std::list<IMonitorModule *> modules;
	int				_y;
	std::string		_Sysname;
	std::string		_Nodename;
	std::string		_sys;
	int				_nb_core;
	IMonitorModule	*_clock;
};

#endif /* !TERMINALDISPLAY_INTERFACE_HPP */
