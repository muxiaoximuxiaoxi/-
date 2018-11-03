#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {

	for (int i = 1; i <= 100; i++) {
		if (i == 9) {
          printf("%d\t", i);
		}
		else if (i % 10 == 9) {
			printf("%d\t", i);
		}
		else if (i / 10 == 9) {
			printf("%d\t", i);
		}
	}
	system("pause");
}
