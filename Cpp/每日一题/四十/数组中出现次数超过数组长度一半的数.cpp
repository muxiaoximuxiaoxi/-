/*�����г��ִ����������鳤��һ����� 
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬
���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int Maxnum=0;
        int len=numbers.size();
        if(len==0)
            return 0;
        int count=0;
        sort(numbers.begin(),numbers.end());//����
        int temp=numbers[0];
        for(int i=0;i<len;++i)
        {
            if(temp==numbers[i])
                ++count;
            else
            {
                Maxnum=count;
                if(Maxnum>(len/2))
                    return temp;
                count=1;
                temp=numbers[i];
            }
        }
        Maxnum=count;
        if(Maxnum>(len/2))
            return temp;
        return 0;
    }
};
