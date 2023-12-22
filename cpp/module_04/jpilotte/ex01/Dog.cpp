/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:01:00 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:01:02 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "A Dog was created, woof" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain)) {
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

