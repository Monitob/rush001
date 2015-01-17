/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:37:56 by jbernabe          #+#    #+#             */
/*   Updated: 2015/01/17 12:38:10 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Gkrellm {

public:
  Gkrellm(std::string name);
  std::string getName();
  void setName(std::string name);


private:

  std::string _name;

  Gkrellm();
  Gkrellm(GKrellm & const src);
  ~Gkrellm();
  Gkrellm & operator=(Gkrellm & f);

};
