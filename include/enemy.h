#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int level);

    std::string getName() const;
    int getLevel() const;
    int getHealth() const;
    int getDamage() const;
    void takeDamage(int damage);

    void setLevel(int level);

private:
    std::string name;
    int level;
    int health;
    int damage;

    void updateStats();
};

class Goblin : public Enemy {
public:
    Goblin(int level);
};

class Troll : public Enemy {
public:
    Troll(int level);
};

class Dragon : public Enemy {
public:
    Dragon(int level);
};

#endif // ENEMY_H
