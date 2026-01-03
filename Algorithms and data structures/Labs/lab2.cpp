#include <iostream>
#include <string>


#define first 1
#define second 2
#define equal 3

int comparison(std::string s_one, std::string s_two) {
    if (s_one.size() > s_two.size())
        return first;
    else if (s_one.size() < s_two.size())
        return second;
    else {
        for (int i = 0; i < s_one.size(); i++) {
            if (s_one[i] - '0' > s_two[i] - '0')
                return first;
            else if (s_one[i] - '0' < s_two[i] - '0')
                return second;
        }
    }
    return equal;
}

int part(std::string* tab, int st, int en) {
    std::string pivot_val = tab[st];
    while (true) {
        while (comparison(tab[st],pivot_val) == second){
            st++;
        }
        while (comparison(tab[en], pivot_val) == first){
            en--;
        }
        if (st < en)
            std::swap(tab[st], tab[en]);
        else
            return en;
        st++;
        en--;
    }
}

void sort_q(std::string* tab, int st, int en) {
    if (st < en) {
        int q = part(tab,st,en);
        sort_q(tab, st, q);
        sort_q(tab, q + 1, en);
    }
}

int main()
{
    int size;
    std::cin >> size;
    std::string* tab = new std::string[size]; //NULL;
    //tab = (std::string*)malloc(size * sizeof(std::string));
    for (int i = 0; i < size; i++) {
        std::cin >> tab[i];
    }
    sort_q(tab, 0, size - 1);
    for (int i = 0; i < size; i++) {
        std::cout << tab[i]<<" ";
    }
    //free(tab);
    delete[] tab;
}

