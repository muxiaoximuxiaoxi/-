#include<iostream>
#include<deque>

using namespace std;

void deque_test1()
{
	deque<int> d1;
	for (auto a : d1)
	{
		cout << a << " ";
	}
	cout << endl;
	deque<int> d2(10, 10);
	for (auto a : d2)
	{
		cout << a << " ";
	}
	cout << endl;
	deque<int> d3(d2.begin(), d2.end());
	for (auto a : d3)
	{
		cout << a << " ";
	}
	cout << endl;
	deque<int> d4(d3);
	for (auto a : d4)
	{
		cout << a << " ";
	}
	cout << endl;
}
void deque_test2()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	auto it1 = d1.begin();
	while (it1 != d1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	auto it2 = d1.rbegin();
	while (it2 != d1.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
	auto it3 = d1.cbegin();
	while (it3 != d1.cend())
	{
		cout << *it3 << " ";
		++it3;
	}
	cout << endl;
	auto it4 = d1.crbegin();
	while (it4 != d1.crend())
	{
		cout << *it4 << " ";
		++it4;
	}
	cout << endl;
}
void deque_test3()
{
	deque<int> d1;
	cout << "d1.size()=" << d1.size() << endl;
	cout << "d1.empty()=" << d1.empty() << endl;
	d1.resize(5, 5);
	for (auto a : d1)
	{
		cout << a << " ";
	}
	cout << endl;
}
void deque_test4()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	cout << "d1[2]=" << d1[2] << endl;
	cout << "d1.front()=" << d1.front() << endl;
	cout << "d1.back()" << d1.back() << endl;
}
void deque_test5()
{
	deque<int> d1(3, 3);
	d1.push_back(1);
	d1.push_back(1);
	d1.push_front(2);
	d1.push_front(2);
	for (auto a : d1)
	{
		cout << a << " ";
	}
	cout << endl;
	d1.pop_back();
	d1.pop_front();
	for (auto a : d1)
	{
		cout << a << " ";
	}
	cout << endl;
	auto it1 = d1.begin();
	d1.insert(it1, 0);
	//会导致迭代器失效
	/*while (it1 != d1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;*/
	auto it2 = d1.begin();
	while (it2 != d1.end())
	{
		if (*it2 % 2 == 0)
			//d1.erase(it2);//会导致迭代器失效
			it2 = d1.erase(it2);
		else
			++it2;
	}
	for (auto a : d1)
	{
		cout << a << " ";
	}
	cout << endl;
	deque<int> d2(4, 4);
	for (auto a : d2)
	{
		cout << a << " ";
	}
	cout << endl;
	d2.insert(d2.begin(),d1.begin(), d1.end());
	cout << "执行d2.insert(d2.begin(),d1.begin(), d1.end());之后" << endl;
	for (auto a : d2)
	{
		cout << a << " ";
	}
	cout << endl;
	auto it3 = d2.begin();
	++it3;
	d2.erase(d2.begin(), it3);
	//d2.erase(d2.begin(), d2.begin()++);
	cout << "执行d2.erase(d2.begin(), d2.begin()++);之后 " << endl;
	for (auto a : d2)
	{
		cout << a << " ";
	}
	cout << endl;
	d2.emplace_front(5);
	d2.emplace_back(10);
	d2.emplace(d2.begin(), 99);
	for (auto a : d2)
	{
		cout << a << " ";
	}
	cout << endl;
	deque<char> d3(3, 'A');
	deque<char> d4(4, 'a');
	cout << "d3=";
	for (auto a : d3)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << "d4=";
	for (auto a : d4)
	{
		cout << a << " ";
	}
	cout << endl;
	d3.swap(d4);
	cout << "d3=";
	for (auto a : d3)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << "d4=";
	for (auto a : d4)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << "执行d3.clear()之后" << endl;
	d3.clear();
	for (auto a : d3)
	{
		cout << a << " ";
	}
	cout << endl;
}
void deque_test6()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(3);
	d1.push_back(4);
	d1.push_back(15);
	auto it1 = d1.begin();
	//d1.insert(it1,10);会导致迭代器失效
	it1 = d1.insert(it1, 10);//解决方法，重新获取一下
	while (it1 != d1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	auto it2 = d1.begin();
	//d1.erase(it2);会导致迭代器失效
	it2 = d1.erase(it2);//解决方法，重新获取一下
	while (it2 != d1.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}
//int main()
//{
//	//deque_test1();
//	//deque_test2();
//	//deque_test3();
//	//deque_test4();
//	//deque_test5();
//	deque_test6();
//	return 0;
//}
