/*
��С������

*/
/*�������򷽷�
������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧ
ϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
"car" < "carriage" < "cats" < "doggies < "koala"
	2.�����ַ����ĳ����������磺
	"car" < "cats" < "koala" < "doggies" < "carriage"
	������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷���
	����Ҫæ�ų���Ҷ��������Ҫ������æ��֤��

	�������� :
�����һ��Ϊ�ַ�������n(n �� 100)
��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ
���


������� :
�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������
"lexicographically",

������ݳ������ж������ֵ����������"lengths",

������ַ�ʽ���������"both"���������"none"
ʾ��1
����
3
a
aa
bbb
���
both
ͨ��100%�޸İ�
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

bool Sort_dictionary(vector<string> v) {
	for (int i = 0;i < v.size() - 1;++i) {
		if (v[i] > v[i + 1])//ǰһ���ַ�����ȻС�ں�һ���ַ���
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
ͨ��100%
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








ͨ��30%
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

bool Sort_dictionary(vector<string> v) {
	for (int i = 0;i < v.size() - 1;++i) {
		if (v[i] > v[i + 1])//ǰһ���ַ�����ȻС�ں�һ���ַ���
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
