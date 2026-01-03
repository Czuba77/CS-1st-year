#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


int main()
{
    char** tab;
    bool cond;
    int size, how_many_graphs, claw_ind1, claw_ind2, claw_ind3, claw_counter, numb;
    char digit;
    scanf("%d", &how_many_graphs);
    getchar();// pobiera \n
    for (int f = 0; f < how_many_graphs; f++) {
        claw_counter = 0;
        cond = false;
        scanf("%d", &size);
        getchar(); // pobiera spacje
        tab = new char* [size];
        for (int i = 0; i < size; i++) {
            tab[i] = new char[size];
            for (int j = 0; j < size; j++) {
                tab[i][j] = getchar();
            }
        }
        for (int row = 0; row < size; row++) {
            claw_ind1 = -1;
            claw_ind2 = -1;
            claw_ind3 = -1;
                for (int which_rel = 0; which_rel < size; which_rel++) {

                    if (tab[row][which_rel] == '1') {
                        if (row == which_rel)
                            break;

                        for (int j = 0; j < size; j++) {
                            if (tab[which_rel][j] != '0') {
                                if (j == row)
                                    cond = true;
                                else if(j==claw_ind1 || j == claw_ind2 || j == claw_ind3){
                                    cond = false;
                                    break;
                                }
                            }
                        }

                        if (cond) {
                            if (claw_ind1 == -1)
                                claw_ind1 = which_rel;
                            else if (claw_ind2 == -1)
                                claw_ind2 = which_rel;
                            else if(claw_ind3 == -1)
                                claw_ind3 = which_rel;
                            claw_counter++;
                        }
                        cond = false;
                    }
                }
                if (claw_counter > 2){
                    break;
                }
                claw_counter = 0;
        }
        if (claw_counter>2)
            printf("0\n");
        else
            printf("1\n");
        for (int i = 0; i < size; i++) {
            delete[] tab[i];
        }
        delete[] tab;
        getchar();// pobiera \n
    }
}