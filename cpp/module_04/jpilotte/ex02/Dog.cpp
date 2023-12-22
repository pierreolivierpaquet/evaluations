/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:02:10 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:02:11 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : _brain(new Brain()) {
	this->_type = "Dog";
	std::cout << "A Dog was created, woof" << std::endl;
}

Dog::Dog(const Dog& other) : _brain(new Brain(*other._brain)) {
	this->_type = "Dog";
	std::cout << "A Dog was created by copy constructor, WOOF!!" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
  this->_brain = other._brain;
  return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "A Dog was destroyed, rip" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

const std::string& Dog::think(int i) const {
	return _brain->getIdeas(i);
}

std::string Dog::getType() const { 
	return(_type); 
}