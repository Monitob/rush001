/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:12:20 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 07:13:32 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GRAPHICDISPLAY_INTERFACE_HPP
# define GRAPHICDISPLAY_INTERFACE_HPP

# include "IMonitorDisplay.interface.hpp"
# include <list>

class	GraphicDisplay: public IMonitorDisplay
{
public:
	GraphicDisplay();
	/*GraphicDisplay(GraphicDisplay const &);
	GraphicDisplay& operator=(GraphicDisplay const &);*/
	~GraphicDisplay();
	virtual void	init();
	virtual void	destroy();
	virtual void	refresh_data();
	virtual void	refresh();
	virtual void	get_data(IMonitorModule *src);
	virtual void	print_data();
	virtual void	print_sliders();
private:
	std::list<IMonitorModule *> modules;
	int				_y;
	std::string		_Sysname;
	std::string		_Nodename;
	std::string		_sys;
	int				_nb_core;
	IMonitorModule	*_clock;
};

#endif /* !GRAPHICDISPLAY_INTERFACE_HPP */
