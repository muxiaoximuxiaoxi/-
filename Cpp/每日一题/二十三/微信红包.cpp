/*΢�ź��
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�
ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����
д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
��û�н���������һ�룬����0��
����������
[1, 2, 3, 2, 2], 5
���أ�2
*/
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		int count = 0;
		for (int i = 0;i < n;++i) {
			for (int j = i;j < n;++j) {
				if (gifts[i] == gifts[j])
					++count;
			}
			if (count > (n / 2)) {
				int result = gifts[i];
				return result;
			}
			count = 0;
		}
		return 0;
	}
};
