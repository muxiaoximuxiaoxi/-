/*
ϴ��
ϴ����������ʮ�ֳ�����������Ҫдһ������ģ��ϴ�ƵĹ��̡�
������Ҫϴ2n���ƣ����ϵ��������ǵ�1�ţ���2�ţ���3��һֱ����2n�š�
���ȣ����ǰ���2n���Ʒֳ����ѣ��������ŵ�1�ŵ���n�ţ��ϰ�ѣ���
�������ŵ�n + 1�ŵ���2n�ţ��°�ѣ������žͿ�ʼϴ�ƵĹ��̣�
�ȷ������ֵ����һ���ƣ��ٷ������ֵ����һ���ƣ����ŷ������ֵ�
�����ڶ����ƣ��ٷ������ֵĵ����ڶ����ƣ�ֱ�����������ֵĵ�һ���ơ�
���Ű��ƺϲ������Ϳ����ˡ� ������6���ƣ��ʼ�Ƶ�����
��1, 2, 3, 4, 5, 6�����ȷֳ����飬��������1, 2, 3����������4, 5, 6��
��ϴ�ƹ����а�˳�������6, 3, 5, 2, 4, 1�������������ٴκϳ�һ����֮��
�����ǰ��մ������µ�˳�������ƣ��ͱ��������1, 4, 2, 5, 3, 6�� 
���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
�������� :
��һ��һ����T(T �� 100)����ʾ��������������ÿ�����ݣ�
��һ��������n, k(1 �� n, k �� 100)��������һ����2n����a1, a2, ..., 
a2n(1 �� ai �� 1000000000)����ʾԭʼ������ϵ��µ����С�
������� :
����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�
ʾ��1
����
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1
���
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1
*/
//�����
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i < n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}

//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//int main() {
//	int T, n, k;
//	cin >> T;
//	while (--T) {
//		cin >> n >> k;
//		int m = 2 * n;
//		vector<int> v(m);
//		for (int i = 0;i < m;++i)
//			cin >> v[i];
//		vector<int> arr(m);
//		while (--k) {
//			//vector<int> arr(m);
//			for (int i = 0;i < n;++i) {
//				arr[2 * i] = v[i];
//				arr[2 * i + 1] = v[i + n];
//			}
//		}
//		for (int i = 0;i < m;++i) {
//
//			if (i == m - 1) {
//				cout << arr[i];
//				return 0;
//			}
//			cout << arr[i] << " ";
//		}
//		system("pause");
//	}
//}
//ջ��
//#include<iostream>
//#include<stack>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		/*vector<int> v;
//		for(int i=0;i<n;++i){
//			cin>>v[i];
//		}*/
//		stack<int> s;
//		for (int i = 0;i < n;++i) {
//			int m;
//			cin >> m;
//			s.push(m);
//		}
//		stack<int> s1;
//		stack<int> s2;
//		for (int i = 0;i < n / 2;++i) {
//			int m = s.top();
//			s1.push(m);
//		}
//		for (int i = n / 2;i < n;++i) {
//			int m = s.top();
//			s2.push(m);
//		}
//		int count = n;
//		for (int i = 0;i < n;++i) {
//			if (i % 2 == 0)
//				s1.pop();
//			else s2.pop();
//			if (count != 0)
//				cout << " ";
//		}
//	}
//	system("pause");
//}
//���а�
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		vector<int> v;
//		for (int i = 0;i < n;++i) {
//			cin >> v[i];
//		}
//		queue<int> q;
//		for (int i = 0;i < n;++i) {
//			q.push(v[i]);
//		}
//		queue<int> q1;
//		queue<int> q2;
//		int k;
//		for (int i = 0;i < n / 2;++i) {
//			k = (int)q.pop();
//			q2.push(k);
//		}
//		for (int j = n / 2;j < n;++j) {
//			k = (int)q.pop();
//			q2.push(k);
//		}
//		int count = n;
//		for (int i = 0;i < n;++i) {
//			if (i % 2 == 0)
//				q1.pop();
//			else
//				q2.pop();
//			if (count != 0)
//				cout << " ";
//		}
//	}
//}
