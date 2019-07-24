/*
三角形判断
KiKi想知道已经给出的三条边a，b，c能否构成三角形，
如果能构成三角形，判断三角形的类型（等边三角形、
等腰三角形或普通三角形）。
输入描述:
题目有多组输入数据，每一行输入三个a，b，c(0<a,b,c<1000)，
作为三角形的三个边，用空格分隔。
输出描述:
针对每组输入数据，输出占一行，如果能构成三角形，
等边三角形则输出“Equilateral triangle!”，
等腰三角形则输出“Isosceles triangle!”，
其余的三角形则输出“Ordinary triangle!”，
反之输出“Not a triangle!”。
示例1
输入
2 3 2
3 3 3
输出
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
