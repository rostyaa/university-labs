#include <iostream>

using namespace std;

int ekv(int x, int y) {
    return (x && y) || (!x && !y);
}

int main()
{

    cout << "A " << "\tB " << "\tC " << "\tD " << "\tf" << endl << endl;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {

                    int result0 = ekv(a && !d || !(a && b) && c, a && !c && d);
                    int result = !result0 || b && !c;
                    cout << a << " \t" << b << " \t" << c << " \t" << d << " \t" << result << endl;

                }
            }
        }
    }

    return 0;
}
