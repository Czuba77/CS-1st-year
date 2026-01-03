#pragma once
#include "LIST.h"
#include "VERTICES.h"
#include "NODE.h"

struct CIAG_STOPNIOWY {
	int stopien;
	VERTICES* wsk;
};

class GRAPH
{
	long long number_of_edges;
	int number_of_ver;
	int number_of_skladowe_spojnosci;
	VERTICES* vertices;
	LIST* colours;
	CIAG_STOPNIOWY* ciag_stop;

public:
	GRAPH(int n_of_ver);
	~GRAPH();
	void init_graph();
	void print_ciag_stopniowany();
	void count_skladowe_spojnosci();
	void Kolorowanie_wierzcholkow_alg_zachlanny();
	void clear_colours();
	void Kolorowanie_wierzcholkow_alg_LF();
	void dwudzielnosc_grafu();
	void print_dopelnienie_grafu();
	void SSdfs(VERTICES* startVer);
	bool Dbfs(VERTICES* startVer);
	void colouring(VERTICES* startVer);

	int comparison(CIAG_STOPNIOWY* s_one, CIAG_STOPNIOWY* s_two);
	int part(CIAG_STOPNIOWY* tab, int st, int en);
	void sort_q(CIAG_STOPNIOWY* tab, int st, int en);
};

