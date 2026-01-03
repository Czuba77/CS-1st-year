#include "HEX_B.h"
#include <iostream>

#define PAWN 0
#define IS_VIS 1
#define CHECKED_N1 2
#define CHECKED_N2 3
#define CHECKED_P1 4
#define CHECKED_P2 5
#define CHECKED_P2_NONPRIO 6
#define CHECKED_VAL '='

#define oX 0
#define oY 1
#define BLUE 3
#define RED 2

#define BLOCK_IN1 0
#define BLOCK_IN2 1

#define BOARD_SIZE 1
#define PAWNS_NUMBER 2
#define IS_BOARD_CORRECT 3
#define IS_GAME_OVER 4
#define IS_BOARD_POSSIBLE 5
#define CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT 6 
#define CAN_RED_WIN_IN_N_MOVE_WITH_PERFECT_OPPONENT 7

void HEX_B::clear_tab(short which_tab) {
	for (int i = 0; i <= board_size; i++) {
		for (int j = 0; j <= board_size; j++) {
			board[i][j][which_tab] = 0;
		}
	}
}


void HEX_B::clearcordsIN1() {
		board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = ' ';
}

void HEX_B::clearcordsIN2() {
		board[cords[BLOCK_IN2][oX]][cords[BLOCK_IN2][oY]][PAWN] = ' ';
}

void HEX_B::init_queries() {
	WinR = false;
	WinB = false;
	expandCond = true;
	blue_pawns = 0;
	red_pawns = 0;
	board_size = -1;
	ii = 1, jj = -1, kk = 0;
	char ctmp = getchar();
	is_board_correct = input_board(ctmp);
	is_board_possible = true;
}

bool HEX_B::input_board(char ctmp) {
	while ((ctmp < 'A' || ctmp>'_') && (kk == 0 || kk <= board_size)) {
		switch (ctmp) {
		case 'b':
			blue_pawns++;
			board[ii][jj][PAWN] = 'b';
			break;
		case 'r':
			red_pawns++;
			board[ii][jj][PAWN] = 'r';
			break;
		case '<':
			ii--;
			jj++;
			board[ii][jj][PAWN] = ' ';
			break;
		case '\n':
			if (expandCond) {
				board_size++;
				jj = -1;
				ii = board_size + 1;
				ctmp = getchar();
				if (ctmp == '<') {
					expandCond = false;
					ii--;
					jj++;
					board[ii][jj][PAWN] = ' ';
					break;
				}
				else
					input_board(ctmp);
			}
			else {
				kk++;
				jj = kk - 1;
				ii = board_size + 1;
			}
			break;
		}
		ctmp = getchar();
	}
	if (blue_pawns > red_pawns || blue_pawns < red_pawns - 1)
		return false;
	else
		return true;
}

int HEX_B::input_query() {
	char ctmp;
	while (true) {
		ctmp = getchar();
		switch (ctmp)
		{
		case 'O':
			return BOARD_SIZE;
		case 'A':
			return PAWNS_NUMBER;
		case 'S':
			for (int i = 0; i < 7; i++)
				getchar();
			ctmp = getchar();
			if (ctmp == 'C')
				return IS_BOARD_CORRECT;
			else if (ctmp == 'V')
				return IS_GAME_OVER;
			else
				return IS_BOARD_POSSIBLE;
		case 'C':
			for (int i = 0; i < 27; i++)
				ctmp = getchar();

			if (ctmp == 'N')
				return CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT;
			else
				return CAN_RED_WIN_IN_N_MOVE_WITH_PERFECT_OPPONENT;
		}
	}
}

void HEX_B::input_buff() {
	char ctmp;
	while (true) {
		if (!(std::cin >> ctmp)) {
			isEof = true;
			break;
		}
		if (ctmp == '-') {
			break;
		}
	}
}




