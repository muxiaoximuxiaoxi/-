/* 
������������� 
��һ���������������������㰴�����һ��һ��ش����������α�ţ�
�������Ϊ1���������������a��b�������һ���㷨�����a��b���
����������ȵı�š�
��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�
ע�������㱾��Ҳ����Ϊ�������ȡ�
����������
2��3
���أ�1
*/
class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        int child_A=a;
        int child_B=b;
        
        while(child_A!=child_B){
            if(child_A>child_B)
                child_A=(child_A)/2;
            else 
                child_B=(child_B)/2;
        }
        return child_A;
    }
};

