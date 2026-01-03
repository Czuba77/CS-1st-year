#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



void make_bin(int* bin_number, int number_to_convert) {
	for (int i = 0; i < 15; i++) {
		bin_number[i] = number_to_convert % 2;
		number_to_convert = number_to_convert / 2;
	}
}

int main()
{
	int how_many_things, Price[15], Weight[15], capacity, bin_number[15];
	int curr_load = 0, curr_price = 0;
	int best_price = 0;
	for(int k =0;k<500;k++)
	{
		scanf("%d", &how_many_things);
		for (int i = 0; i < how_many_things; i++)
			scanf("%d", &Price[i]);
		for (int i = 0; i < how_many_things; i++)
			scanf("%d", &Weight[i]);
		scanf("%d", &capacity);
		for (int i = 0; i < pow(2, how_many_things); i++) {
			make_bin(bin_number, i);
			for (int j = 0; j < how_many_things; j++) {
				if (bin_number[j]) {
					curr_load += Weight[j];
					curr_price += Price[j];
				}
			}
			if (curr_load <= capacity && curr_price > best_price) {
				best_price = curr_price;
			}
			curr_load = 0;
			curr_price = 0;
		}
		printf("%d\n", best_price);
		best_price = 0;
	}
}
