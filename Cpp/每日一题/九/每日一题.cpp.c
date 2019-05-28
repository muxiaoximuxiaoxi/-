#include<stdio.h>
#include<math.h>
#define p 3.14

int main(){
	double a,s1,s2,s3;
	s1=a*a;
	s2=(1/2)*(a*sqrt(a*a-(a/2)*(a/2)));
	s3=a*a*p;
	printf("a=%f\n",a);
	printf("s1=%f\t s2=%f\t s3=%f\n",s1,s2,s3);
	return 0;
}
