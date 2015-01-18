/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:12:20 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 13:20:28 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GRAPHICDISPLAY_INTERFACE_HPP
# define GRAPHICDISPLAY_INTERFACE_HPP

# include "IMonitorDisplay.interface.hpp"
# include <list>
# include <SDL2/SDL.h>

class	GraphicDisplay: public IMonitorDisplay
{
public:
	GraphicDisplay();
	GraphicDisplay(GraphicDisplay const &);
	GraphicDisplay& operator=(GraphicDisplay const &);
	~GraphicDisplay();
	virtual void	init();
	virtual void	destroy();
	virtual void	refresh_data();
	virtual void	refresh();
	virtual void	get_data(IMonitorModule *src);
	virtual void	print_data();
	virtual void	print_sliders();
	void			print_balls(int ball_nb);
	virtual bool	ubreak();


private:
	std::list<IMonitorModule *> modules;
	int				_y;
	std::string		_Sysname;
	std::string		_Nodename;
	std::string		_sys;
	int				_nb_core;
	IMonitorModule	*_clock;
	SDL_Window*		Window;
	bool			init_suc;
	SDL_Surface		*bar;
	SDL_Surface		*point;
	SDL_Surface		*back;
	SDL_Surface		*container;
	SDL_Surface		*ScreenSurface;
	int				y;
};

#endif /* !GRAPHICDISPLAY_INTERFACE_HPP */
