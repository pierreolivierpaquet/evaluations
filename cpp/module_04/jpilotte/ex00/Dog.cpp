/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:45 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 12:59:46 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "A Dog was created, woof" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "A Dog was created by copy constructor, WOOF!!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "A Dog was assigned." << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "A Dog was destroyed, rip" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog " << _type << " makes a sound, woof" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Dog& dog) {
	os << dog.getType();
	return os;
}