bool HEX_B::solve_hex() {
	init_queries();
	query = input_query();
	switch (query)
	{
	case BOARD_SIZE:
		printf("%d\n\n", board_size + 1);
		break;
	case PAWNS_NUMBER:
		printf("%d\n\n", blue_pawns + red_pawns);
		break;
	case IS_BOARD_CORRECT:
		if (is_board_correct)
			printf("YES\n\n");
		else
			printf("NO\n\n");
		break;
	case IS_GAME_OVER:
		IS_GAME_OVER_Q();
		break;
	case IS_BOARD_POSSIBLE:
		IS_BOARD_POSSIBLE_Q();
		break;
	case CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT:
		CAN_NAIVE_Q();
		break;
	case CAN_RED_WIN_IN_N_MOVE_WITH_PERFECT_OPPONENT:
		CAN_PERF_Q();
		break;
	}
	return true;
}

void HEX_B::prepare_next() {
	input_buff();
	for (int i = 0; i < 7; i++)
		clear_tab(i);
}


const bool HEX_B::getEof() {
	return this->isEof;
};

 void HEX_B::IS_GAME_OVER_Q() {
	 if (!board_size) {
		 if (board[0][0][PAWN] == 'b')
			 printf("NO\n\n");
		 else if(board[0][0][PAWN] == 'r')
			 printf("YES RED\n\n");
		 else
			 printf("NO\n\n");
	 }
	 else if (is_board_correct) {
		 loop_for_winchec();
		 if (WinR)
			 printf("YES RED\n\n");
		 else if (WinB)
			 printf("YES BLUE\n\n");
		 else
			 printf("NO\n\n");
	 }
	 else
		 printf("NO\n\n");
 }

 void HEX_B::IS_BOARD_POSSIBLE_Q() {
	 if (!board_size) {
		 if (board[0][0][PAWN] == 'b')
			 printf("NO\n\n");
		 else if (board[0][0][PAWN] == 'r')
			 printf("YES\n\n");
		 else
			 printf("YES\n\n");
	 }
	 else {
		 bool cond=false;
		 if (is_board_correct) {
			 loop_for_winchec();		
			 if ((WinB == true && red_pawns > blue_pawns) || (WinR == true && red_pawns == blue_pawns)){
				 is_board_possible = false;
			 }
			 else {
				 clear_tab(IS_VIS);
				 if (WinB) {
					 for (int i = 0; i <= board_size && !cond; i++) {
						 for (int j = 0; j <= board_size; j++) {
							 if (board[i][j][PAWN] == 'b') {
								 board[i][j][PAWN] = ' ';
								 WinB = false;
								 loop_for_winchec();
								 if (!WinB) {
									 is_board_possible = true;
									 cond = true;
									 break;
								 }
								 board[i][j][PAWN] = 'b';
								 clear_tab(IS_VIS);
							 }
						 }
					 }
					 if(WinB)
						is_board_possible = false;
				 }
				 else if (WinR) {
					 for (int i = 0; i <= board_size && !cond; i++) {
						 for (int j = 0; j <= board_size; j++) {
							 if (board[i][j][PAWN] == 'r') {
								 board[i][j][PAWN] = ' ';
								 WinR = false;
								 loop_for_winchec();
								 if (!WinR) {
									 is_board_possible = true;
									 cond = true;
									 break;
								 }
								 board[i][j][PAWN] = 'r';
								 clear_tab(IS_VIS);
							 }
						 }
					 }
					 if (WinR)
						is_board_possible = false;
				 }
			 }
		 }
		 else
			 is_board_possible = false;

		 if (is_board_possible)
			 printf("YES\n\n");
		 else
			 printf("NO\n\n");
	 }
 }

const void HEX_B::print4answers() {
	if(WinRin1)
		printf("YES\n");
	else
		printf("NO\n");

	if (WinBin1)
		printf("YES\n");
	else
		printf("NO\n");

	if (WinRin2)
		printf("YES\n");
	else
		printf("NO\n");

	if (WinBin2)
		printf("YES\n\n");
	else
		printf("NO\n\n");
}

