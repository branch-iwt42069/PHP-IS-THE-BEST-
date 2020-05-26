#ifndef DESIGN_H
#define DESIGN_H

#include "../headers/functions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>

void init();
void intro();
void mainMenu();
void returnToNormalMode();
void showQuestion(short questionNumber, short currentQuestion);
void showResult(short result);

#endif