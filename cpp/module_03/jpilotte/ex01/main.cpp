/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:17 by jpilotte          #+#    #+#             */
/*   Updated: 2023/09/30 15:23:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clapTrap("ClapTrap");
    clapTrap.attack("enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    ScavTrap scavTrap("ScavTrap");
    scavTrap.attack("enemy");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(3);
    scavTrap.guardGate();
    return 0;
}