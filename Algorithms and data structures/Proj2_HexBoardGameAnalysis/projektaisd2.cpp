#include "HEX_B.h"
#include <iostream>

int main()
{

    HEX_B h1;
    while (true) {
        h1.solve_hex();
        h1.prepare_next();
        if (h1.getEof())
            break;
    }

    return 0;
}
