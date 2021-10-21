#include "weapon.h"

weapon::weapon() {
    W_item = "air";
    W_damage = 0;

}

weapon::weapon(string i, int d, int u, int c) {
    W_item = i;
    W_damage = d;
    W_usage = u;
    W_cost = c;
}

void weapon::setItem(string i) {
    W_item = i;
}

void weapon::setDMG(int d) {
    W_damage = d;
}

void weapon::setUsage(int u) {
    W_usage = u;
}

void weapon::setCost(int c) {
    W_cost = c;
}

string weapon::getItem() {
    return W_item;
}

int weapon::getDMG() {
    return W_damage;
}
