#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <memory>


class Weapon {
public:
    explicit Weapon(const std::string& name);
    std::string getName() const;
    int getDamage() const;
private:
    std::string name;
    int damage;
};

class Character {
public:
    Character(const std::string& name, const std::string& description, std::unique_ptr<Weapon> weapon);
    virtual ~Character() = default;

    std::string getName() const;
    std::string getWeaponName() const;
    std::string getDescription() const;
    int getLevel() const;
    int getExp() const;
    int getExpToNextLevel() const;
    void gainExp(int amount);
    int getHealth() const;
    void addHealth();
    int getDamage() const;
    void takeDamage(int damage);
    void setName(const std::string& newName);
    void displayStats() const;

    virtual void displaySpecialAbility() const = 0;
    virtual std::string getClassName() const = 0;

private:
    std::string name;
    std::string description;
    std::unique_ptr<Weapon> weapon;
    int level;
    int exp;
    int expToNextLevel;
    int health;

    void levelUp();
};

class Mage : public Character {
public:
    Mage();
    void displaySpecialAbility() const override;
    std::string getClassName() const override;
};

class Knight : public Character {
public:
    Knight();
    void displaySpecialAbility() const override;
    std::string getClassName() const override;
};

class Hunter : public Character {
public:
    Hunter();
    void displaySpecialAbility() const override;
    std::string getClassName() const override;
};

#endif // CHARACTER_H
