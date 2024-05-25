#include "../include/enemy.h"

Enemy::Enemy(const std::string& name, int level)
    : name(name), level(level) {
    updateStats();
}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getLevel() const {
    return level;
}

int Enemy::getHealth() const {
    return health;
}

int Enemy::getDamage() const {
    return damage;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Enemy::setLevel(int level) {
    this->level = level;
    updateStats();
}

void Enemy::updateStats() {
    health = 50 + 10 * level;
    damage = 5 + 2 * level;
}

//goblin
Goblin::Goblin(int level)
    : Enemy("Goblin", level) {}

//troll
Troll::Troll(int level)
    : Enemy("Troll", level) {}

//dragon
Dragon::Dragon(int level)
    : Enemy("Dragon", level) {}
