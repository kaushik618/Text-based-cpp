#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "scoreboard.h"
#include "player.h"

using namespace std;

class FileOperations {
private:
    string SB_file_name = "scoreboard.txt";
    //holds the name of the scoreboard file
    fstream SB_myFile;
    //opens the scoreboard file

    string P_file_name;
    //holds the name of the player file
    fstream P_myFile;
    //opens the player file

public:
    void Save2File(player &);

    //Function Saves player progress into a file
    void Save2File(scoreboard &);
    //Function Saves scoreboard progress into a file

    void ChooseFile(scoreboard &, player &);

    //Function that asks the user to select the file to use
    //void OpenFile();
    void CloseFile();
    //Function to close the files

    void ScoreRank();
    //Function to output scores from all the scoreboards
};