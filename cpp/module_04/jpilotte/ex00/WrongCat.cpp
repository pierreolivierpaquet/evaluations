/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:00:17 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 15:58:14 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "A WrongCat was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "A WrongCat was created by copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "A WrongCat was assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "A WrongCat was destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat " << _type << " makes a sound.. kwack kwack" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const WrongCat& wrongCat) {
	os << wrongCat.getType();
	return os;
}
