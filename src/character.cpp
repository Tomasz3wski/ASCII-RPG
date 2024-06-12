#include <iostream>
#include "../include/character.h"

//weapon
Weapon::Weapon(const std::string& name) : name(name), damage(10) {}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}

//character
Character::Character(const std::string& name, const std::string& description, std::unique_ptr<Weapon> weapon)
    : name(name), description(description), weapon(std::move(weapon)), level(1), exp(0), expToNextLevel(100), health(100) {}


std::string Character::getName() const {
    return name;
}

std::string Character::getWeaponName() const {
    return weapon->getName();
}


std::string Character::getDescription() const {
    return description;
}

int Character::getLevel() const {
    return level;
}

int Character::getExp() const {
    return exp;
}

int Character::getExpToNextLevel() const {
    return expToNextLevel;
}

void Character::gainExp(int amount) {
    exp += amount;
    if (exp >= expToNextLevel) {
        levelUp();
    }
}

int Character::getHealth() const {
    return health;
}

void Character::addHealth() {
    health += 50;
}

int Character::getDamage() const {
    int damage = (weapon->getDamage())+level*2;
    return damage;
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Character::displayStats() const{
    std::cout << "Character Name: " << getName() << "\n";
    std::cout << "Class: " << getClassName() << "\n";
    std::cout << "Damage: " << getDamage() << "\n";
    std::cout << "HP: " << getHealth() << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "EXP: " << getExp() << " / " << getExpToNextLevel() << "\n";
}

void Character::levelUp() {
    exp -= expToNextLevel;
    level++;
    expToNextLevel *= 1.5;
    health += 50;
    std::cout << "Level up! You are now level " << level << "!\n";
}

void Character::setName(const std::string& newName) {
    name = newName;
}

//mage
Mage::Mage() : Character("Mage", "A powerful spellcaster with a variety of magical abilities.", std::make_unique<Weapon>("Magic Staff")) {}

void Mage::displaySpecialAbility() const {
    std::cout << "Mage's special ability: Casts powerful spells.\n";
}

std::string Mage::getClassName() const {
    return "Mage";
}

//knight
Knight::Knight() : Character("Knight", "A heavily armored warrior with strong defense.", std::make_unique<Weapon>("Sword")) {}

void Knight::displaySpecialAbility() const {
    std::cout << "Knight's special ability: Has strong defense.\n";
}

std::string Knight::getClassName() const {
    return "Knight";
}

//hunter
Hunter::Hunter() : Character("Hunter", "A quick and agile ranged attacker.", std::make_unique<Weapon>("Bow")) {}

void Hunter::displaySpecialAbility() const {
    std::cout << "Hunter's special ability: High agility and ranged attacks.\n";
}

std::string Hunter::getClassName() const {
    return "Hunter";
}