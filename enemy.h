#pragma once

#include "player.h"

using namespace std;

//class enemy : public player
class enemy {
private:
    string Name;
    //This should hold the player�s name
    int MaxHealth;
    //This should hold the maximum health of the player
    int HealthPoints;
    //This should hold the current health of the player
    int AttackDamage;
    //This should hold the attack damage of the player

    int level = 0;

public:
    enemy();

    enemy(string, int, int, int, int);

    string getName();

    int getMaxHP();

    //returns the maximum health
    int getHP();

    //returns the current health
    int getDMG();

    //returns the current damage
    int getLVL();
    //returns the level

    void setName(string);

    void setMaxHP(int);

    void setHP(int);

    //sets the current health
    void setDMG(int);

    //sets the current damage
    void setLVL(int);
    //sets the level

    void ModifyHealth(int);

    //Increments or decrements the player�s health by the input value
    void ModifyDamage(int);
    //Increments or decrements the player�s attack damage by the input value

};