/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:25:46 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:49:40 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	IMonitorDisplay
{
public:
	IMonitorDisplay();
	IMonitorDisplay(IMonitorDisplay const &);
	IMonitorDisplay(bool graphic_on);
	IMonitorDisplay& operator=(IMonitorDisplay const &);
	~IMonitorDisplay();
	void init();
	void destroy();

private:
	bool	_graphic_on;
};
