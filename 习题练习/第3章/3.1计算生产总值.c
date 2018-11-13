#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//假如我国国民生产总值的年增长率为9%，请编写一个程序计算10年后我国国民生产总值与现在相比增长多少百分比？

//注释：其计算公式为

//p = (1 + r)n
//（其中r为年增长率，n为年数，p为与现在相比的倍数）
int main() {
	double p = 0, r = 0.09;
	int n = 10;
	p = pow(1 + r, n);
	printf("%f\n", p);
	system("pause");
}
