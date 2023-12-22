/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:00:49 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:00:51 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "A Cat was created.. Meow.." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "A Cat was created by copy constructor.. MEEEOOOWW!!!" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  this->_brain = other._brain;
  return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "A Cat was destroyed.. rip" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow.." << std::endl;
}


const std::string& Cat::think(int i) const {
	return _brain->getIdeas(i);
}