//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�
//����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��

class Solution {
public:
	int StrToInt(string str) {
		int result = 0;
		int len = sizeof(str);
		if (len <= 0) {
			return 0;
		}
		int i = 0;
		int flag = 1;
		if (str[i] == ' ') {
			i++;
		}
		if (str[i] == '+') {
			i++;
			flag = 1;
		}
		if (str[i] == '-') {
			i++;
			flag = -1;
		}
		while (str[i] != '\0') {
			if (str[i] >= '0'&&str[i] <= '9') {

				result = (str[i] - '0') + result * 10;
				i++;
			}
			else {
				result = 0;
				break;
			}
		}
		return result * flag;
	}
};
