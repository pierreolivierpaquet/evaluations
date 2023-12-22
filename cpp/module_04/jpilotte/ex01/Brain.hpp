/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:00:44 by jpilotte          #+#    #+#             */
/*   Updated: 2023/10/01 13:00:45 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

	const std::string& getIdeas(int i) const;

private:
	std::string _ideas[100];
};

#endif
