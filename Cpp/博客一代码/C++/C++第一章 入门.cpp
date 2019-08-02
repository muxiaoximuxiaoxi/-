#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;
//写求和
#define Add((a),(b)) (((a)+(b)))

inline int Add1(int a, int b)
{
	return a + b;
}

int main()
{
	cout << Add(1, 2) << endl;

}
//int& Add(int a, int b) {
//	int c = a + b;
//	return c;
//}
//int Bdd(int& a, int& b) {
//	int c = a + b;
//	return c;
//}

//常引用
//int main()
//{
	//const int a = 10;
	////int& ba = a;//无法将const int 转换成 int&
	//const int& baa = a;
	//const double b = 20.0;
	////double& bb = b;//无法将const double 转换成 double&
	//const double& bba = b;
	//int a = 10;
	//auto b = a;
	////char s = 'a';
	////auto s1 = s;
	//auto& c = b;
	///*string str = "hehe";
	//for (auto e : str)
	//	cout << e;
	//cout << endl;
	//cout << b << endl;
	//cout<< s1 << endl;*/
	//cout << c << endl;
	/*int a[] = { 1,2,3,4,5,6,7 };
	string s = "my name is Tom!";
	for (auto e : a)
		cout << e<<" ";
	cout << endl;
	for (auto e : s)
		cout << e;
	cout << endl;*/
	//system("pause");
//}

