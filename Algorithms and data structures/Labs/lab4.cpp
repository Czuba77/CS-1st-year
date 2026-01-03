#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


int main()
{
	char** tab;
	bool cond;
	int size, how_many_graphs, one_counter = 0, how_many_del = 0, which_element = 0, prev;
	char digit;
	scanf("%d", &how_many_graphs);
	getchar();// pobiera \n
	for (int k=0;k<how_many_graphs;k++){
		cond = false;
		how_many_del = 0;
		one_counter = 0;
		which_element = 0;
		scanf("%d", &size);
		getchar(); // pobiera spacje
		tab = new char*[size];
		for (int i = 0; i < size; i++) {
			tab[i] = new char[size];
			for (int j = 0; j < size; j++) {
				digit = getchar();
				if (digit == '1') {
					one_counter++;
					if (one_counter > 2) {
						printf("0\n");
						for (int l = 0; l <= i; l++) {
							delete[] tab[l];
						}
						delete[] tab;
						while (getchar() != '\n');
						break;
					}

				}
				tab[i][j] = digit;
			}
			if (one_counter > 2)
				break;
			else
				one_counter = 0;
		}
		if (one_counter > 2)
			continue;
		while (true) {
			for (int i = 0; i < size; i++) {
				if (tab[which_element][i] == '1') {
					prev = which_element;
					tab[which_element][i] = '0';
					how_many_del++;
					which_element = i;
					tab[which_element][prev] = '0';
					break;
				}
				else if (i == size - 1)
					cond = true;
			}
			if (cond == true)
				break;
		}
		if (size == how_many_del)
			printf("1\n");
		else
			printf("0\n");
		for (int i = 0; i < size; i++) {
			delete[] tab[i];
		}
		delete[] tab;
		getchar();// pobiera \n
	}
}
