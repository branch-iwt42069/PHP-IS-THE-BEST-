#include "../headers/functions.h"
#include "../headers/design.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	readBase();
	init();
	short questionNumbers[20];
	while (true) {
		intro();
		mainMenu();
		
		srand(time(NULL));
       *questionNumbers = massive();
		short resultCounter = 0;
		short choose = 0;
		for (short i = 0; i < 20; ++i) {
			showQuestion(questionNumbers[i], i + 1);
			choose = readKey();
			if (checkAnswer(i, choose))
				resultCounter++;
		}
		showResult(resultCounter);
	}
	endProgramm();
	return 0;
}
