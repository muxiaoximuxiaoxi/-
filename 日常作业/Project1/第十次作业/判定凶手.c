//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�� 
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ� 
//A˵�������ҡ� 
//B˵����C�� 
//C˵����D�� 
//D˵��C�ں�˵ 
//��֪3����˵���滰��1����˵���Ǽٻ��� 
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡� 
#include<stdio.h>
#include<stdlib.h>
int main() {
	char killer;
	for (killer = 'A';killer <= 'D';killer++) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3) {
			printf("killer==%c", killer);
			printf("\n");
		}
	}
	system("pause");
}
