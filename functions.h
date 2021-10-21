#pragma once

using namespace std;

void ChoooseWeapon(weapon w1[4][4], int f, player &p1);

void PlayerCombat(weapon w1[4][4], player &p1, enemy &e1, scoreboard &s1);

bool EnemyCombat(enemy &e1, player &p1, scoreboard &s1);

void PlayerOptions(player &p, FileOperations &f, scoreboard &s);


void ChoooseWeapon(weapon w1[4][4], int f, player &p1) {
    int floor = (f - 1);
    bool valid = true;
    int choice;
    while (valid) {
        cout << "What weapon would you like to use? " << endl;

        for (int i = 0; i < 4; i++) {
            cout << "Option: " << (i + 1) << ": " << w1[floor][i].getItem() << " " << w1[floor][i].getDMG() << endl;
        }
        cout << "> ";
        cin >> choice;
        if (choice < 1 || choice > 4) {
            cout << "Invalid option, try again." << endl;
            valid = true;
        } else {
            cout << "You have selected the " << w1[floor][(choice - 1)].getItem() << " as your weapon." << endl;
            p1.setDMG(w1[floor][(choice - 1)].getDMG());
            valid = false;
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

        if (p1.getHP() < 0 || p1.getHP() == 0) {
            cout << "You have " << p1.getHP() << " out of " << p1.getMaxHP() << endl;
            cout << "Game Over." << endl;

            s1.SB_out();

            exit(10);
        }
    } else {
        cout << "The " << e1.getName() << " was defeated! " << endl;
        cout << "**********************" << endl;
        s1.AddScore(s1.getDiffMod());

        return false;
    }
}


void PlayerOptions(player &p, FileOperations &f, scoreboard &s) {
    string choose;
    char simpleChoose;

    bool valid = true;
    while (valid) {

        cout << "What would you like to do? " << endl
             << "[E]xamine Self, [B]uy Weapon, [C]ontinue, [S]coreboard, [Q]uit" << endl;
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
            case 'B':


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