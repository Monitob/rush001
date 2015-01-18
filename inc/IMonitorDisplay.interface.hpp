/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.interface.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:25:46 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 13:16:47 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_INTERFACE_HPP
# define IMONITORDISPLAY_INTERFACE_HPP

# include "IMonitorModule.interface.hpp"

class	IMonitorDisplay
{
public:/*
	IMonitorDisplay();
	IMonitorDisplay(IMonitorDisplay const &);
	IMonitorDisplay(bool graphic_on);
	IMonitorDisplay& operator=(IMonitorDisplay const &);
	~IMonitorDisplay();*/
	virtual void	init() = 0;
	virtual void	destroy() = 0;
	virtual void	refresh_data() = 0;
	virtual void	refresh() = 0;
	virtual void	get_data(IMonitorModule *src) = 0;
	virtual void	print_data() = 0;
	virtual void	print_sliders() = 0;
	virtual bool	ubreak() = 0;
/*
private:
	bool	_graphic_on;*/
};

#endif /* !IMONITORDISPLAY_INTERFACE_HPP */
