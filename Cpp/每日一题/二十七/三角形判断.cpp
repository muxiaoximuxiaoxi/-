/*
�������ж�
KiKi��֪���Ѿ�������������a��b��c�ܷ񹹳������Σ�
����ܹ��������Σ��ж������ε����ͣ��ȱ������Ρ�
���������λ���ͨ�����Σ���
��������:
��Ŀ�ж����������ݣ�ÿһ����������a��b��c(0<a,b,c<1000)��
��Ϊ�����ε������ߣ��ÿո�ָ���
�������:
���ÿ���������ݣ����ռһ�У�����ܹ��������Σ�
�ȱ��������������Equilateral triangle!����
�����������������Isosceles triangle!����
������������������Ordinary triangle!����
��֮�����Not a triangle!����
ʾ��1
����
2 3 2
3 3 3
���
Isosceles triangle!
Equilateral triangle!*/
#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
     
    while (cin>>a>>b>>c) {
        if (a + b <= c || a + c <= b || b + c <= a) puts("Not a triangle!");
        else if (a == b && a == c) puts("Equilateral triangle!");
        else if (a == b || a == c || b == c) puts("Isosceles triangle!");
        else puts("Ordinary triangle!");
    }
}
