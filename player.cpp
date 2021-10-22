#include "player.h"

player::player() {
    Name = "Player";
    MaxHealth = 100;
    HealthPoints = MaxHealth;
    AttackDamage = 0;
    totalCurrency = 0;
    listOfWeaponsOwned;

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

int player::getCurrency() {
    return totalCurrency;
}

vector<weapon> player::getListOfWeapons() {
    return listOfWeaponsOwned;
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

void player::setCurrency(int cur) {
    totalCurrency = cur;
}


void player::ModifyHealth(int hp) {
    HealthPoints += hp;
}


void player::ModifyDamage(int dmg) {
    AttackDamage += dmg;
}

//There are 2 times when this method is called, when weapon is purchased (amount decreases)
// and when enemy is defeated (amount increases)
bool player::ModifyCurrency(bool isEnemyDefeated, bool isWeaponPurchased, int amount) {
    if (isEnemyDefeated) {
        totalCurrency += amount;
    }
    if (isWeaponPurchased) {
        if (totalCurrency - amount < 0) {
            cout << "Not enough Money in your wallet to buy the weapon" << endl;
            return false;
        } else {
            totalCurrency -= amount;
        }
    }
    return true;
}

void player::addWeapons(weapon w1) {
    listOfWeaponsOwned.push_back(w1);
}

ostream &operator<<(ostream &os, const player &p) {
    os << p.Name << endl;
    os << p.MaxHealth << endl;
    os << p.HealthPoints << endl;
    os << p.AttackDamage << endl;
    os << p.totalCurrency << endl;

    return os;
}