#include "../headers/design.h"
#include "../headers/functions.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <locale.h>

void init() {
	//setlocale(LC_ALL, "");
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);
	attron(COLOR_PAIR(1));
	bkgd(COLOR_PAIR(1));
	refresh();
}

void intro() {
	clear();
	attron(COLOR_PAIR(2));
	border(0, 0, 0, 0, 0, 0, 0, 0);
	attron(COLOR_PAIR(1));
	move(1, 3);
	addstr(" _______  _______  _______  _______    _______          _________ _______ ");
	move(2, 3);
	addstr("(  ____ )(  ____ )(  ___  )(  ____ \\  (  ___  )|\\     /|\\__   __// ___   )");
	move(3, 3);
	addstr("| (    )|| (    )|| (   ) || (    \\/  | (   ) || )   ( |   ) (   \\/   )  |");
	move(4, 3);
	addstr("| (____)|| (____)|| |   | || |        | |   | || |   | |   | |       /   )");
	move(5, 3);
	addstr("|  _____)|     __)| |   | || | ____   | |   | || |   | |   | |      /   / ");
	move(6, 3);
	addstr("| (      | (\\ (   | |   | || | \\_  )  | | /\\| || |   | |   | |     /   /  ");
	move(7, 3);
	addstr("| )      | ) \\ \\__| (___) || (___) |  | (_\\ \\ || (___) |___) (___ /   (_/\\");
	move(8, 3);
	addstr("|/       |/   \\__/(_______)(_______)  (____\\/_)(_______)\\_______/(_______/");
	attron(COLOR_PAIR(2));
	move(11, 20);
	addstr("Авторы:");
	move(13, 20);
	addstr("Макогон Данил");
	move(14, 20);
	addstr("Певнев Александр");
	move(15, 20);
	addstr("Федосов Кирилл");
	move(18, 20 );
	addstr("Для продолжения нажми любую клавишу");
	refresh();
	getch();
}

void mainMenu() {
	clear();
	attron(COLOR_PAIR(2));
	border(0, 0, 0, 0, 0, 0, 0, 0);
	attron(COLOR_PAIR(1));
	move(1, 3);
	addstr(" _______  _______  _______  _______    _______          _________ _______ ");
	move(2, 3);
	addstr("(  ____ )(  ____ )(  ___  )(  ____ \\  (  ___  )|\\     /|\\__   __// ___   )");
	move(3, 3);
	addstr("| (    )|| (    )|| (   ) || (    \\/  | (   ) || )   ( |   ) (   \\/   )  |");
	move(4, 3);
	addstr("| (____)|| (____)|| |   | || |        | |   | || |   | |   | |       /   )");
	move(5, 3);
	addstr("|  _____)|     __)| |   | || | ____   | |   | || |   | |   | |      /   / ");
	move(6, 3);
	addstr("| (      | (\\ (   | |   | || | \\_  )  | | /\\| || |   | |   | |     /   /  ");
	move(7, 3);
	addstr("| )      | ) \\ \\__| (___) || (___) |  | (_\\ \\ || (___) |___) (___ /   (_/\\");
	move(8, 3);
	addstr("|/       |/   \\__/(_______)(_______)  (____\\/_)(_______)\\_______/(_______/");
	attron(COLOR_PAIR(2));
	move(11, 10);
	addstr("Правила:");
	move(13, 10);
	addstr("Вам предложено пройти тест на знание программирования.");
	move(14, 10);
	addstr("В конца теста на экране высветится ваш уровень навыков");
	move(15, 10);
	addstr("программирования, составленный на основе ваших ответов.");
	move(17, 10);
	addstr("Управление:");
	move(19, 10);
	addstr("Нажимай '1', '2', '3', '4' или 'A', 'B', 'C', 'D'");
	move(20, 10);
	addstr("для выбора варианта ответа");
	move(21, 10);
	addstr("Нажми ESCAPE в любой момент для выхода.");
	refresh();
	getch();
}

void showQuestion(short questionNumber, short currentQuestion) {
	clear();
	move(2, 34);
	printw("%d / 20", currentQuestion);
	attron(COLOR_PAIR(2));
	move(6, 10);
	for (unsigned short i = 0; i < dataBase[questionNumber].ques.size(); ++i) {
		char c = dataBase[questionNumber].ques[i];
		if (c == '$')
			printw("\n\t  ");
		else
		printw("%c", c);
	}
	move(11, 11);
	addstr("1) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans1.size(); ++i) {
		char c = dataBase[questionNumber].ans1[i];
		if (c == '$')
			printw("\n\t   ");
		else
		printw("%c", c);
	}
	move(14, 11);
	addstr("2) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans2.size(); ++i) {
		char c = dataBase[questionNumber].ans2[i];
		if (c == '$')
			printw("\n\t   ");
		else
		printw("%c", c);
	}
	move(17, 11);
	addstr("3) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans3.size(); ++i) {
		char c = dataBase[questionNumber].ans3[i];
		if (c == '$')
			printw("\n\t   ");
		else
		printw("%c", c);
	}
	move(20, 11);
	addstr("4) ");
	for (unsigned short i = 0; i < dataBase[questionNumber].ans4.size(); ++i) {
		char c = dataBase[questionNumber].ans4[i];
		if (c == '$')
			printw("\n\t   ");
		else
		printw("%c", c);
	}
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}

void returnToNormalMode() {
	echo();
	endwin();
}

