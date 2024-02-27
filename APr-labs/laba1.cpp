//варіант 30
//завдання 1
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x = 0.92;
    double y = 5.3;
    double a = 0.25;
    double pi = 3.14159265358979323846;

    double a = (cos(pow(x, 3) - pi / 2)) / (1 + log10(y - 2)) + cbrt(y - 2);
    double b = (pow(a, 2 * x) + pow(y, -x) * cos(a + x) * x) / fabs(x - 1);

    cout << "value a: " << a << endl;
    cout << "value b: " << b << endl;

    return 0;
}

//завдання 2
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//double f1(double x, double y) {
//    return x * x + y * y;
//}
//
//double f2(double x, double y) {
//    return x * x + y;
//}
//
//double f3(double x, double y) {
//    return log(x * x + y * y);
//}
//
//int main() {
//    double hx = 0.2;
//    double hy = 0.3;
//    double x_start = 0.1;
//    double x_end = 1.3;
//    double y_start = 0.1;
//    double y_end = 1.3;
//    double integral1 = 0.0;
//    double integral2 = 0.0;
//    double integral3 = 0.0;
//
//    for (double x = x_start; x < x_end; x += hx) {
//        for (double y = y_start; y < y_end; y += hy) {
//            
//            double x_mid = x + hx / 2;
//            double y_mid = y + hy / 2;
//
//            if (x_mid * x_mid + y_mid * y_mid <= 1) {
//                integral1 += f1(x_mid, y_mid) * hx * hy;
//            }
//            else if (x_mid * x_mid + y_mid * y_mid > 1 && y_mid >= x_mid) {
//                integral2 += f2(x_mid, y_mid) * hx * hy;
//            }
//            else if (x_mid * x_mid + y_mid * y_mid > 1 && y_mid < x_mid) {
//                integral3 += f3(x_mid, y_mid) * hx * hy;
//            }
//        }
//    }
//
//    cout << "Integral 1: " << integral1 << endl;
//    cout << "Integral 2: " << integral2 << endl;
//    cout << "Integral 3: " << integral3 << endl;
//
//    return 0;
//}
// 
