#include "../headers/functions.h"
#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

vector< baseStruct > dataBase;

short massive(){
        short questionNumbers[20];
        for (int i = 0; i < 20; ++i)
			questionNumbers[i] = 0;
		for (int i = 0; i < 20; ++i) {
			questionNumbers[i] = i % dataBase.size();
		}
		return *questionNumbers;
}

int readBase() {
	ifstream ist("base.txt");
	baseStruct tempStruct;
	string r_ans;
	while(!ist.eof()) {
		if (ist.eof())
			break;
		getline(ist, tempStruct.ques);
		getline(ist, tempStruct.ans1);
		getline(ist, tempStruct.ans2);
		getline(ist, tempStruct.ans3);
		getline(ist, tempStruct.ans4);
		getline(ist, r_ans);
		tempStruct.right_ans = atoi(r_ans.c_str());
		dataBase.push_back(tempStruct);
	}
	return dataBase.size();
}

int readKey() {
	while (true) {
		char c = getch();
		switch(c) {
			case 'a': case 'A': case '1': {
				return 1;
				break;
			}
			case 'b': case 'B': case '2': {
				return 2;
				break;
			}
			case 'c': case 'C': case '3': {
				return 3;
				break;
			}
			case 'd': case 'D': case '4': {
				return 4;
				break;
			}
			case 27: {
				endProgramm();
				break;
			}
			default:
				break;
		}
	}
	return -1;
}

int checkAnswer(int questionNumber, int choose) {
	if (dataBase[questionNumber].right_ans == choose)
		return 1;
	else
		return 0;
}

void endProgramm() {
	returnToNormalMode();
	exit(0);
}
