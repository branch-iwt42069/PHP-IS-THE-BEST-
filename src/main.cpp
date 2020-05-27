#include "../headers/design.h"
#include "../headers/functions.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    readBase();
    init();
    short questionNumbers[20];
    while (true) {
        intro();
        mainMenu();
        srand(time(NULL));
        *questionNumbers = massive();
        short resultCounter = 0;
        for (int i = 0; i < 20; ++i)
            questionNumbers[i] = i;
        for (int i = 0; i < 20; ++i) {
            questionNumbers[i] = i % dataBase.size();
            for (int j = i - 1; j >= 0; --j) {
                if (questionNumbers[i] == questionNumbers[j]) {
                    --i;
                    break;
                }
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
            showResult(resultCounter);
        }
        endProgramm();
        return 0;
    }
}
