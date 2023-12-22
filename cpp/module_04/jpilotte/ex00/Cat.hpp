/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:39 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 12:59:40 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CAT_H
# define CAT_H

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();

	virtual void makeSound() const;
};

#endif