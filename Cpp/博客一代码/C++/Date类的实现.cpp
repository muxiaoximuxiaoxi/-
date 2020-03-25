#pragma once
#include<iostream>
using namespace std;
class Data
{
public:

	 static int GetMonthDays(int year, int month)
	{
		static int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (((year % 4 == 0 && year % 100 != 0)
			|| (year % 400 == 0)) && month == 2)
			return arr[month] + 1;
		return arr[month];
	}
	Data(int year=1900, int month=1, int day=1) 
	{//构造函数
		if (year >= 1900
			&& month > 0 && month < 13
			&& day>0 && day <= GetMonthDays(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "输入有误！！！" << endl;
	}
	//不写析构函数了，因为这是日期类，并没有涉及到内存的申请，
	//所以可以使用系统自动生成的析构函数
	//其实拷贝构造也不需要自己重新写，这是一个日期类，没有深浅拷贝之说，所以
	//系统默认生成的拷贝构造函数已经够用了，当然自己写也是可以的
	const Data(const Data& d)
	//第一个const修饰的目的是，虽然返回的是T的引用，但是返回值不能作为<左值>，
	//也就是对于返回值只能读，不能写

	//第二个const目的是在data()函数内部，不能以任何方式直接或间接的修改成员变量
	//就是说只能读成员变量而不能写
	{//拷贝构造函数
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(const Data& d)
	{
		if (_year == d._year
			&&_month == d._month
			&&_day == d._day)
			return true;
		return false;
	}
	bool operator!=(Data d)
	{
		if (*this == d)
			return false;
		return true;
	}
	bool operator<(const Data d)const
	{
		if (_year < d._year)
			return true;
		else
		{
			if (_month < d._month)
				return true;
			else
			{
				if (_day < d._day)
					return true;
			}
		}
		return false;
	}
	bool operator>(Data d)
	{
		if (_year < d._year)
			return false;
		else
		{
			if (_month < d._month)
				return false;
			else
			{
				if (_day < d._day)
					return false;
			}
		}
		return true;
	}
	bool operator<=(Data d)
	{
		if ((*this < d) || (*this == d))
			return true;
		return false;
	}
	bool operator>=(Data d)
	{
		if ((*this > d) || (*this == d))
			return true;
		return false;
	}

	Data& operator=(const Data& d)//传参和传值如果使用引用的
	//话可以减少两次拷贝构造的调用
	{
		if (this != &d)//自己给自己赋值，没有必要，还会报错
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//可以实现连续赋值
	}
	Data operator+(int day) const 
		//加const的目的是避免直接对参数进行修改
		//但这里可加可不加
	{
		//_day += day;//不可以直接对参数进行修改
		Data ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDays(_year, _month))
		{
			ret._day -= GetMonthDays(_year, _month);
			++ret._month;
			if (_month == 13)
			{
				++ret._year;
				ret._month = 1;
			}
		}
		return ret;
	}
	Data operator-(int day) const
	{
		Data ret = *this;
		ret._day -= day;
		while ((ret._day < 1))
		{
			--ret._month;
			if (ret._month == 0)
			{
				--ret._year;
				ret._month = 12;
				ret._day += GetMonthDays(ret._year, ret._month);
			}
			else
			{
				ret._day += GetMonthDays(ret._year, ret._month);
			}
		}
		return ret;
	}
	int operator-(const Data& d) const
	{
		Data maxData(*this);
		Data minData(d);
		int flag = 1;
		if (maxData<minData) 
		//始终让maxData>minData
		//但是当进入此条件后表示，原来两个日期相减应该为负数，
		//故需要将flag置为-1
		{
			maxData = d;
			minData = *this;
			flag = -1;
		}
		int count = 1;
		while (minData != maxData)
		{
			minData += 1;
			++count;
		}
		return count * flag;
	}

	Data operator+=(int day) 
	{
		Data ret = *this;
		ret._day += day;
		while (ret._day > GetMonthDays(ret._year, ret._month))
		{
			ret._day -= GetMonthDays(ret._year, ret._month);
			++ret._month;
			if (ret._month == 13)
			{
				ret._month = 1;
				++ret._year;
			}
		}
		return ret;
	}
	Data operator-=(int day) const
	{
		Data ret = *this;
		ret._day -= day;
		while (ret._day < 1)
		{
			--ret._month;
			if (ret._month == 0)
			{
				--ret._year;
				ret._month = 12;
				ret._day += GetMonthDays(ret._year, ret._month);
			}
			else
			{
				ret._day += GetMonthDays(ret._year, ret._month);
			}
		}
		return ret;
	}

	Data operator++()  //前置++
		//即++i
	{
		return *this += 1;
	}
	Data operator++(int)//后置++
		//即i++
	{
		Data ret = *this;
		*this += 1;
		return ret;
	}
	Data operator--()//前置--
		//即--i
	{
		return *this -= 1;
	}
	Data operator--(int)//后置--
		//即--i
	{
		Data ret = *this;
		*this += 1;
		return ret;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test1()
{
	/*Data d(2019, 9, 11);
	Data d2(2019, 8, 12);
	(d - 10).Print();
	cout << (d - d2) << endl;*/
	/*(d++).Print();
	(++d).Print();
	(--d).Print();
	(d--).Print();*/
	//(d - 100).Print();
	//(d - 1000).Print();
	//Data d2(2009, 3, 2);
	//cout << (d == d2) << endl;
	//cout << (d != d2) << endl;
	/*cout << (d < d2) << endl;
	cout << (d > d2) << endl;
	cout << (d <= d2) << endl;
	cout << (d >= d2) << endl;*/
	//(d +20).Print();
	/*Data d1;
	Data d2;
	d1 = d2 = d;
	d1.Print();
	d2.Print();*/
	/*Data d1(1900, 2, 4);
	Data d2(d1);
	cout <<(d == d1)<< endl;
	cout << (d2 == d1) << endl;*/
	/*Data d1(d);
	d.Print();
	d1.Print();*/
}
