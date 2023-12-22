/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:00:00 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:00:01 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  {
    const Animal* meta = new Animal("Unidentified");
    meta->makeSound();
    std::cout << meta->getType() << " " << std::endl;
    delete meta;
    std::cout << std::endl;

    const Animal* i = new Cat();
    std::cout << "set type " << i->getType() << std::endl;
    i->makeSound();
    delete i;
    std::cout << std::endl;

    const Animal* j = new Dog();
    std::cout << "set type " << j->getType() << std::endl;
    j->makeSound();
    delete j;
    std::cout << std::endl;
  }
  std::cout << std::endl;
  {
    const WrongAnimal* meta = new WrongAnimal();
    meta->makeSound();
    delete meta;
    std::cout << std::endl;

    const WrongAnimal* i = new WrongCat();
    std::cout << "set type " << i->getType() << std::endl;
    i->makeSound();
    delete i;
    std::cout << std::endl;
  }
  return 0;
}