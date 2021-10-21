#include "scoreboard.h"

scoreboard::scoreboard() {
    SB_Name = "empty";
    SB_Score = 0;
    SB_Difficulty = "None";
    SB_DifficultyMod = 0;
    SB_Floor = 0;
}

void scoreboard::setName(string n) {
    SB_Name = n;
}

void scoreboard::setScore(int s) {
    SB_Score = s;
}

void scoreboard::setDiff(string d) {
    SB_Difficulty = d;
}

void scoreboard::setDiffMod(int d) {
    SB_DifficultyMod = d;
}

void scoreboard::setFloor(int f) {
    SB_Floor = f;
}

string scoreboard::getName() {
    return SB_Name;
}

int scoreboard::getScore() {
    return SB_Score;
}

string scoreboard::getDiff() {
    return SB_Difficulty;
}

int scoreboard::getDiffMod() {
    return SB_DifficultyMod;
}

int scoreboard::getFloor() {
    return SB_Floor;
}

void scoreboard::AddScore(int inc) {
    SB_Score += inc;
}

void scoreboard::SB_out() {
    cout << "Scoreboard:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Difficulty: " << getDiff() << endl;
    cout << "Score: " << getScore() << endl;
}

ostream &operator<<(ostream &os, const scoreboard &p) {
    os << p.SB_Name << endl;
    os << p.SB_Score << endl;
    os << p.SB_Difficulty << endl;
    os << p.SB_DifficultyMod << endl;
    os << p.SB_Floor << endl;
    return os;
}