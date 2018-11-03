
#include<stdio.h>
#include<stdlib.h>
int main() {
	int p, r, n, m, temp;
	printf("请输入俩个正整数，n,m\n");
	scanf("%d %d", &n, &m);
	if (n < m) {
		temp = n;
		n = m;
		m = temp;
	}
	p = n * m;
	while (m != 0) {
		r = n % m;
		n = m;
		m = r;
	}
	printf("最大公约数为：%d\n", n);
	printf("最小公倍数为：%d\n", p / n);

		system("pause");
}
