/*
����ȼ�ǿ�� 
���밴���¹�����мƷ֣�
�����ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
       һ�����볤��:
       5 ��: С�ڵ���4 ���ַ�
       10 ��: 5 ��7 �ַ�
       25 ��: ���ڵ���8 ���ַ�
       ������ĸ:
       0 ��: û����ĸ
       10 ��: ȫ����С����д��ĸ
       20 ��: ��Сд�����ĸ
       ��������:
       0 ��: û������
       10 ��: 1 ������
       20 ��: ����1 ������
       �ġ�����:
       0 ��: û�з���
       10 ��: 1 ������
       25 ��: ����1 ������
       �塢����:
       2 ��: ��ĸ������
       3 ��: ��ĸ�����ֺͷ���
       5 ��: ��Сд��ĸ�����ֺͷ���
       �������ֱ�׼:
       >= 90: �ǳ���ȫ
       >= 80: ��ȫ��Secure��
       >= 70: �ǳ�ǿ
       >= 60: ǿ��Strong��
       >= 50: һ�㣨Average��
       >= 25: ����Weak��
       >= 0:  �ǳ���
��Ӧ���Ϊ��
  VERY_WEAK,
   WEAK,   
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 
       ���������������ַ��������а�ȫ������

       ע��

       ��ĸ��a-z, A-Z

       ���֣�-9

       ���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII 
	   Table�鿴)

       !"#$%&'()*+,-./     (ASCII�룺x21~0x2F)

       :;<=>?@             (ASCII<=><=><=><=><=>�룺x3A~0x40)

       [\]^_`              (ASCII�룺x5B~0x60)

  {|}~                (ASCII�룺x7B~0x7E)

�ӿ�������
 Input Param 
      String pPasswordStr:    ���룬���ַ�����ʽ��š�
 Return Value
   ���ݹ��������İ�ȫ�ȼ���
 public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
 {
     ������ʵ�ֹ���
  return null;
 }
��������:
����һ��string������
�������:
�������ȼ�
ʾ��1
����
38$@NoNoNo
���
VERY_SECURE
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string password;
    while(getline(cin,password))
    {
        int score=0;
        //���볤�ȵ÷�
        if(password.size()<=4){
            score+=5;
        }else if(password.size()>=8){
            score+=25;
        }else{
            score+=10;
        }
        //��ĸ�����֡�����ͳ��
        int Alpha=0,alpha=0,number=0,number_count=0,ch=0,ch_count=0;
        for(int i=0;i<password.size();i++)
        {
            if(password[i]>='a' && password[i]<='z'){
                alpha=1;
            }else if(password[i]>='A' && password[i]<='Z'){
                Alpha=1;
            }else if(isdigit(password[i])){
                number=1;
                number_count++;
            }else{
                ch=1;
                ch_count++;
            }                  
        }
        //��ĸ�÷�
        if((alpha==1&&Alpha==0) || (alpha==0&&Alpha==1)){
                score+=10;
        }else if(alpha==1 && Alpha==1){
                score+=20;
        }
        //���ֵ÷�
        if(number_count>1){
            score+=20;
        }else if(number){
            score+=10;
        }
        //���ŵ÷�
        if(ch_count>1){
            score+=25;
        }else if(ch){
            score+=10;
        }
        //�����÷�
        if(Alpha && alpha && number && ch){
            score+=5;
        }else if((Alpha||alpha)&& number && ch){
            score+=3;
        }else if((Alpha||alpha)&& number){
            score+=2;
        }
        if(score>=90){
            cout<<"VERY_SECURE"<<endl;
        }else if(score>=80){
            cout<<"SECURE"<<endl;
        }else if(score>=70){
            cout<<"VERY_STRONG"<<endl;
        }else if(score>=60){
            cout<<"STRONG"<<endl;
        }else if(score>=50){
            cout<<"AVERAGE"<<endl;
        }else if(score>=25){
            cout<<"WEAK"<<endl;
        }else{
            cout<<"VERY_WEAK"<<endl;
        }
    }
    return 0;
}
