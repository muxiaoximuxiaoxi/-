/*
最小公倍数

*/
/*两种排序方法
考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学
习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
	2.根据字符串的长度排序。例如：
	"car" < "cats" < "koala" < "doggies" < "carriage"
	考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，
	考拉要忙着吃树叶，所以需要你来帮忙验证。

	输入描述 :
输入第一行为字符串个数n(n ≤ 100)
接下来的n行, 每行一个字符串, 字符串长度均小于100，均由小写字母
组成


输出描述 :
如果这些字符串是根据字典序排列而不是根据长度排列输出
"lexicographically",

如果根据长度排列而不是字典序排列输出"lengths",

如果两种方式都符合输出"both"，否则输出"none"
示例1
输入
3
a
aa
bbb
输出
both
通过100%修改版
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

bool Sort_dictionary(vector<string> v) {
	for (int i = 0;i < v.size() - 1;++i) {
		if (v[i] > v[i + 1])//前一个字符串必然小于后一个字符串
			return false;
	}
	return true;
}

bool Sort_size(vector<string> v) {
	for (int i = 0;i < v.size() - 1;++i) {
		if (v[i].length() > v[i + 1].length())
			return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	string str;
	vector<string> v;
	for (int i = 0;i < n;++i) {
		cin >> str;
		v.push_back(str);
	}
	if (Sort_dictionary(v) && !Sort_size(v)) {
		cout << "lexicographically";
	}
	else if (!Sort_dictionary(v)&&Sort_size(v)) {
		cout << "lengths";
	}
	else if (Sort_dictionary(v)&&Sort_size(v)) {
		cout << "both";
	}
	else {
		cout << "none";
	}
	system("pause");
	return 0;

}
通过100%
#include<iostream>

#include<vector>

#include<string>



using namespace std;



bool isle(vector<string> vs)

{

	for(int i = 0;i<vs.size()-1;++i)

		if(vs[i+1]<vs[i])

			return false;

	return true;

}



bool islen(vector<string> vs)

{

	for(int i = 0;i<vs.size()-1;++i)

		if(vs[i+1].length()<vs[i].length())

			return false;

	return true;

}



int main()

{

	int n;

	while(cin>>n)

	{

		string ts;

		vector<string> vs;

		for(int i = 0;i<n;++i)

		{

			cin>>ts;

			vs.push_back(ts);

		}

		if(isle(vs)&&islen(vs))

			cout<<"both"<<endl;

		else if(islen(vs)&&!isle(vs))

			cout<<"lengths"<<endl;

		else if(!islen(vs)&&isle(vs))

			cout<<"lexicographically"<<endl;

		else

			cout<<"none"<<endl;

	}



	return 0;

}








通过30%
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

bool Sort_dictionary(vector<string> v) {
	for (int i = 0;i < v.size() - 1;++i) {
		if (v[i] > v[i + 1])//前一个字符串必然小于后一个字符串
			return false;
	}
	return true;
}

bool Sort_size(vector<string> v) {
	for (int i = 0;i < v.size() - 1;++i) {
		if (v[i].length() > v[i + 1].length())
			return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	string str;
	vector<string> v;
	for (int i = 0;i < n;++i) {
		cin >> str;
		v.push_back(str);
	}
	if (Sort_dictionary && !Sort_size) {
		cout << "lexicographically";
	}
	else if (!Sort_dictionary&&Sort_size) {
		cout << "lengths";
	}
	else if (Sort_dictionary&&Sort_size) {
		cout << "both";
	}
	else {
		cout << "none";
	}
	system("pause");
	return 0;

}
*/
