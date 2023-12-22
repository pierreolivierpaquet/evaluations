/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:00:54 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:00:56 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CAT_H
# define CAT_H

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();

	virtual void makeSound() const;
	const std::string& think(int i) const;

private:
	Brain *_brain;
};

#endif