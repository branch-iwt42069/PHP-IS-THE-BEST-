#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

struct baseStruct {
	string ques;
	string ans1;
	string ans2;
	string ans3;
	string ans4;
	short right_ans;
};

extern vector< baseStruct > dataBase;

short massive();
int readBase();
int readKey();
int checkAnswer(int questionNumber, int choose);
void endProgramm();

#endif