void showResult(short result) {
	clear();
	if (result <= 7) {
		attron(COLOR_PAIR(1));
		move(1, 10);
		addstr("     ___   __   __   __    _   ___    _______   ______   ");
		move(2, 10);
		addstr("    |   | |  | |  | |  |  | | |   |  |       | |    _ |  ");
		move(3, 10);
		addstr("    |   | |  | |  | |   |_| | |   |  |   _   | |   | ||  ");
		move(4, 10);
		addstr("    |   | |  |_|  | |       | |   |  |  | |  | |   |_||_ ");
		move(5, 10);
		addstr(" ___|   | |       | |  _    | |   |  |  |_|  | |    __  |");
		move(6, 10);
		addstr("|       | |       | | | |   | |   |  |       | |   |  | |");
		move(7, 10);
		addstr("|_______| |_______| |_|  |__| |___|  |_______| |___|  |_|");
		attron(COLOR_PAIR(2));
		move(11, 29);
		printw("Твой результат - %d", result);
		move(14, 16);
		addstr("Ты очень хочешь программировать, но для этого");
		move(15, 16);
		addstr("нужно очень сильно стараться и много работать.");
		move(18, 16);
		addstr("Попрактикуйся ещё и попробуй снова!");
		border(0, 0, 0, 0, 0, 0, 0, 0);                                           
	} else
	if (result <= 14) {
		attron(COLOR_PAIR(1));
		move(1, 10);
		addstr(" __   __   ___    ______    ______    ___       _______ ");
		move(2, 10);
		addstr("|  |_|  | |   |  |      |  |      |  |   |     |       |");
		move(3, 10);
		addstr("|       | |   |  |  _    | |  _    | |   |     |    ___|");
		move(4, 10);
		addstr("|       | |   |  | | |   | | | |   | |   |     |   |___ ");
		move(5, 10);
		addstr("|       | |   |  | |_|   | | |_|   | |   |___  |    ___|");
		move(6, 10);
		addstr("| ||_|| | |   |  |       | |       | |       | |   |___ ");
		move(7, 10);
		addstr("|_|   |_| |___|  |______|  |______|  |_______| |_______|");
		attron(COLOR_PAIR(2));
		move(11, 29);
		printw("Твой результат - %d", result);
		move(14, 16);
		addstr("У тебя хорошо получается, но это ли");
		move(15, 16);
		addstr("предел твоих возможностей?.");
		move(18, 16);
		addstr("Попрактикуйся ещё и попробуй снова!");
		border(0, 0, 0, 0, 0, 0, 0, 0);       
	} else
	if (result <= 18) {
		attron(COLOR_PAIR(1));
		move(2, 10);
		addstr(" _______   _______   __    _   ___    _______   ______   ");
		move(3, 10);
		addstr("|       | |       | |  |  | | |   |  |       | |    _ |  ");
		move(4, 10);
		addstr("|  _____| |    ___| |   |_| | |   |  |   _   | |   | ||  ");
		move(5, 10);
		addstr("| |_____  |   |___  |       | |   |  |  | |  | |   |_||_ ");
		move(6, 10);
		addstr("|_____  | |    ___| |  _    | |   |  |  |_|  | |    __  |");
		move(7, 10);
		addstr(" _____| | |   |___  | | |   | |   |  |       | |   |  | |");
		move(8, 10);
		addstr("|_______| |_______| |_|  |__| |___|  |_______| |___|  |_|");
		attron(COLOR_PAIR(2));
		move(11, 29);
		printw("Твой результат - %d", result);
		move(14, 16);
		addstr("Ты уже многое умеешь, но в данной области");
		move(15, 16);
		addstr("необходимо постоянно развиваться. Ты можешь лучше!");
		move(18, 16);
		addstr("Попрактикуйся ещё и попробуй снова!");
		border(0, 0, 0, 0, 0, 0, 0, 0);       
	} else
	if (result <= 20) {
		attron(COLOR_PAIR(1));
		move(1, 3);
		addstr("_________ _______  _______  _______    _        _______  _______  ______  ");
		move(2, 3);
		addstr("\\__   __/(  ____ \\(  ___  )(       )  ( \\      (  ____ \\(  ___  )(  __  \\ ");
		move(3, 3);
		addstr("   ) (   | (    \\/| (   ) || () () |  | (      | (    \\/| (   ) || (  \\  )");
		move(4, 3);
		addstr("   | |   | (__    | (___) || || || |  | |      | (__    | (___) || |   ) |");
		move(5, 3);
		addstr("   | |   |  __)   |  ___  || |(_)| |  | |      |  __)   |  ___  || |   | |");
		move(6, 3);
		addstr("   | |   | (      | (   ) || |   | |  | |      | (      | (   ) || |   ) |");
		move(7, 3);
		addstr("   | |   | (____/\\| )   ( || )   ( |  | (____/\\| (____/\\| )   ( || (__/  )");
		move(8, 3);
		addstr("   )_(   (_______/|/     \\||/     \\|  (_______/(_______/|/     \\|(______/ ");		
		attron(COLOR_PAIR(2));
		move(11, 29);
		printw("Твой результат - %d", result);
		move(14, 16);
		addstr("Вау! Неужели программисты с такими навыками");
		move(15, 16);
		addstr("тратят своё свободное время на разные тесты?.");
		move(18, 16);
		addstr("В любом случае, вы - молодец!");
		border(0, 0, 0, 0, 0, 0, 0, 0);      
	}
	getch();
}
