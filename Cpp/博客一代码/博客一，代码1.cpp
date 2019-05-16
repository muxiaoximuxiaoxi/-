#include<iostream>
#include <assert.h>
#include<stdlib.h>
using namespace std;
int& Add1(int a, int b) {
	int c = a + b;
	return c;
}
int Add2(int a, int b) {
	int c = a + b;
	return c;
}int* Add3(int a, int b) {
	int c = a + b;
	return &c;
}
int main() {
	int a = 10;
	int b = 20;
	cout << "Add1(a, b)=" << Add1(a, b) << endl;
	cout << "Add2(a, b)=" << Add2(a, b) << endl;
	cout << "Add3(a, b)=" << Add3(a, b) << endl;
	system("pause");
}
//int main() {
//	int a = 10;
//	int& b = a;
//	int*p1 = &a;
//	int *p2 = &b;
//	int** p3 = &p1;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "p1=" << p1 << endl;
//	cout << "p2=" << p2 << endl;
//	cout << "p3=" << p3<< endl;
//	cout << "*p3=" << *p3 << endl;
//	system("pause");
//}
//using namespace std;
//int Add(int left, int right)
//{
//
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//int main()
//{
//    cout<<Add(10, 20) << endl;
//	cout<<Add(10.1, 20.0)<<endl;
//	system("pause");
//	return 0;
//}


//void Func(int a , int b ,int c = 30) {
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//}
//int main() {
//	Func(1,5);
//	cout << "....." << endl;
//	Func(200,3);
//	system("pause");
//}
//using std::cout;
//using std::cin;
//using std::endl;
//int main() {
//	int a;
//	double b;
//	char c;
//	cin >>a;
//	cin >> b>>c;
//	cout << a <<endl<< b <<endl<<c << endl;
//
//	system("pause");
//}
//using std::cout;
//using std::endl;
//
//namespace Zhao {
//	int value = 10;
//}
//
//namespace Qian {
//	char value = 'A';
//}
//
//namespace Sun {
//	double value = 3.14;
//}
//int main() {
//	cout << Zhao::value << endl;
//	cout << Qian::value << endl;
//	cout << Sun::value << endl;
//	system("pause");
//}

