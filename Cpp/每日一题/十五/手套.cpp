/*
����
�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡�
�����������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
������ɫ����n(1��n��13), ͬʱ������������Ϊn������left, right, �ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

����������
4, [0, 7, 1, 6], [1, 5, 0, 6]
���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)
*/
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int Left = 0;
		int Right = 0;
		int lmin = 30;
		int rmin = 30;
		int lnum = 0;
		int rnum = 0;
		int count = 0;
		int sum = 0;
		for (int i = 0;i < n;++i) {
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			else {
				lnum = lnum + left[i];
				if (lmin > left[i] && left[i] != 0)
					lmin = left[i];
				rnum = rnum + right[i];
				if (rmin > right[i] && right[i] != 0)
					rmin = right[i];
			}
		}
		if (lnum < rnum) {

			Left = lnum - (lmin - 1) + 1;
			
			Right = sum;
		}
		else {

			Right = rnum - (rmin - 1) + 1;
			Left = sum;
		}
		count = Left + Right;
		return count;
	}
};
