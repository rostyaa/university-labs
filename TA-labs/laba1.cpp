//варіант 2
//завдання 1
#include<iostream>
using namespace std;

int g(int y) {
	return 4 * y - 6;
}
void f(int y) {
	cout << "y: " << y << "\t" << 2 * g(0) + 3 * y << endl;
	y++;
	if (y == 5) {
		cout << "";
	}
	else {
		f(y);
	}
}
int main() {
	f(0);
	return 0;
}

////завдання 2
//#include<iostream>
//using namespace std;
//
//int g(int y) {
//	return y + 1;
//}
//void h(int x, int y) {
//	cout << "y =" << y << "\tx = " << x << "\th(x,y)=" << g(x) * y + g(x) << endl;
//	y++;
//	if (y == 3) {
//		cout << "";
//	}
//	else {
//		h(x, y);
//	}
//}
//int main() {
//	h(0, 0);
//	return 0;
//}
//
//
////завдання 3
//#include<iostream>
//using namespace std;
// 
//void f(int x, int y) {
//	if (x != 3) {
//		if ((x - y + 2) != 0)
//		{
//			cout << "x=" << x << "\ty =" << y << "\tx-y+2=" << x - y + 2 << endl;
//			y++;
//			f(x, y);
//	    }
//		else {
//			cout << "x=" << x << "\ty =" << y << "\tx-y+2=" << x - y + 2 << "\n" << endl;
//			x++;
//			y = 0;
//			f(x, y);
//		}
//	 }
//}
//
//int main()
//{
//	f(0, 0);
//}
//
