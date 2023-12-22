/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:02:21 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 16:11:24 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  
  std::cout << "Testing testing" << std::endl;
  {
    Cat firstcat = Cat();
    Cat secondcat = Cat();
    Cat copycat = Cat(firstcat);

    std::cout << std::endl;
    for (int i = 0; i < 5; ++i) {
      std::cout << firstcat.think(i) << std::endl;
      std::cout << copycat.think(i) << std::endl;
      std::cout << secondcat.think(i) << std::endl;
      std::cout << std::endl;
    }
  }
  return 0;
}