#pragma once
#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)//���캯��
	{	
		_year = year;
		_month = month;
		_day = day;
	}
	~Date()
	{
		//cout << "~Date()" << this << endl;
	}
	//Date(Data d)//ֵ���ݴ���ʱ���ͻ���ÿ������캯����������ʱ�������γɵݹ�
	//{			//Ӧ��ΪData(Data& d)�������죬��Ҫ���Σ���d��d1�ı���
	//			//��Ϊ�˸�����һ��Ӧ�ø�ΪData(const Data& d)
	//			//������������֤d��ֵ���ᱻ�޸�
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	/*Date(const Data& d)
	{
		_year = d._year;
		_month = d._month;  //����������ǳ���������л��ö������ָ��
		_day = d._day;		//ͬһ����ַ��������ʱ������`s1`������
	}*/					    //����ʱ�����еĸ��߳̽���һ���ֵ�ַ������ϵͳ
							//��ϵͳ�ֽ��ⲿ�ֵ�ַ������һ���̣߳�
							//֮��`s2`����ʱ�������������˵ĵ�ַ	
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
	//��һ��&��Ϊ����������ֵ��ʱ�����Ч��
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
	//Data d3();//����ʱ�ᱨ��
	//cout << "d1Ϊ";
	//d1.CoutData();
	//cout << "d2Ϊ";
	//d2.CoutData();
	//cout << "d4Ϊ";
	//d4.CoutData();
	/*cout<<"d2="<<d2.CoutData();
	cout<<"d4="<<d4.CoutData();*/
	//d3.CoutData();//���ʽ����������
}


