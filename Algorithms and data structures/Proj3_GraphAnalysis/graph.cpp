#define _CRT_SECURE_NO_WARNINGS
#include "GRAPH.h"
#include <stdio.h>
#include <type_traits>
#define first 1
#define second 2
#define equal 3


GRAPH::GRAPH(int n_of_ver) {
    this->number_of_skladowe_spojnosci = 0;
    this->number_of_edges = 0;
	this->number_of_ver = n_of_ver;
	this->vertices = new VERTICES[n_of_ver];
	this->ciag_stop = new CIAG_STOPNIOWY[n_of_ver];
    this->colours = nullptr;
}

GRAPH::~GRAPH() {
    delete[] (ciag_stop);
    delete (colours);
    delete[] (vertices);
}

void GRAPH::init_graph() {
	int tmp;
	for (int i = 0; i < number_of_ver;i++) {
		scanf("%d", &tmp);
		ciag_stop[i].stopien = tmp;
        ciag_stop[i].wsk = &vertices[i];
		vertices[i].setNeigh(tmp);
        vertices[i].setIndex(i);

		for (int j = 0; j < vertices[i].getNumOfNeigh(); j++) {
            number_of_edges++;
			scanf("%d", &tmp);
            tmp--;
			vertices[i].push(tmp);
		}
	}
    sort_q(ciag_stop, 0, number_of_ver - 1);
}

void  GRAPH::print_ciag_stopniowany() {
    for (int i = 0; i < number_of_ver; i++) {
        printf("%d ", ciag_stop[i].stopien);
    }
    printf("\n");
}

void  GRAPH::print_dopelnienie_grafu() {
    long long tmp = ((long long)number_of_ver * ((long long)number_of_ver - 1)) / 2 ;
    tmp -= number_of_edges/2;
    printf("%lld\n",tmp);
}

void GRAPH::count_skladowe_spojnosci() {
    for (int i = 0; i < number_of_ver; i++) {
        SSdfs(&vertices[i]);
    }
    printf("%d\n", number_of_skladowe_spojnosci);
}

void GRAPH::dwudzielnosc_grafu() {
    bool isDwudzielny=true;
    for (int i = 0; isDwudzielny && i < number_of_ver; i++) {
        isDwudzielny= Dbfs(&vertices[i]);
    }
    if (isDwudzielny)
        printf("T\n");
    else
        printf("F\n");
}



void GRAPH::SSdfs(VERTICES* startVer) {
    if (!startVer->getIsChecked(SS)) {
        number_of_skladowe_spojnosci++;
        startVer->setIsChecked(true, SS);
        LIST stack;
        int how_many_neighbours;
        int current;
        int neighbour;
        VERTICES* vertex;
        stack.push(startVer->getIndex());
        while (stack.getFirst() != nullptr) {
            current=stack.pop();
            vertex = &vertices[current];
            vertex->resetIteration();
            how_many_neighbours = vertex->getNumOfNeigh();
            for (int i = 0; i < how_many_neighbours; i++) {
                neighbour=vertex->getItVer()->getIndex();
                if (!vertices[neighbour].getIsChecked(SS)) {
                    vertices[neighbour].setIsChecked(true, SS);
                    stack.push(neighbour);
                }
                vertex->iterate();
            }
            vertex->resetIteration();
        }
    }
}

bool GRAPH::Dbfs(VERTICES* startVer) {
    if (!startVer->getIsChecked(DWUDZIELNOSC)) {
        startVer->setIsChecked(true, DWUDZIELNOSC);
        startVer->setIsChecked(LEWA, STRONA);
        bool Opposite_side;
        LIST que;
        int how_many_neighbours;
        int current;
        int neighbour;
        VERTICES* vertex;
        que.put(startVer->getIndex());
        while (que.getFirst() != nullptr) {
            current = que.get();
            vertex = &vertices[current];
            Opposite_side = !(vertex->getIsChecked(STRONA));
            vertex->resetIteration();
            how_many_neighbours = vertex->getNumOfNeigh();
            for (int i = 0; i < how_many_neighbours; i++) {
                neighbour = vertex->getItVer()->getIndex();
                if (!vertices[neighbour].getIsChecked(DWUDZIELNOSC)) {
                    vertices[neighbour].setIsChecked(true, DWUDZIELNOSC);
                    vertices[neighbour].setIsChecked(Opposite_side, STRONA);
                    que.put(neighbour);
                }
                else if (vertices[neighbour].getIsChecked(STRONA)!=Opposite_side) {
                    return false;
                }
                vertex->iterate();
            }
            vertex->resetIteration();
        }
    }
    return true;
}

void GRAPH::Kolorowanie_wierzcholkow_alg_LF() {
    colours = new LIST();
    colours->setIndex(1);
    colours->push(1);
    for (int i = 0; i < number_of_ver; i++) {
        colouring(ciag_stop[i].wsk);
    }
    for (int i = 0; i < number_of_ver; i++) {
        printf("%d ", vertices[i].getColour());
    }
    printf("\n");
}

void GRAPH::Kolorowanie_wierzcholkow_alg_zachlanny() {
    colours = new LIST();
    colours->setIndex(1);
    colours->push(1);
    for (int i = 0; i < number_of_ver; i++) {
        colouring(&vertices[i]);
    }
    for (int i = 0; i < number_of_ver; i++) {
        printf("%d ", vertices[i].getColour());
    }
    printf("\n");
}

void GRAPH::clear_colours() {
    for (int i = 0; i < number_of_ver; i++) {
        vertices[i].setColour(0);
    }
    delete colours;
    colours=nullptr;
}

void GRAPH::colouring(VERTICES* startVer) {
        int how_many_neighbours;
        int neighbour;
        startVer->resetIteration();
        colours->resetIteration();
        how_many_neighbours = startVer->getNumOfNeigh();
        for (int i = 0; i < how_many_neighbours; i++) {
            neighbour = startVer->getItVer()->getIndex();
            if (vertices[neighbour].getColour() == colours->getItVer()->getIndex()) {
                colours->iterate();
                if (colours->getItVer() == nullptr) {
                    colours->incrementIndex();
                    colours->put(colours->getIndex());
                    colours->setIteratorToLast();
                }
                i = -1;
                startVer->resetIteration();
            }
            else 
                startVer->iterate();
        }
        startVer->resetIteration();
        startVer->setColour(colours->getItVer()->getIndex());
}


int GRAPH::comparison(CIAG_STOPNIOWY* s_one, CIAG_STOPNIOWY* s_two) {
    if (s_one->stopien > s_two->stopien)
        return second;
    else if (s_one->stopien < s_two->stopien)
        return first;
    else
        if (s_one->wsk->getIndex() > s_two->wsk->getIndex())
            return first;
        else if (s_one->wsk->getIndex() < s_two->wsk->getIndex())
            return second;
        else
            return equal;
}

int GRAPH::part(CIAG_STOPNIOWY tab[], int st, int en) {
    CIAG_STOPNIOWY pivot = tab[(st + en) / 2];
    int i = st;
    int j = en;
    CIAG_STOPNIOWY tmp;
    while (i <= j) {
        while (comparison(&tab[i], &pivot) == second) {
            i++;
        }
        while (comparison(&tab[j], &pivot) == first) {
            j--;
        }

        if (i <= j) {
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;
            j--;
        }
    }

    return i;
}

void GRAPH::sort_q(CIAG_STOPNIOWY tab[], int st, int en) {
    if (st < en) {
        int q = part(tab, st, en);
        sort_q(tab, st, q - 1);
        sort_q(tab, q, en);
    }
}
