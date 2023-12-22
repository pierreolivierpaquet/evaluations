
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clapTrap("ClapTrap");
    clapTrap.attack("enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    ScavTrap scavTrap("ScavTrap");
    scavTrap.attack("enemy");
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(3);

    FragTrap fragTrap("FragTrap");
    fragTrap.attack("enemy");
    fragTrap.takeDamage(5);
    fragTrap.beRepaired(3);
    fragTrap.highFivesGuys();

    return 0;
}