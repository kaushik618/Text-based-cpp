#pragma once

#include <string>

using namespace std;

class weapon {
private:
    string W_item;
    //Name of the weapon item
    int W_damage;
    //Attack damage to the item. This can be added or removed by the player
    int W_usage;
    // No of times the weapon can be used
    int W_cost;
    //Cost to buy the weapon=

public:
    weapon();

    weapon(string i, int d, int u, int c);

    void setItem(string);

    void setDMG(int);

    void setUsage(int);

    void setCost(int);

    string getItem();

    int getDMG();

    int getUsage();

    int getCost();

};