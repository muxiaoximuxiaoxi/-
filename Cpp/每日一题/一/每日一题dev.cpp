//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<algorithm>
//ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.
////����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.
////ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
//using namespace std;
//int main() {
//	int n = 0;
//	cin >> n;
//	int sum = 0;
//	vector<int> v(n * 3);
//	for (int i = 0;i < n * 3;++i) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	for (int i = n;i <= (n * 3) - 2;i += 2) {
//		sum += v[i];
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}

//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou����
//��ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	string::iterator it = str2.begin();
	while (it != str2.end()) {
		for (int i = 0;i < str1.size();++i) {
			if (str1[i] == *it) {
				str1.erase(i, 1);
			}
		}
		++it;
	}
	cout << str1 << endl;
	system("pause");
}












//int main() {
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	string::iterator it = str2.begin();
//	while (it != str2.end())
//	{
//		for (int i = 0; i < str1.size(); i++)
//		{
//			if (str1[i] == *it)
//			{
//				str1.erase(i, 1);
//			}
//		}
//		it++;
//	}
//	cout << str1 << endl;
//	system("pause");
//}

