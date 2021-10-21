//Main File

#include<iostream>
#include<iomanip>
#include<vector>
#include <string>
#include <cmath>

#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "scoreboard.h"
#include "FileOperations.h"
#include "functions.h"

using namespace std;

void PlayerCombat(player &, weapon[4][4], enemy &, scoreboard &);

//void PlayerCombat(int, player&, enemy&);
bool EnemyCombat(enemy &, player &, scoreboard &);

void PlayerOptions(player &, FileOperations &, scoreboard &);

void ChoooseWeapon(weapon[4][4], int, player &);

int main() {

    int FloorCount = 0;
    //vector<vector<weapon>> WeaponList(4, vector<weapon>(4,1));

    weapon w11("fist", 5), w12("stick", 10), w13("rock", 15), w14("sling-shot", 20),
            w21("dagger", 25), w22("sword", 30), w23("hammer", 35), w24("crossbow", 40),
            w31("gauntlet", 45), w32("spear", 50), w33("mace", 55), w34("pistol", 60),
            w41("axe", 65), w42("whip", 70), w43("bomb", 75), w44("spell-book", 80);
    weapon WeaponList[4][4] = {{w11, w12, w13, w14},
                               {w21, w22, w23, w24},
                               {w31, w32, w33, w34},
                               {w41, w42, w43, w44}};

    FileOperations SaveSlot;
    scoreboard LeaderBoard;
    player Player1;

    SaveSlot.ChooseFile(LeaderBoard, Player1);
    SaveSlot.Save2File(LeaderBoard);
    SaveSlot.Save2File(Player1);

    cout << endl
         << "****************************************" << endl
         << "The adventure begins! Anything can happen. " << endl
         << "A path is before you . . ." << endl;

    //SaveSlot.Save2File(LeaderBoard);
    //SaveSlot.Save2File(Player1);

    PlayerOptions(Player1, SaveSlot, LeaderBoard);

    if (LeaderBoard.getFloor() == 0) {
        FloorCount++;
        cout << "You enter " << FloorCount << endl;
        LeaderBoard.setFloor(FloorCount);

        enemy mob1("Goblin", 10, 10, 2, 1);
        cout << "A " << mob1.getName() << " blocks your path." << endl;
        PlayerCombat(WeaponList, Player1, mob1, LeaderBoard);
        //PlayerCombat(FloorCount, Player1, troll);

        //ChoooseWeapon(WeaponList, FloorCount, Player1);
        SaveSlot.Save2File(LeaderBoard);
        SaveSlot.Save2File(Player1);
        PlayerOptions(Player1, SaveSlot, LeaderBoard);

    }
    if (LeaderBoard.getFloor() == 1) {
        FloorCount++;
        cout << "You enter floor " << FloorCount << endl;
        LeaderBoard.setFloor(FloorCount);

        enemy mob2("Troll", 15, 20, 2, 2);
        cout << "A " << mob2.getName() << " blocks your path." << endl;
        PlayerCombat(WeaponList, Player1, mob2, LeaderBoard);

        SaveSlot.Save2File(LeaderBoard);
        SaveSlot.Save2File(Player1);
        PlayerOptions(Player1, SaveSlot, LeaderBoard);

    }
    if (LeaderBoard.getFloor() == 2) {
        FloorCount++;
        cout << "You enter floor" << FloorCount << endl;
        LeaderBoard.setFloor(FloorCount);


        enemy mob3("slime", 20, 5, 2, 3);
        cout << "A " << mob3.getName() << " blocks your path." << endl;
        PlayerCombat(WeaponList, Player1, mob3, LeaderBoard);

        SaveSlot.Save2File(LeaderBoard);
        SaveSlot.Save2File(Player1);
        PlayerOptions(Player1, SaveSlot, LeaderBoard);

    }
    if (LeaderBoard.getFloor() == 3) {
        FloorCount++;
        cout << "You enter floor" << FloorCount << endl;
        LeaderBoard.setFloor(FloorCount);


        enemy mob4("dragon", 20, 20, 2, 4);
        cout << "A " << mob4.getName() << " blocks your path." << endl;
        PlayerCombat(WeaponList, Player1, mob4, LeaderBoard);
        SaveSlot.Save2File(LeaderBoard);
        SaveSlot.Save2File(Player1);
    }

    cout << endl << "******************************************" << endl
         << "You are at the end. Congratulations! " << endl;

    LeaderBoard.SB_out();

    SaveSlot.ScoreRank();

    system("pause");
    return 0;
}

