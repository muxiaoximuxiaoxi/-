/*�ֽ����� 

��ν���ӷֽ⣬���ǰѸ�����������a���ֽ�����ɸ������ĳ˻���
�� a = a1 �� a2 �� a3 �� ... �� an,���� 1 < a1 �� a2 �� a3 
�� ... �� an������a1��a2��...��an��Ϊ������ �ȸ���һ������a��
������ֽ������ӡ�

��������:
��������������ݣ�ÿ�����ݰ���һ��������a��2��a��1000000����

�������:
��Ӧÿ�����ݣ��ԡ�a = a1 * a2 * a3...������ʽ�����ʽ�ֽ��Ľ����
ʾ��1
����
10
18
���
10 = 2 * 5
18 = 2 * 3 * 3*/
// write your code here cpp
#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        cout<<n<<" =";
        int i;
        for( i=2;i<sqrt(n);++i){
            while(n!=i){
                if(n%i==0){
                    cout<<" "<<i<<" *";
                    n/=i;
                }
                else 
                    break;
            }
        }
        cout<<" "<<n<<endl;
    }
    return 0;
}

