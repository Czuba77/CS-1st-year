#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "LIST.h"
#include "NODE.h"
#include "GRAPH.h"








int main()
{
    int number_of_tests, number_of_ver;
    GRAPH* graph;
    scanf("%d", &number_of_tests);
    for (int i = 0; i < number_of_tests; i++) {
        scanf("%d", &number_of_ver);
        graph = new GRAPH(number_of_ver);
        graph->init_graph();
        graph->print_ciag_stopniowany();
        graph->count_skladowe_spojnosci();
        graph->dwudzielnosc_grafu();
        printf("?\n");
        printf("?\n");
        graph->Kolorowanie_wierzcholkow_alg_zachlanny();
        graph->clear_colours();
        graph->Kolorowanie_wierzcholkow_alg_LF();
        printf("?\n");
        printf("?\n");
        graph->print_dopelnienie_grafu();
        delete(graph);
    }
}
