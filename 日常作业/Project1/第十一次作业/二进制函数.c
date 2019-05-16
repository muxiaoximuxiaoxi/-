//#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<stdio.h>
////写一个函数返回参数二进制中 1 的个数
////比如： 15 0000 1111 4 个 1
////程序原型：
////int count_one_bits(unsigned int value)
////{
////	// 返回 1的位数 
////}
//
int count_one_bits(unsigned int value) {
	int count = 0;
	while (value) {
		if (value % 2 == 1) {
			++count;
		}
		value /= 2;
	}
	return count;
}
int main() {
	int x = 0;
	int ret = 0;
	printf("请输入你想要计算该数为二进制形式下 1 的个数：\n");
	scanf("%d", &x);
	ret = count_one_bits(x);
	printf("%d在二进制形式下 1 的个数为%d个\n", x, ret);
	system("pause");
}