void HEX_B::isGameOver() {
	int hex[2] = {};
	for (int i = 0; i <= board_size; i++) {
		hex[0] = i;
		hex[1] = 0;
		WinR = CheckIfWin(hex, 'r');
		if (WinR)
			break;
		hex[0] = 0;
		hex[1] = i;
		WinB = CheckIfWin(hex, 'b');
		if (WinB)
			break;
	}
	clear_tab(IS_VIS);
}

void HEX_B::CAN_NAIVE_Q() {
	CAN_NAIVE_Q_logic();
	print4answers();
}

void HEX_B::CAN_NAIVE_Q_logic() {
	isGameOver();
	WinRin1 = false;
	WinBin1 = false;
	WinRin2 = false;
	WinBin2 = false;
	int board_area = (board_size + 1) * (board_size + 1);
	if (!WinB && !WinR && is_board_correct && blue_pawns + red_pawns < board_area) {
		int hex[2] = {};
		if (red_pawns == blue_pawns + 1)
			whoseturn = BLUE;
		else
			whoseturn = RED;
		if (!board_size)
			WinRin1 = true;
		else if (whoseturn == BLUE) {
			for (int i = 0; i <= board_size; i++) {
				hex[0] = 0;
				hex[1] = i;
				WinBin1 = CheckIfWinIN1(hex, 'b');
				if (WinBin1)
					break;
			}
			clear_tab(CHECKED_N1);
			if (blue_pawns + red_pawns + 1 < board_area) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = i;
					hex[1] = 0;
					WinRin1 = CheckIfWinIN1(hex, 'r');
					if (WinRin1)
						break;
				}
				clear_tab(CHECKED_N1);
			}
			if (blue_pawns + red_pawns + 2 < board_area) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = 0;
					hex[1] = i;
					WinBin2 = CheckIfWinIN2(hex, 'b');
					if (WinBin2)
						break;
				}
				clear_tab(CHECKED_N2);
			}
			if (blue_pawns + red_pawns + 3 < board_area) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = i;
					hex[1] = 0;
					WinRin2 = CheckIfWinIN2(hex, 'r');
					if (WinRin2)
						break;
				}
			}
		}
		else {
			for (int i = 0; i <= board_size; i++) {
				hex[0] = i;
				hex[1] = 0;
				WinRin1 = CheckIfWinIN1(hex, 'r');
				if (WinRin1)
					break;
			}
			clear_tab(CHECKED_N1);
			if (blue_pawns + red_pawns + 1 < board_area) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = 0;
					hex[1] = i;
					WinBin1 = CheckIfWinIN1(hex, 'b');
					if (WinBin1)
						break;
				}
				clear_tab(CHECKED_N1);
			}
			if (blue_pawns + red_pawns + 2 < board_area) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = i;
					hex[1] = 0;
					WinRin2 = CheckIfWinIN2(hex, 'r');
					if (WinRin2)
						break;
				}
				clear_tab(CHECKED_N2);
			}
			if (blue_pawns + red_pawns + 3 < board_area) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = 0;
					hex[1] = i;
					WinBin2 = CheckIfWinIN2(hex, 'b');
					if (WinBin2)
						break;
				}
				clear_tab(CHECKED_N2);
			}
		}
	}
}


void HEX_B::get_neighbours(int current[2],int neighbours[][2], int* how_many_neighbours) {
	*how_many_neighbours = 0;
	if (current[oX] - 1 >= 0) {
		neighbours[*how_many_neighbours][oX] = current[oX] - 1;
		neighbours[(*how_many_neighbours)++][oY] = current[oY];
	}

	if (current[oY] - 1 >= 0) {
		neighbours[*how_many_neighbours][oX] = current[oX];
		neighbours[(*how_many_neighbours)++][oY] = current[oY] - 1;
	}

	if (current[oY] - 1 >= 0 && current[oX] - 1 >= 0) {
		neighbours[*how_many_neighbours][oX] = current[oX] - 1;
		neighbours[(*how_many_neighbours)++][oY] = current[oY] - 1;
	}

	if (current[oX] + 1 <= board_size) {
		neighbours[*how_many_neighbours][oX] = current[oX] + 1;
		neighbours[(*how_many_neighbours)++][oY] = current[oY];
	}

	if (current[oY] + 1 <= board_size) {
		neighbours[*how_many_neighbours][oX] = current[oX];
		neighbours[(*how_many_neighbours)++][oY] = current[oY] + 1;
	}

	if (current[oX] + 1 <= board_size && current[oY] + 1 <= board_size) {
		neighbours[*how_many_neighbours][oX] = current[oX] + 1;
		neighbours[(*how_many_neighbours)++][oY] = current[oY] + 1;
	}
}


