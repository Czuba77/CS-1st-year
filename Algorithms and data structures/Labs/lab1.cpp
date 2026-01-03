
#include <iostream>
using namespace std;

struct W {
    int x, y;
};


int main()
{
    int l, n, POLE = 0, prz = 0;
    W ws, wz1, wz2;
    cin >> l;
    for (int j = 0; j < l; j++) {
        cin >> n;
        cin >> ws.x;
        cin >> ws.y;
        cin >> wz1.x;
        cin >> wz1.y;
        POLE += ws.x * wz1.y - ws.y * wz1.x;
        for (int i = 4; i < n; i += 2) {
            cin >> wz2.x;
            cin >> wz2.y;
            i += 2;
            POLE += wz1.x * wz2.y - wz1.y * wz2.x;
            if (i == n) {
                prz = 1;
                break;
            }
            cin >> wz1.x;
            cin >> wz1.y;
            POLE += wz2.x * wz1.y - wz2.y * wz1.x;
        }
        if (prz)
            POLE += wz2.x * ws.y - wz2.y * ws.x;
        else
            POLE += wz1.x * ws.y - wz1.y * ws.x;
        if (POLE < 0) POLE *= (-1);
        cout << POLE / 2 << endl;
        prz = 0;
        POLE = 0;
    }

}
