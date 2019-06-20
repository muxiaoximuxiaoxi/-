/*
密码等级强度 
密码按如下规则进行计分，
并根据不同的得分为密码进行安全等级划分。
       一、密码长度:
       5 分: 小于等于4 个字符
       10 分: 5 到7 字符
       25 分: 大于等于8 个字符
       二、字母:
       0 分: 没有字母
       10 分: 全都是小（大）写字母
       20 分: 大小写混合字母
       三、数字:
       0 分: 没有数字
       10 分: 1 个数字
       20 分: 大于1 个数字
       四、符号:
       0 分: 没有符号
       10 分: 1 个符号
       25 分: 大于1 个符号
       五、奖励:
       2 分: 字母和数字
       3 分: 字母、数字和符号
       5 分: 大小写字母、数字和符号
       最后的评分标准:
       >= 90: 非常安全
       >= 80: 安全（Secure）
       >= 70: 非常强
       >= 60: 强（Strong）
       >= 50: 一般（Average）
       >= 25: 弱（Weak）
       >= 0:  非常弱
对应输出为：
  VERY_WEAK,
   WEAK,   
   AVERAGE,    
   STRONG,     
   VERY_STRONG,
   SECURE,     
   VERY_SECURE 
       请根据输入的密码字符串，进行安全评定。

       注：

       字母：a-z, A-Z

       数字：-9

       符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII 
	   Table查看)

       !"#$%&'()*+,-./     (ASCII码：x21~0x2F)

       :;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)

       [\]^_`              (ASCII码：x5B~0x60)

  {|}~                (ASCII码：x7B~0x7E)

接口描述：
 Input Param 
      String pPasswordStr:    密码，以字符串方式存放。
 Return Value
   根据规则评定的安全等级。
 public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
 {
     在这里实现功能
  return null;
 }
输入描述:
输入一个string的密码
输出描述:
输出密码等级
示例1
输入
38$@NoNoNo
输出
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
        //密码长度得分
        if(password.size()<=4){
            score+=5;
        }else if(password.size()>=8){
            score+=25;
        }else{
            score+=10;
        }
        //字母、数字、符号统计
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
        //字母得分
        if((alpha==1&&Alpha==0) || (alpha==0&&Alpha==1)){
                score+=10;
        }else if(alpha==1 && Alpha==1){
                score+=20;
        }
        //数字得分
        if(number_count>1){
            score+=20;
        }else if(number){
            score+=10;
        }
        //符号得分
        if(ch_count>1){
            score+=25;
        }else if(ch){
            score+=10;
        }
        //奖励得分
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