void HEX_B::loop_for_winchec() {
	int hex[2] = {};
	for (int i = 0; i <= board_size; i++) {
		hex[oX] = i;
		hex[oY] = 0;
		WinR = CheckIfWin(hex, 'r');
		if (WinR)
			break;
		hex[oX] = 0;
		hex[oY] = i;
		WinB = CheckIfWin(hex, 'b');
		if (WinB)
			break;
	}
}



bool HEX_B::loop_for_winchec(char col) {
	int hex[2] = {};
	bool win;
	if (col == 'r') {
		for (int i = 0; i <= board_size; i++) {
			hex[oX] = i;
			hex[oY] = 0;
			win = CheckIfWin(hex, col);
			if (win)
				return true;
		}
	}
	else {
		for (int i = 0; i <= board_size; i++) {
			hex[oX] = 0;
			hex[oY] = i;
			win = CheckIfWin(hex, col);
			if (win)
				return true;
		}
	}
	return false;
}



bool HEX_B::CheckIfWinIN2_win_in_1_case(int startHex[2], char colour) {
	clear_tab(IS_VIS);
	board[startHex[oX]][startHex[oY]][PAWN] = ' ';
	clear_tab(CHECKED_N1);
	for (int i = 0; i <= board_size; i++) {
		for (int j = 0; j <= board_size; j++) {
			if (board[i][j][PAWN] == ' ') {
				board[i][j][PAWN] = colour;
				if (!loop_for_winchec(colour)) {
					board[i][j][PAWN] = ' ';
					clear_tab(IS_VIS);
					return true;
				}
				board[i][j][PAWN] = ' ';
				clear_tab(IS_VIS);
			}
		}
	}
	return false;
}

bool HEX_B::CheckIfWinIN2(int startHex[2], char colour) {
	if (board[startHex[oX]][startHex[oY]][PAWN] == colour && board[startHex[oX]][startHex[oY]][CHECKED_N2] != CHECKED_VAL) {
		LIST stack;
		int how_many_neighbours;
		int current[2] = {};//XY
		int neighbours[6][2] = {};//MAX 6 NEIGBOURS
		stack.push(startHex);
		while (stack.getFirst() != nullptr) {
			stack.pop(current);
			get_neighbours(current, neighbours, &how_many_neighbours);
			for (int i = 0; i < how_many_neighbours; i++) {
				if (board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_N2] != CHECKED_VAL) {
					if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == colour) {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_N2] = CHECKED_VAL;
						stack.push(neighbours[i]);
					}
					else if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == ' ') {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_N2] = CHECKED_VAL;
						board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = colour;
						if (CheckIfWinIN1(startHex, colour) && !loop_for_winchec(colour)) {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(CHECKED_N1);
							return true;
						}
						clear_tab(IS_VIS);
						if (loop_for_winchec(colour) && CheckIfWinIN2_win_in_1_case(neighbours[i], colour)) {
							return true;
						}
						else {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(CHECKED_N1);
						}
					}
				}
			}
		}
	}
	else if (board[startHex[oX]][startHex[oY]][PAWN] == ' ' && board[startHex[oX]][startHex[oY]][CHECKED_N2] != CHECKED_VAL) {
		board[startHex[oX]][startHex[oY]][CHECKED_N2] = CHECKED_VAL;
		board[startHex[oX]][startHex[oY]][PAWN] = colour;
		if (CheckIfWinIN1(startHex, colour) && !loop_for_winchec(colour)) {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(CHECKED_N1);
			return true;
		}
		clear_tab(IS_VIS);
		if (loop_for_winchec(colour) && CheckIfWinIN2_win_in_1_case(startHex, colour)) {
			return true;
		}
		else {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(CHECKED_N1);
		}
	}
	return false;
}

