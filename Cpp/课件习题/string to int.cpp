//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
//但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0。

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
