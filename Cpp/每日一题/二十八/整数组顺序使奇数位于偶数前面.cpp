/*��������˳��ʹ����λ��ż��ǰ��
����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣*/
class Solution {
public:
   void reOrderArray(vector<int> &array) {

        for (int i = 0; i < array.size();i++)
        {
            for (int j = array.size() - 1; j>i;j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //ǰż���潻��
                {
                    swap(array[j], array[j-1]);
                }
            }
        }
    }
    
};
