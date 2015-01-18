/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicDisplay.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:12:27 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 07:22:16 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GraphicDisplay.class.hpp"
#include "../inc/IMonitorModule.interface.hpp"
#include <SDL2/SDL.h>
GraphicDisplay::GraphicDisplay()
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
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Window* gWindow = NULL;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        //success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
           // success = false;
        }
        else
        {
            //Get window surface
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

}

void GraphicDisplay::print_data(){

}

void GraphicDisplay::print_sliders(){

}