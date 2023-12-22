/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:33 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 12:59:34 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "A Cat was created.. Meow.." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "A Cat was created by copy constructor.. MEEEOOOWW!!!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "A Cat was assigned." << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "A Cat was destroyed.. rip" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat " << _type << " makes a sound.. Meow.." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Cat& cat) {
	os << cat.getType();
	return os;
}