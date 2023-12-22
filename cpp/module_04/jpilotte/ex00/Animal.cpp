/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:19 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 12:59:20 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "An Animal was created" << std::endl;
}

Animal::Animal(const std::string type) : _type(type) {
	std::cout << "An Animal of type " << _type << " was created" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "An Animal of type " << _type << " was created by copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "An Animal of type " << _type << " was assigned" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "An Animal of type " << _type << " was destroyed" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "Animal " << _type << " makes a sound" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Animal& animal) {
	os << animal.getType();
	return os;
}