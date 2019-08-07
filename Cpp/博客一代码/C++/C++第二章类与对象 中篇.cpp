#pragma once
#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//构造函数
	{	
		_year = year;
		_month = month;
		_day = day;
	}
	~Date()
	{
		//cout << "~Date()" << this << endl;
	}
	//Date(Data d)//值传递传参时，就会调用拷贝构造函数来构造临时变量，形成递归
	//{			//应改为Data(Data& d)拷贝构造，需要传参，而d是d1的别名
	//			//但为了更保险一点应该改为Data(const Data& d)
	//			//这样就这样保证d的值不会被修改
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	/*Date(const Data& d)
	{
		_year = d._year;
		_month = d._month;  //由于上述是浅拷贝，所有会让多个对象指向
		_day = d._day;		//同一个地址，当析构时，假设`s1`析构后，
	}*/					    //若此时进程中的该线程将这一部分地址还给了系统
							//且系统又将这部分地址给了另一个线程，
							//之后`s2`析构时就是在析构别人的地址	
	Date(const Date& d)
	{
		_year = d._year;
		py = new int(d._year);
		_month = d._month;
		pm = new int(d._month);
		_day = d._day;
		pd = new int(d._day);
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	Date& operator=(const Date& d)
	//第一个&是为了在连续赋值的时候提高效率
	{
		if (&d != this)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	Date* operator&()
	{
		return this;
	}
	const Date* operator&() const
	{
		return this;
	}
	void CoutDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << py << "-" << pm << "-" << pd << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	int* py;
	int* pm;
	int* pd;
};
int main() 
{
	Date d1(1919, 2, 4);
	Date d2(1919, 2, 8);
	//cout << (d1 == d2) << endl;
	Date d3 = d2;
	d2.CoutDate();
	d3.CoutDate();
	//Data d2;
	//Data d4(d1);
	//Data d3();//编译时会报错
	//cout << "d1为";
	//d1.CoutData();
	//cout << "d2为";
	//d2.CoutData();
	//cout << "d4为";
	//d4.CoutData();
	/*cout<<"d2="<<d2.CoutData();
	cout<<"d4="<<d4.CoutData();*/
	//d3.CoutData();//表达式包含类类型
}


