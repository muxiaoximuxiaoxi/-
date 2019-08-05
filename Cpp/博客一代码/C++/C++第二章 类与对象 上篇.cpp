#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

	class student
	{
	public:
		void show()
		{
			cout << _name << "-" << _age << endl;
		}
		void Set(char name,int age)
		{
			_name = name;
			_age = age;
		}
	public:
		char _name;
		int _age;
	};

	void TestS()
	{
	student s;
	s._name = 'j'; 
	s._age = 20;
	s.show();
	}
	int check_sys() {
		int i = 1;
		return (*(char*)&i);//将i的地址，强转成char*的指针,即取到了第一个字节的位置
	}
	void TestCheck_sys()
	{
		int p = check_sys();
		cout << p << endl;
		if (p == 1)
			cout << "小端" << endl;
		else
			cout << "大端" << endl;
	}

int main()
{
	student s1, s2;
	s1.Set('j', 18);
	s2.Set('s', 20);
	s1.show();
	s2.show();
	//TestS();
	/*student m;
	printf("m=%d\n", sizeof(m));
	student w;
	w._age = 12;
	w._name = 'w';
	printf("w=%d\n", sizeof(w));*/
	//TestCheck_sys();

	//system("pause");
}
