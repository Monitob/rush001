/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:42:10 by sbres             #+#    #+#             */
/*   Updated: 2015/01/17 17:21:50 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class	Interface
{
public:
	Interface();
	Interface(Interface const &);
	Interface(bool graphic_on);
	Interface& operator=(Interface const &);
	~Interface();
	void init();
	void destroy();

private:
	bool	_graphic_on;
};
