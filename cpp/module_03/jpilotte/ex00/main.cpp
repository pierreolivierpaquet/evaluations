/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:17 by jpilotte          #+#    #+#             */
/*   Updated: 2023/08/26 14:43:18 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

// int main() {
//     ClapTrap clapTrap1("ClapTrap1");
//     ClapTrap clapTrap2(clapTrap1);
//     ClapTrap clapTrap3("ClapTrap3");

//     clapTrap3 = clapTrap1;

//     clapTrap1.attack("enemy");
//     clapTrap1.beRepaired(5);
//     clapTrap1.takeDamage(3);

//     clapTrap2.attack("enemy");
//     clapTrap2.takeDamage(10);

//     clapTrap3.attack("enemy");
//     clapTrap3.beRepaired(10);
//     clapTrap3.takeDamage(15);

//     return 0;
// }

int main() {
    ClapTrap clapTrap("Bob");
    clapTrap.attack("enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    ClapTrap clapTrap2 = clapTrap;
    clapTrap2.attack("enemy");
    clapTrap2.takeDamage(10);
    clapTrap2.beRepaired(2);
    clapTrap2 = clapTrap;
    clapTrap2.attack("enemy");
    clapTrap2.takeDamage(15);
    clapTrap2.beRepaired(1);
    return 0;
}