bool HEX_B::CheckIfWinIN1(int startHex[2], char colour) {
	clear_tab(IS_VIS);
	if (board[startHex[oX]][startHex[oY]][PAWN] == colour && board[startHex[oX]][startHex[oY]][CHECKED_N1] != CHECKED_VAL) {
		LIST stack;
		int how_many_neighbours;
		int current[2] = {};//XY
		int hex[2] = {};
		int neighbours[6][2] = {};//MAX 6 NEIGBOURS
		stack.push(startHex);
		while (stack.getFirst() != nullptr) {
			stack.pop(current);
			get_neighbours(current, neighbours, &how_many_neighbours);
			for (int i = 0; i < how_many_neighbours; i++) {
				if (board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_N1] != CHECKED_VAL) {
					if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == colour) {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_N1] = CHECKED_VAL;
						stack.push(neighbours[i]);
					}
					else if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == ' ') {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_N1] = CHECKED_VAL;
						board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = colour;
						if (loop_for_winchec(colour)) {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(IS_VIS);
							return true;
						}
						else {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(IS_VIS);
						}
					}
				}
			}
		}
	}
	else if (board[startHex[oX]][startHex[oY]][PAWN] == ' ' && board[startHex[oX]][startHex[oY]][CHECKED_N1] != CHECKED_VAL) {
		board[startHex[oX]][startHex[oY]][CHECKED_N1] = CHECKED_VAL;
		board[startHex[oX]][startHex[oY]][PAWN] = colour;
		if (loop_for_winchec(colour)) {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(IS_VIS);
			return true;
		}
		else {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(IS_VIS);
		}
	}
	return false;
}

bool HEX_B::CheckIfWin(int startHex[2], char colour) {
	if (board[startHex[oX]][startHex[oY]][PAWN] == colour && board[startHex[oX]][startHex[oY]][IS_VIS] != CHECKED_VAL) {
		board[startHex[oX]][startHex[oY]][IS_VIS] = CHECKED_VAL;
		LIST stack;
		int how_many_neighbours;
		int current[2] = {};//XY
		int hex[2] = {};
		int neighbours[6][2] = {};//MAX 6 NEIGBOURS
		stack.push(startHex);
		while (stack.getFirst() != nullptr) {
			stack.pop(current);
			get_neighbours(current, neighbours, &how_many_neighbours);
			for (int i = 0; i < how_many_neighbours; i++) {
				if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == colour && board[neighbours[i][oX]][neighbours[i][oY]][IS_VIS] != CHECKED_VAL) {
					if ((colour == 'b' && neighbours[i][oX] == board_size) || (colour == 'r' && neighbours[i][oY] == board_size)) {
						return true;
					}
					board[neighbours[i][oX]][neighbours[i][oY]][IS_VIS] = CHECKED_VAL;
					stack.push(neighbours[i]);
				}
			}
		}
	}
	return false;
}



void HEX_B::CAN_PERF_Q() {
	CAN_NAIVE_Q_logic();
	if (WinRin1 || WinBin1 || WinRin2 || WinBin2)
		CAN_PERF_Q_logic();
	print4answers();
}

