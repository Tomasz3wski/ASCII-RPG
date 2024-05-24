#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <memory>

class Weapon {
public:
    Weapon(const std::string& name);
    std::string getName() const;
private:
    std::string name;
};

class Character {
public:
    Character(const std::string& name, std::unique_ptr<Weapon> weapon);
    virtual ~Character() = default;

    std::string getName() const;
    std::string getWeaponName() const;

    virtual void displaySpecialAbility() const = 0;

private:
    std::string name;
    std::unique_ptr<Weapon> weapon;
};

class Mage : public Character {
public:
    Mage();
    void displaySpecialAbility() const override;
};

class Knight : public Character {
public:
    Knight();
    void displaySpecialAbility() const override;
};

class Hunter : public Character {
public:
    Hunter();
    void displaySpecialAbility() const override;
};

#endif // CHARACTER_H
