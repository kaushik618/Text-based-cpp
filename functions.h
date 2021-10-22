#pragma once

using namespace std;

void ChoooseWeapon(weapon w1[4][4], int f, player &p1);

void PlayerCombat(weapon w1[4][4], player &p1, enemy &e1, scoreboard &s1);

bool EnemyCombat(enemy &e1, player &p1, scoreboard &s1);

void PlayerOptions(player &p, FileOperations &f, scoreboard &s);


void ChoooseWeapon(weapon w1[4][4], int f, player &p1) {
    int floor = (f - 1);
    bool valid = true;
    string choice;
    while (valid) {
        cout << "What weapon would you like to use? enter the weapon name" << endl;

        for (weapon w2 : p1.getListOfWeapons()) {
            cout << "Weapon : " << w2.getItem() << " Damage: " << w2.getDMG() << endl;
        }

        cout << "> ";
        cin >> choice;

        for (weapon w2 : p1.getListOfWeapons()) {
            if (choice == w2.getItem()) {
                if (w2.getUsage() < 1) {
                    cout << "you already used the weapon, please use a diff one " << endl;
                    valid = true;
                } else {
                    cout << "You have selected the " << w2.getItem() << " as your weapon." << endl;
                    p1.setDMG(w2.getDMG());
                    valid = false;
                }
            } else {
                cout << "Invalid option, try again." << endl;
                valid = true;
            }
        }
    }

}

void PlayerCombat(weapon w1[4][4], player &p1, enemy &e1, scoreboard &s1)
//void PlayerCombat(int CurrentFloor, player& p1, enemy& e1)
{
    string choice;
    char SimpleChoice;

    bool Fight = true;
    while (Fight) {
        cout << endl << "What would you like to do? " << endl;
        cout << "[A]ttack" << endl;
        //	cout << "[C]hange Weapon" << endl;
        cout << "Examine [S]elf " << endl;
        cout << "Examine [E]nemy " << endl;
        cout << "> ";
        cin >> choice;
        SimpleChoice = (toupper(choice[0]));

        switch (SimpleChoice) {
            default:
                cout << "Not a valid option. Try again." << endl;
                break;
            case 'A':
                //cout << "What weapon would you like to use? " << endl;
                //ChoooseWeapon(w1, CurrentFloor, p1);
                ChoooseWeapon(w1, s1.getFloor(), p1);
                cout << "You attack the " << e1.getName() << endl;
                e1.ModifyHealth(((-1) * (p1.getDMG())));
                Fight = EnemyCombat(e1, p1, s1);
                //Fight = true;
                break;

            case 'S':
                cout << "Max Health: " << p1.getMaxHP() << endl;
                cout << "Current Health: " << p1.getHP() << endl;
                cout << "Attack Damage: " << p1.getDMG() << endl;
                cout << endl;
                break;
            case 'E':
                cout << "Max Health: " << e1.getMaxHP() << endl;
                cout << "Current Health: " << e1.getHP() << endl;
                cout << "Attack Damage: " << e1.getDMG() << endl;
                cout << "Level: " << e1.getLVL() << endl;
                cout << endl;
                break;
        }
    }

}


bool EnemyCombat(enemy &e1, player &p1, scoreboard &s1) {
    if (e1.getHP() > 0) {
        cout << "The " << e1.getName() << " attacks!" << endl;
        p1.ModifyHealth(((-1) * e1.getDMG()) * (s1.getDiffMod()));
        cout << "You lose " << e1.getDMG() << " health!" << endl;

        return true;
    } else {
        cout << "The " << e1.getName() << " was defeated! " << endl;
        cout << "**********************" << endl;
        s1.AddScore(s1.getDiffMod());
        //Adds currency when enemy is defeated
        p1.ModifyCurrency(true, false, e1.getCurrency());
        // TODO: NEED to reduce the usage of weapon to zero.
        return false;
    }
}


void PlayerOptions(player &p, FileOperations &f, scoreboard &s, weapon w1[4][4]) {
    string choose;
    string chooseWeapon;
    char simpleChoose;

    bool valid = true;
    while (valid) {

        cout << "What would you like to do? " << endl
             << "[E]xamine Self, [W]eapon buy, [C]ontinue, [S]coreboard, [Q]uit" << endl;
        cout << "> ";
        cin >> choose;
        simpleChoose = toupper(choose[0]);


        switch (simpleChoose) {
            default:
                cout << "Not a valid option. Try again." << endl;
                valid = 1;
                break;

            case 'E':
                cout << "Name: " << p.getName() << endl;
                cout << "Max Health: " << p.getMaxHP() << endl;
                cout << "Current Health: " << p.getHP() << endl;
                cout << "Attack Damage: " << p.getDMG() << endl;
                cout << endl;
                valid = 1;
                break;

            case 'C' :
                cout << "Carrying on . . ." << endl;
                cout << endl << "**************************" << endl;
                valid = 0;
                break;

            case 'S' :
                //cout << s << endl;
                cout << "Name: " << s.getName() << endl;
                cout << "Score: " << s.getScore() << endl;
                cout << "Difficulty: " << s.getDiff() << endl;
                cout << "Floor Number: " << s.getFloor() << endl;
                cout << endl;
                valid = 1;
                break;
            case 'W':
                cout << "Which weapon would like to buy? Type the weapon name" << endl;
                for (int i = 0; i<4; i++) {
                    for (int j = 0; j < 4; j++) {
                        cout << "weapon name: " << w1[i][j].getItem() << " cost: " << w1[i][j].getCost() << endl;
                    }
                }
                cin >> chooseWeapon;
                for (int i = 0; i<4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (w1[i][j].getItem() == chooseWeapon) {
                            int cost = w1[i][j].getCost();
                            if (!p.ModifyCurrency(false, true, cost)) {
                                cout << "Not enough money - please choose other weapon" << endl;
                            } else {
                                cout << "Weapon bough, adding to your weapon list" << endl;
                                p.addWeapons(w1[i][j]); // Add to list of player weapons
                            }
                        } else {
                            cout << "Invalid weapon choice - please try again" << endl;
                        }
                    }
                }
                valid = 1;
                break;

            case 'Q' :
                f.Save2File(p);
                f.Save2File(s);
                f.CloseFile();
                valid = 0;
                exit(10);
                break;
        }
    }

}