bool HEX_B::CAN_PERF_Q_logic_S1(char* colour) {
	int board_area = (board_size + 1) * (board_size + 1);
	bool win = false;
	int hex[2] = {};
	if (*colour == 'b') {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = 0;
			hex[1] = i;
			if (CheckIfWinIN1PERF(hex, *colour)) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = 0;
					hex[1] = i;
					if (CheckIfWinIN1(hex, 'b')) {
						clearcordsIN1();
						clear_tab(CHECKED_N1);
						clear_tab(CHECKED_P1);
						return true;
					}
				}
				clearcordsIN1();
			}
		}
	}
	else {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = i;
			hex[1] = 0;
			if (CheckIfWinIN1PERF(hex, *colour)) {
				for (int i = 0; i <= board_size; i++) {
					hex[0] = i;
					hex[1] = 0;
					if (CheckIfWinIN1(hex, 'r')) {
						clearcordsIN1();
						clear_tab(CHECKED_N1);
						clear_tab(CHECKED_P1);
						return true;
					}
				}
				clearcordsIN1();
			}
		}
	}
	clear_tab(CHECKED_N1);
	clear_tab(CHECKED_P1);
	return win;
}

bool HEX_B::CAN_PERF_Q_logic_F2(char* colour) {
	bool win = false;
	int hex[2] = {};
	if (*colour == 'b') {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = 0;
			hex[1] = i;
			if (CheckIfWinIN2PERF(hex, *colour)) {
				win = true;
			}
		}
		for (int i = 0; i <= board_size; i++) {
			hex[0] = board_size;
			hex[1] = i;
			if (CheckIfWinIN2PERF(hex, *colour)) {
				win = true;
			}
		}
	}
	else {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = i;
			hex[1] = 0;
			if (CheckIfWinIN2PERF(hex, *colour)) {
				win = true;
			}
		}
		for (int i = 0; i <= board_size; i++) {
			hex[0] = i;
			hex[1] = board_size;
			if (CheckIfWinIN2PERF(hex, *colour)) {
				win = true;
			}
		}
	}
	clear_tab(CHECKED_P2);
	return win;
}

bool HEX_B::CAN_PERF_Q_logic_S2_NONPRIO(char* colour) {
	bool win = true;
	int hex[2] = {};
	if (*colour == 'b') {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = 0;
			hex[1] = i;
			if (!CheckIfWinIN2PERF_NONPRIO(hex, *colour, 'r')) {
				win = false;
				break;
			}
		}
		for (int i = 0; i <= board_size; i++) {
			hex[0] = board_size;
			hex[1] = i;
			if (!CheckIfWinIN2PERF_NONPRIO(hex, *colour, 'r')) {
				win = false;
				break;
			}
		}
	}
	else {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = i;
			hex[1] = 0;
			if (!CheckIfWinIN2PERF_NONPRIO(hex, *colour, 'b')) {
				win = false;
				break;
			}
		}
		for (int i = 0; i <= board_size; i++) {
			hex[0] = i;
			hex[1] = board_size;
			if (!CheckIfWinIN2PERF_NONPRIO(hex, *colour, 'b')) {
				win = false;
				break;
			}
		}
	}
	clear_tab(CHECKED_P2_NONPRIO);
	return win;
}


void HEX_B::CAN_PERF_Q_logic() {
	bool* WinFin1p = &WinBin1, * WinSin1p = &WinRin1, * WinFin2p = &WinBin2, * WinSin2p = &WinRin2;
	short first_colour = whoseturn, second_colour = RED;
	int hex[2] = {};
	char fc_char = 'b', sc_char = 'r';

	if (first_colour == RED) {
		second_colour = BLUE;
		sc_char = 'b';
		fc_char = 'r';
		WinFin1p = &WinRin1;
		WinSin1p = &WinBin1;
		WinFin2p = &WinRin2;
		WinSin2p = &WinBin2;
	}

	if (*WinSin1p) {
		if (*WinFin1p)
			*WinSin1p = false;
		else {
			*WinSin1p = CAN_PERF_Q_logic_S1(&sc_char);
		}
	}

	if (*WinFin2p) {
		if (*WinSin1p) {
			*WinFin2p = false;
		}
		else {
			*WinFin2p = CAN_PERF_Q_logic_F2(&fc_char);
		}
	}

	if (*WinSin2p) {
		if (*WinFin1p) {
			*WinSin2p = false;
		}
		else {
			*WinSin2p = CAN_PERF_Q_logic_S2_NONPRIO(&sc_char);
		}
	}
}


