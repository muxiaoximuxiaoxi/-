/*统计每个月兔子的总数
有一只兔子，从出生后第3个月起每个月都生一只兔子，
小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，
问每个月的兔子总数为多少？
/**
 * 统计出兔子总数。
 *
 * @param monthCount 第几个月
 * @return 兔子总数
 */
//	public static int getTotalCount(int monthCount)
//{
//	return 0;
//}
//输入描述:
//输入int型表示month
//输出描述 :
//输出兔子总数int型
//示例1
//输入
//9
//输出
//34

#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 1 || n == 2)
			cout << 1;
		int f1 = 1;
		int f2 = 1;
		int f = 0;
		for (int i = 2;i < n;++i) {
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
		cout << f;
	}
	system("pasue");
}
