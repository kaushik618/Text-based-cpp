#include "FileOperations.h"

using namespace std;

void FileOperations::Save2File(player &p1) {
    P_myFile.seekg(0, ios::beg);

    //myfile << endl << endl;

    P_myFile.close();
    P_myFile.open(P_file_name, ios::out | ios::trunc);

    P_myFile << p1 << endl;
    //myFile << current << endl;
}

void FileOperations::Save2File(scoreboard &current) {
//	SB_myFile.seekg(0, ios::beg);

    //myfile << endl << endl;

    //SB_myFile.close();
    //SB_myFile.open(SB_file_name, ios::out | ios::trunc);
    SB_myFile.close();

    SB_myFile.open(SB_file_name, ios::app); // Append mode
    if (SB_myFile.is_open()) {
        SB_myFile.seekg(0, ios::beg);
        SB_myFile << current << endl;
    } else {
        cout << endl << "Error appending scoreboard.txt !" << endl;
    }

    SB_myFile.open(SB_file_name, ios::out);
    SB_myFile.seekg(0, ios::beg);
}

void FileOperations::ChooseFile(scoreboard &current, player &user) {
    string Answer;
    cout << "Do you have an existing file? " << endl;
    cout << "[Y]es or [N]o " << endl;
    cin >> Answer;

    char temp = (toupper(Answer[0]));

    //cout << endl << temp << endl;

    char Yes = 'Y';
    if (temp == Yes) {
        cout << "What is the file name? " << endl;
        cin >> Answer;
        P_file_name = Answer;

        string UserName;
        int InTmp;
        int dbTmp;

        P_myFile.open(P_file_name);
        if (P_myFile.fail()) {
            cerr << "File cannot be opened.";
            exit(1);
        } else {
            cout << "Player file successfully opened." << endl;

            P_myFile.seekg(0, ios::beg);

            getline(P_myFile, UserName);
            //cout << UserName;
            user.setName(UserName);
            //current.setName(UserName);

            P_myFile >> InTmp;
            //cout << InTmp;
            user.setHP(InTmp);

            P_myFile >> InTmp;
            user.setMaxHP(InTmp);

            P_myFile >> InTmp;
            user.setDMG(InTmp);

            //myFile >> UserName;
            ////cout << UserName;
            //current.setName(UserName);

            //myFile >> InTmp;
            ////cout << InTmp;
            //current.setScore(InTmp);

            //myFile >> UserName;
            //current.setDiff(UserName);
            //myFile >> dbTmp;
            //current.setDiffMod(dbTmp);
            //myFile >> InTmp;
            //current.setFloor(InTmp);
            //myFile.seekg(0, ios::beg);

        }
        //this->OpenFile();
        SB_myFile.open(SB_file_name);
        if (SB_myFile.fail()) {
            cerr << "Scoreboard file cannot be opened.";
            cout << "Creating new scoreboard file.";
            P_myFile.open(P_file_name, ios::out);

            cout << "Try again." << endl;

            SB_myFile.close();
            exit(1);
        } else {
            SB_myFile.seekg(0, ios::beg);

            SB_myFile >> UserName;
            //cout << UserName;
            current.setName(UserName);

            SB_myFile >> InTmp;
            //cout << InTmp;
            current.setScore(InTmp);

            SB_myFile >> UserName;
            current.setDiff(UserName);
            SB_myFile >> dbTmp;
            current.setDiffMod(dbTmp);
            SB_myFile >> InTmp;
            current.setFloor(InTmp);
            SB_myFile.seekg(0, ios::beg);

            SB_myFile.close();
            SB_myFile.open(SB_file_name);
        }

    } else if (temp == 'N') {
        //fstream File("SaveSlot1");
        cout << "What would you like to call this file? " << endl;
        cin >> P_file_name;
        P_myFile.open(P_file_name, ios::out);
        //myFile.open("SaveSlot1.txt", ios::out);
        if (!P_myFile) {
            cout << "Error in creating new fike!" << endl;
            exit(1);
        } else {
            cout << "Success in creating new file." << endl << endl;



            //Set Name
            cout << "What is your name?" << endl;
            cout << "> ";
            cin >> Answer;
            //getline(cin, Answer); //does not work
            current.setName(Answer);

            user.setName(Answer);
            P_myFile << user;

            bool valid = true;
            while (valid) {
                // Start difficulty
                cout << "What difficulty level do you want to play on?" << endl;
                cout << "Pick from: [E]asy, [M]edium, or [H]ard " << endl;
                cout << "> ";
                cin >> Answer;
                char temp = (toupper(Answer[0]));
                switch (temp) {
                    case 'E':
                        current.setDiff("Easy");
                        current.setDiffMod(1);
                        valid = 0;
                        break;

                    case 'M':
                        current.setDiff("Medium");
                        current.setDiffMod(2);
                        valid = 0;
                        break;

                    case 'H':
                        current.setDiff("Hard");
                        current.setDiffMod(3);
                        valid = 0;
                        break;
                    default:
                        cout << "Error. Not valid option." << endl;
                        valid = 1;
                }
            }

            if (!SB_myFile) {
                cerr << "No existing scorebaord.txt!" << endl << "Generating new file!" << endl;
                SB_myFile.open(SB_file_name, ios::out); //create scoreboard
            } else {
                cout << "Found existing scoreboard.txt!" << endl;

                SB_myFile << current;

            }

        }
    } else {
        cout << "Invalid response. " << endl;
        exit(1);
    }

}

//void FileOperations::OpenFile()
//{
//	//file_name = file;
//
//	//cout << "Save to file . . ." << endl;
//	//cin >> file_name;
//	myFile.open(file_name);
//	if (myFile.fail())
//	{
//		cerr << "File cannot be opened.";
//		exit(1);
//	}
//	else
//	{
//		cout << "Successfully opens the target file" << endl;
//	}
//}

void FileOperations::CloseFile() {
    P_myFile.close();
    SB_myFile.close();
}

void FileOperations::ScoreRank() {
    string a, b;
    int x, y, z, i = 1;

    vector<scoreboard> Rank;

    //while (!(SB_myFile.eof()))
    {
        SB_myFile >> a >> x >> b >> y >> z;
        Rank[i].setName(a);
        Rank[i].setScore(x);

        i++;
    }
    P_myFile.seekg(0, ios::beg);

    //bubble sort
    //bool swapp = true;
    //while (swapp) {
    //	swapp = false;
    //	for (size_t j = 0; j < (Rank.size() - 1); j++)
    //	{
    //		if ((Rank[j].getScore()) > (Rank[j + 1].getScore()))
    //		{
    //			x = Rank[j].getScore() ;
    //			z = Rank[j+1].getScore();

    //			x += z;
    //			Rank[j].setScore(x);
    //			z = x - z;
    //			Rank[j + 1].setScore(z);
    //			x -= z;
    //			Rank[j].setScore(x);

    //			swapp = true;
    //		}
    //	}
    //}

    for (size_t j = 0; j < (Rank.size() - 1); j++) {
        cout << "Scoreboard List: " << endl;
        cout << "Name: " << Rank[j].getName() << "Score: " << Rank[j].getScore() << endl;
    }

}