bool HEX_B::CheckIfWinIN2PERF_NONPRIO(int startHex[2], char colour, char enemy_colour) {
	if (board[startHex[oX]][startHex[oY]][PAWN] == colour && board[startHex[oX]][startHex[oY]][CHECKED_P2_NONPRIO] != CHECKED_VAL) {
		LIST stack;
		int how_many_neighbours;
		int current[2] = {};//XY
		int neighbours[6][2] = {};//MAX 6 NEIGBOURS
		stack.push(startHex);
		while (stack.getFirst() != nullptr) {
			stack.pop(current);
			get_neighbours(current, neighbours, &how_many_neighbours);
			for (int i = 0; i < how_many_neighbours; i++) {
				if (board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P2_NONPRIO] != CHECKED_VAL) {
					if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == colour) {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P2_NONPRIO] = CHECKED_VAL;
						stack.push(neighbours[i]);
					}
					else if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == ' ') {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P2_NONPRIO] = CHECKED_VAL;
						board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = enemy_colour;
						if (!CAN_PERF_Q_logic_F2(&colour)) {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(CHECKED_P2);
							return false;
						}
						else {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
						}
					}
				}
			}
		}
		clear_tab(CHECKED_P2);
		return true;
	}
	else if (board[startHex[oX]][startHex[oY]][PAWN] == ' ' && board[startHex[oX]][startHex[oY]][CHECKED_P2_NONPRIO] != CHECKED_VAL) {
		board[startHex[oX]][startHex[oY]][CHECKED_P2_NONPRIO] = CHECKED_VAL;
		board[startHex[oX]][startHex[oY]][PAWN] = enemy_colour;
		if (!CAN_PERF_Q_logic_F2(&colour)) {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(CHECKED_P2);
			return false;
		}
		board[startHex[oX]][startHex[oY]][PAWN] = ' ';
		clear_tab(CHECKED_P2);
		return true;
	}
	return true;
}

bool HEX_B::CheckIfWinIN2_win_in_1_casePERF(int hexToChange[2], char colour) {
	int hex[2] = {};
	cords[BLOCK_IN1][oX] = hexToChange[oX];
	cords[BLOCK_IN1][oY] = hexToChange[oY];
	if (colour == 'b')
		board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = 'r';
	else
		board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = 'b';
	if (colour == 'b') {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = 0;
			hex[1] = i;
			if (CheckIfWinIN2(hex, 'b')) {
				clear_tab(CHECKED_N2);
				clearcordsIN1();
				return true;
			}
		}
	}
	else {
		for (int i = 0; i <= board_size; i++) {
			hex[0] = i;
			hex[1] = 0;
			if (CheckIfWinIN2(hex, 'r')) {
				clear_tab(CHECKED_N2);
				clearcordsIN1();
				return true;
			}
		}
	}
	clear_tab(CHECKED_N2);
	clearcordsIN1();
	return false;
}

