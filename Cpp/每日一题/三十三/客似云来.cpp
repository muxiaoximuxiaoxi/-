/* 
��������
NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼���������ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���

��������:
�������ݰ������顣
ÿ�����ݰ�����������from��to(1��from��to��80)���ֱ������ĵ�from��͵�to�졣


�������:
��Ӧÿһ�����룬�����from��to��Щ�������from��to���죩����Ҫ�����ٷ���͡�*/
// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int from, to;
	while (cin >> from >> to)
	{

		long long m1 = 0;
		long long m2 = 1;
		long long m;
		vector<long long> v;

		if (from == 1)
			v.push_back(1);
		for (int i = 2;i <= to;++i)
		{
			
			m = m1 + m2;
			m1 = m2;
			m2 = m;
			if (i >= from && i <= to)
				v.push_back(m);
		}
		long long count = 0;
		for (auto e : v)
			count += e;
		cout << count << endl;
	}
	return 0;
}
