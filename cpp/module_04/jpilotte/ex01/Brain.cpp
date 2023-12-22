/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:00:38 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:00:41 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Brain.hpp"

Brain::Brain() {
	std::string newIdeas[] = {"Random idea 1", "Random idea 2", "Random idea 3", "Random idea 4", "Random idea 5", "Random idea 6", "Random idea 7", "Random idea 8", "Random idea 9", "Random idea 10" };
	for (int i = 0; i < 100; i++) {
		_ideas[i] = newIdeas[rand() % (sizeof(newIdeas) / sizeof(newIdeas[0]))];
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other.getIdeas(1);
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other.getIdeas(1);
		}
	}
	std::cout << "Brain assignation operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdeas(int i) const {
	return(_ideas[i]);
}