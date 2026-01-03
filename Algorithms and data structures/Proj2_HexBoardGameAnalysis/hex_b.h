#pragma once
#include "LIST.h"
#define MAX_BOARD_SIZE 11

class HEX_B
{
	short blue_pawns, red_pawns, board_size,whoseturn, cords[2][2];
	char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE][7] = {};
	bool is_board_correct, is_board_possible, expandCond; 
	bool WinR, WinB, WinRin1, WinBin1, WinRin2, WinBin2;
	bool isEof=false;
	short query=-1;
	short ii, jj, kk; 
public:
	bool solve_hex();
	void prepare_next();
	void init_queries();
	bool input_board(char ctmp);
	int input_query();
	void input_buff();
	const bool getEof();
	void clear_tab(short which_tab);

	const void print4answers();
	void isGameOver();

	void get_neighbours(int current[2], int neighbours[][2], int* how_many_neighbours);

	void IS_GAME_OVER_Q();
	void IS_BOARD_POSSIBLE_Q();

	void loop_for_winchec();
	bool loop_for_winchec(char col);

	void CAN_NAIVE_Q();
	void CAN_NAIVE_Q_logic();
	bool CheckIfWin(int startHex[2], char colour);
	bool CheckIfWinIN1(int startHex[2], char colour);
	bool CheckIfWinIN2(int startHex[2], char colour);
	bool CheckIfWinIN2_win_in_1_case(int startHex[2], char colour);

	void clearcordsIN1();
	void clearcordsIN2();

	void CAN_PERF_Q();
	void CAN_PERF_Q_logic();
	bool CAN_PERF_Q_logic_S1(char* colour);
	bool CAN_PERF_Q_logic_F2(char* colour);
	bool CAN_PERF_Q_logic_S2_NONPRIO(char* colour);

	bool CheckIfWinIN1PERF(int startHex[2], char colour);
	bool CheckIfWinIN2PERF(int startHex[2], char colour);
	bool CheckIfWinIN2_win_in_1_casePERF(int hexToChange[2], char colour);
	bool CheckIfWinIN2PERF_NONPRIO(int startHex[2], char colour, char enemy_colour);
};

