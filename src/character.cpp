#include <iostream>
#include "../include/character.h"

//Weapon
Weapon::Weapon(const std::string& name) : name(name) {}

std::string Weapon::getName() const {
    return name;
}

//Character
Character::Character(const std::string& name, std::unique_ptr<Weapon> weapon)
    : name(name), weapon(std::move(weapon)) {}

std::string Character::getName() const {
    return name;
}

std::string Character::getWeaponName() const {
    return weapon->getName();
}

//Mage
Mage::Mage() : Character("Mage", std::make_unique<Weapon>("Magic Staff")) {}

void Mage::displaySpecialAbility() const {
    std::cout << "special ability: powerful spells.\n";
}

//Knight
Knight::Knight() : Character("Knight", std::make_unique<Weapon>("Sword")) {}

void Knight::displaySpecialAbility() const {
    std::cout << "special ability: strong defense.\n";
}

//Hunter
Hunter::Hunter() : Character("Hunter", std::make_unique<Weapon>("Bow")) {}

void Hunter::displaySpecialAbility() const {
    std::cout << "special ability: ranged attacks.\n";
}
