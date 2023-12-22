/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:02:00 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:02:01 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : _brain(new Brain()) {
	this->_type = "Cat";
	std::cout << "A Cat was created.. Meow.." << std::endl;
}

Cat::Cat(const Cat& other) : _brain(new Brain(*other._brain)) {
	this->_type = "Cat";
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

std::string Cat::getType() const { 
	return(_type); 
}