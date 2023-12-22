/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:01:14 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:01:15 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
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
  return 0;
}