bool HEX_B::CheckIfWinIN2PERF(int startHex[2], char colour) {
	bool winCheckIF;
	if (board[startHex[oX]][startHex[oY]][PAWN] == colour && board[startHex[oX]][startHex[oY]][CHECKED_P2] != CHECKED_VAL) {
		LIST stack;
		int how_many_neighbours;
		int current[2] = {};//XY
		int neighbours[6][2] = {};//MAX 6 NEIGBOURS
		stack.push(startHex);
		while (stack.getFirst() != nullptr) {
			stack.pop(current);
			get_neighbours(current, neighbours, &how_many_neighbours);
			for (int i = 0; i < how_many_neighbours; i++) {
				if (board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P2] != CHECKED_VAL) {
					if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == colour) {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P2] = CHECKED_VAL;
						stack.push(neighbours[i]);
					}
					else if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == ' ') {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P2] = CHECKED_VAL;
						board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = colour;
						clear_tab(IS_VIS);
						winCheckIF = loop_for_winchec(colour);
						clear_tab(IS_VIS);
						if (CAN_PERF_Q_logic_S1(&colour) && !winCheckIF) {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(CHECKED_P1);
							return true;
						}
						if (winCheckIF && CheckIfWinIN2_win_in_1_casePERF(neighbours[i], colour)) {
							clear_tab(CHECKED_P1);
							return true;
						}
						else {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(CHECKED_P1);
						}
					}
				}
			}
		}
	}
	else if (board[startHex[oX]][startHex[oY]][PAWN] == ' ' && board[startHex[oX]][startHex[oY]][CHECKED_P2] != CHECKED_VAL) {
		board[startHex[oX]][startHex[oY]][CHECKED_P2] = CHECKED_VAL;
		board[startHex[oX]][startHex[oY]][PAWN] = colour;
		clear_tab(IS_VIS);
		winCheckIF = loop_for_winchec(colour);
		clear_tab(IS_VIS);
		if (CAN_PERF_Q_logic_S1(&colour) && !winCheckIF) {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(CHECKED_P1);
			return true;
		}
		if (winCheckIF && CheckIfWinIN2_win_in_1_casePERF(startHex, colour)) {
			clear_tab(CHECKED_P1);
			return true;
		}
		else {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(CHECKED_P1);
		}
	}
	return false;
}

bool HEX_B::CheckIfWinIN1PERF(int startHex[2], char colour) {
	clear_tab(IS_VIS);
	if (board[startHex[oX]][startHex[oY]][PAWN] == colour && board[startHex[oX]][startHex[oY]][CHECKED_P1] != CHECKED_VAL) {
		LIST stack;
		int how_many_neighbours;
		int current[2] = {};//XY
		int hex[2] = {};
		int neighbours[6][2] = {};//MAX 6 NEIGBOURS
		stack.push(startHex);
		while (stack.getFirst() != nullptr) {
			stack.pop(current);
			get_neighbours(current, neighbours, &how_many_neighbours);
			for (int i = 0; i < how_many_neighbours; i++) {
				if (board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P1] != CHECKED_VAL) {
					if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == colour) {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P1] = CHECKED_VAL;
						stack.push(neighbours[i]);
					}
					else if (board[neighbours[i][oX]][neighbours[i][oY]][PAWN] == ' ') {
						board[neighbours[i][oX]][neighbours[i][oY]][CHECKED_P1] = CHECKED_VAL;
						board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = colour;
						if (loop_for_winchec(colour)) {
							cords[BLOCK_IN1][oX] = neighbours[i][oX];
							cords[BLOCK_IN1][oY] = neighbours[i][oY];
							if (colour == 'b')
								board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = 'r';
							else
								board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = 'b';
							clear_tab(IS_VIS);
							return true;
						}
						else {
							board[neighbours[i][oX]][neighbours[i][oY]][PAWN] = ' ';
							clear_tab(IS_VIS);
						}
					}
				}
			}
		}
	}
	else if (board[startHex[oX]][startHex[oY]][PAWN] == ' ' && board[startHex[oX]][startHex[oY]][CHECKED_P1] != CHECKED_VAL) {
		board[startHex[oX]][startHex[oY]][CHECKED_P1] = CHECKED_VAL;
		board[startHex[oX]][startHex[oY]][PAWN] = colour;
		if (loop_for_winchec(colour)) {
			cords[BLOCK_IN1][oX] = startHex[oX];
			cords[BLOCK_IN1][oY] = startHex[oY];
			if (colour == 'b')
				board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = 'r';
			else
				board[cords[BLOCK_IN1][oX]][cords[BLOCK_IN1][oY]][PAWN] = 'b';
			clear_tab(IS_VIS);
			return true;
		}
		else {
			board[startHex[oX]][startHex[oY]][PAWN] = ' ';
			clear_tab(IS_VIS);
		}
	}
	return false;
}
