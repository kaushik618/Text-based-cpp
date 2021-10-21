#include "player.h"

player::player() {
    Name = "Player";
    MaxHealth = 100;
    HealthPoints = MaxHealth;
    AttackDamage = 0;

}

string player::getName() {
    return Name;
}

int player::getHP() {
    return HealthPoints;
}


int player::getDMG() {
    return AttackDamage;
}

int player::getMaxHP() {
    return MaxHealth;
}

void player::setName(string n) {
    Name = n;
}

void player::setHP(int hp) {
    HealthPoints = hp;
}

void player::setMaxHP(int hp) {
    MaxHealth = hp;
}

void player::setDMG(int dmg) {
    AttackDamage = dmg;
}

void player::ModifyHealth(int hp) {
    HealthPoints += hp;
}


void player::ModifyDamage(int dmg) {
    AttackDamage += dmg;
}

ostream &operator<<(ostream &os, const player &p) {
    os << p.Name << endl;
    os << p.MaxHealth << endl;
    os << p.HealthPoints << endl;
    os << p.AttackDamage << endl;

    return os;
}