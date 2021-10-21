#include "enemy.h"

using namespace std;

enemy::enemy() {
    Name = "Mob";
    MaxHealth = 20;
    HealthPoints = MaxHealth;
    AttackDamage = 0;
    level = 0;
}

enemy::enemy(string n, int mh, int hp, int atk, int lvl) {
    Name = n;
    MaxHealth = mh;
    HealthPoints = hp;
    AttackDamage = atk;
    level = lvl;
}

string enemy::getName() {
    return Name;
}

int enemy::getHP() {
    return HealthPoints;
}


int enemy::getDMG() {
    return AttackDamage;
}

int enemy::getMaxHP() {
    return MaxHealth;
}

int enemy::getLVL() {
    return level;
}

void enemy::setName(string n) {
    Name = n;
}

void enemy::setHP(int hp) {
    HealthPoints = hp;
}

void enemy::setMaxHP(int hp) {
    MaxHealth = hp;
}

void enemy::setDMG(int dmg) {
    AttackDamage = dmg;
}

void enemy::setLVL(int lvl) {
    level = lvl;
}

void enemy::ModifyHealth(int hp) {
    HealthPoints += hp;
}


void enemy::ModifyDamage(int dmg) {
    AttackDamage += dmg;
}