/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:02:26 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:02:27 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "A WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
	std::cout << "A WrongAnimal of type " << _type << " was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << "A WrongAnimal of type " << _type << " was created by copy constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "A WrongAnimal of type " << _type << " was assigned" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "A WrongAnimal of type " << _type << " was destroyed" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal " << _type << " makes a sound" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const WrongAnimal& wrongAnimal) {
	os << wrongAnimal.getType();
	return os;
}
