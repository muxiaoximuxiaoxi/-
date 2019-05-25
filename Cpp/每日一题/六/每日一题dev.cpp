

/*不要二
二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，
网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，
任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为 :
	((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 
	的算术平方根
	小易想知道最多可以放多少块蛋糕在网格盒子里。

	输入描述 :
每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000)


输出描述 :
	输出一个最多可以放的蛋糕数
	示例1
	输入
	3 2
	输出
	4
#include<iostream>
#include<stdlib.h>
using namespace std;
不需要找规律，直接递推
定义一个数组a[1000][1000],初始值都为0，从a[0][0]开始,
将a[0][2]和a[2][0]置为-1,遍历数组，不是-1的地方可以放蛋糕
int a[1000][1000] = { 0 };
int main() {
	int w, h;
	cin >> w >> h;
	int count = 0;
	for (int i = 0;i < w;++i) {
		for (int j = 0;j < h;++j) {
			if (a[i][j] == 0) {
				++count;
				if ((j + 2) < h)
					a[i][j + 2] = 1;
				if ((i + 2) < w)
					a[i + 2][j] = 1;
			}
		}
	}
		cout << count << endl;
		system("pause");
}
*/


/*把字符串转换成整数 

将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

输入描述:
输入一个字符串,包括数字字母符号,可以为空


输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
    1a33
输出
2147483647
    0







class Solution {
public:
    int StrToInt(string str) {
        int len=str.size();
        if(len<=0){
            return 0;
        }
        int flag=1;
        int sum=0;
       int i=0;
        if(str[i]=='-'){
            ++i;
            flag=-1;
        }
        if(str[i]==' '){
            ++i;
            flag=1;
        }
        if(str[i]=='+'){
            ++i;
            flag=1;
        }
       while(str[i]!='\0'){
           if(str[i]>'0'&&str[i]<'9'){
               sum=sum*10+(str[i]-'0');
               ++i;
           }else{
               sum=0;
               break;
           }
       }
        return sum*flag;
    }
};*/
