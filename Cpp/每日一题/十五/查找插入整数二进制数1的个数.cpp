/*
查找输入整数二进制中1的个数
请实现如下接口
public   static   int  findNumberOf1(int num)

{
	//  请实现  

	return  0;

} 譬如：输入5 ，5的二进制为101，输出2
涉及知识点：
输入描述 :
输入一个整数
输出描述 :
计算整数二进制中1的个数
示例1
输入
5
输出
2
*/
#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		int m = 0;
		while (n != 0) {
			m = n % 2;
			n /= 2;
			if (m == 1) {
				++count;
			}
		}
		cout << count << endl;
	}
}
