/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:12:27 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 12:14:02 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GraphicDisplay.class.hpp"
#include "../inc/IMonitorModule.interface.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>


GraphicDisplay::GraphicDisplay(): init_suc(true), y(100)
{

}
/*
GraphicDisplay::GraphicDisplay(GraphicDisplay const &instance)
{

}

GraphicDisplay& GraphicDisplay::operator=(GraphicDisplay const &rhs)
{
	return *this;
}*/

GraphicDisplay::~GraphicDisplay()
{

}


void GraphicDisplay::init(){
		//init sdl2
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 960;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        this->init_suc = false;
    }
    else
    {
        this->Window = SDL_CreateWindow( "ft_gkrellm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( this->Window == NULL )
        {
			std::cout << "Window could not created! SDL_Error: " << SDL_GetError() << std::endl;
            this->init_suc = false;
        }
        else
        {
			this->bar = SDL_LoadBMP("images/loading_bar.bmp");
			this->back = SDL_LoadBMP("images/background.bmp");
			this->point = SDL_LoadBMP("images/loading_point.bmp");
			this->container = SDL_LoadBMP("images/container.bmp");
			if (this->bar == NULL || this->point == NULL || this->back == NULL || this->container == NULL )
			{
				this->init_suc = false;
				std::cout << "images could not be imported! SDL_Error: " << SDL_GetError() << std::endl;
			}
			this->ScreenSurface = SDL_GetWindowSurface( this->Window );
        }
    }

}


void GraphicDisplay::destroy(){
		//destroy sdl2
}

void GraphicDisplay::refresh_data(){
	IMonitorModule *current;
	std::list<IMonitorModule *>::iterator start = this->modules.begin();
	std::list<IMonitorModule *>::iterator end = this->modules.end();
	while (start != end)
	{
		current = *start;
		current->get_value();
		++start;
	}
}

void GraphicDisplay::get_data(IMonitorModule *src){
	modules.push_back(src);
}

void GraphicDisplay::refresh(){
	std::cout << "31 !" << this->back << " | " <<  this->ScreenSurface <<std::endl;
	SDL_BlitSurface( this->back, NULL, this->ScreenSurface, NULL);
	std::cout << "32 !" << std::endl;
	SDL_UpdateWindowSurface( this->Window );
	std::cout << "33 !" << std::endl;
}

void GraphicDisplay::print_data(){
	if (this->modules.size() == 0)
		return;
	this->print_sliders();
	std::cout << this->y << "y !" << std::endl;
	int x = 20;
	IMonitorModule *current;
	std::list<IMonitorModule *>::iterator start = this->modules.begin();
	std::list<IMonitorModule *>::iterator end = this->modules.end();
	while (start != end)
	{
		current = *start;
		if (!current->is_slider())
		{
			if (x >= 500){
				x = 20;
				this->y += 270;
			}
			SDL_Rect dest = { x, this->y , 0, 0};
			SDL_BlitSurface( this->container, NULL, this->ScreenSurface, &dest);
			x += 275;
		}
		++start;
	}
	this->y += 20;

	SDL_UpdateWindowSurface( this->Window );
}

void GraphicDisplay::print_sliders(){
	// il y a la place de 13 boules

	//int size = 0;
	float tmp = 2;
	IMonitorModule *current;
	std::list<IMonitorModule *>::iterator start = this->modules.begin();
	std::list<IMonitorModule *>::iterator end = this->modules.end();
	while (start != end)
	{
		current = *start;
		if (current->is_slider())
		{
			SDL_Rect dest = { 100, this->y , 0, 0};
			SDL_BlitSurface( this->bar, NULL, this->ScreenSurface, &dest);
			tmp = (current->get_max() - current->get_min()) / 14;
			this->print_balls((std::atoi(current->get_data().c_str()) - current->get_min() ) / tmp);
			this->y += 50;
		}
		++start;

	}
	this->y += 50;
	//la boule est 30 * 30
}

void GraphicDisplay::print_balls(int ball_nb){
	for (int i = 0; i < ball_nb; ++i)
	{
		SDL_Rect dest = { 110 + 31 * i, this->y + 12, 0, 0};
		SDL_BlitSurface( this->point, NULL, this->ScreenSurface, &dest);
	}
}



