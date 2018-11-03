#include<stdio.h>
int main(){
	int a=10,b=20,c=0;
	c=a^b;
	a=a^c;
	b=b^c;
	printf("a=%d b=%d",a,b);
}
