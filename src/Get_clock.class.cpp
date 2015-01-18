/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_clock.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:50:20 by sbres             #+#    #+#             */
/*   Updated: 2015/01/18 06:26:05 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "../inc/Get_clock.class.hpp"

Get_clock::Get_clock()
{

}

Get_clock::Get_clock(std::string str)
{
  this->store_string(str);
}

template <typename T>
std::string NumberToString ( T Number )
{
  std::ostringstream ss;
  ss << Number;
  return ss.str();
}

void Get_clock::get_value(){
    time_t now = time(0);
    std::string dateData = new char[100];

    tm *ltm = localtime(&now);

    dateData += "Year: ";
    dateData += NumberToString(1900 + ltm->tm_year);
    dateData +=  " Month:  ";
    dateData += NumberToString(1 + ltm->tm_mon);
    dateData += " Day: ";
    dateData += NumberToString(ltm->tm_mday);
    dateData += " Time: ";
    dateData += NumberToString(1 + ltm->tm_hour);
    dateData += " : ";
    dateData += NumberToString(1 + ltm->tm_min);
    dateData += " : ";
    dateData += NumberToString(1 + ltm->tm_sec);
    this->store_string(dateData);
}

Get_clock & Get_clock::operator=(Get_clock & src){
  this->store_string(src.get_value());
}

Get_clock::~Get_clock()
{

}
