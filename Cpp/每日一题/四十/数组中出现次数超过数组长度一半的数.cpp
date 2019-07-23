/*数组中出现次数超过数组长度一半的数 
数组中有一个数字出现的次数超过数组长度的一半，
请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int Maxnum=0;
        int len=numbers.size();
        if(len==0)
            return 0;
        int count=0;
        sort(numbers.begin(),numbers.end());//排序
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
