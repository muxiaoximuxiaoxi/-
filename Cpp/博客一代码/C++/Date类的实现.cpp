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
	{//���캯��
		if (year >= 1900
			&& month > 0 && month < 13
			&& day>0 && day <= GetMonthDays(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "�������󣡣���" << endl;
	}
	//��д���������ˣ���Ϊ���������࣬��û���漰���ڴ�����룬
	//���Կ���ʹ��ϵͳ�Զ����ɵ���������
	//��ʵ��������Ҳ����Ҫ�Լ�����д������һ�������࣬û����ǳ����֮˵������
	//ϵͳĬ�����ɵĿ������캯���Ѿ������ˣ���Ȼ�Լ�дҲ�ǿ��Ե�
	const Data(const Data& d)
	//��һ��const���ε�Ŀ���ǣ���Ȼ���ص���T�����ã����Ƿ���ֵ������Ϊ<��ֵ>��
	//Ҳ���Ƕ��ڷ���ֵֻ�ܶ�������д

	//�ڶ���constĿ������data()�����ڲ����������κη�ʽֱ�ӻ��ӵ��޸ĳ�Ա����
	//����˵ֻ�ܶ���Ա����������д
	{//�������캯��
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

	Data& operator=(const Data& d)//���κʹ�ֵ���ʹ�����õ�
	//�����Լ������ο�������ĵ���
	{
		if (this != &d)//�Լ����Լ���ֵ��û�б�Ҫ�����ᱨ��
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//����ʵ��������ֵ
	}
	Data operator+(int day) const 
		//��const��Ŀ���Ǳ���ֱ�ӶԲ��������޸�
		//������ɼӿɲ���
	{
		//_day += day;//������ֱ�ӶԲ��������޸�
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
		//ʼ����maxData>minData
		//���ǵ�������������ʾ��ԭ�������������Ӧ��Ϊ������
		//����Ҫ��flag��Ϊ-1
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

	Data operator++()  //ǰ��++
		//��++i
	{
		return *this += 1;
	}
	Data operator++(int)//����++
		//��i++
	{
		Data ret = *this;
		*this += 1;
		return ret;
	}
	Data operator--()//ǰ��--
		//��--i
	{
		return *this -= 1;
	}
	Data operator--(int)//����--
		//��--i
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
