#pragma once
#include<string>
#define Chunk_Byte 64
typedef unsigned int uint;
class MD5
{
public:
	//λ����ĺ���,F,G,H,I
	/*
	F(B,C,D) = (B & C) | ((~B) & D)
	F(x,y,z) = (x & y) | ((~x) & z)

	G(B,C,D) = (B & D) | ( C & (~D))
	G(x,y,z) = (x & z) | ( y & (~z))

	H(B,C,D) = B ^ C ^ D
	H(x,y,z) = x ^ y ^ z

	I(B,C,D) = C ^ (B | (~D))
	I(x,y,z) = y ^ (x | (~z))
	*/
	uint F(uint B, uint C, uint D)
	{
		return (B&C) | ((~B)&D);
	}
	uint G(uint B, uint C, uint D)
	{
		return (B&D) | (C&(~D));
	}
	uint H(uint B, uint C, uint D)
	{
		return B^C^D;
	}
	uint I(uint B, uint C, uint D)
	{
		return C ^ (B | (~D));
	}
	//ѭ������
	uint LeftShift(uint number, int shift_number)
	{
		/*
		number 1byte --->1100 1010
		number ����һλ  1001 0101
		(number<<1)|(number>>7) --->
		number<<1: 1001 0100
		number>>7: 0000 0001
					������
				   1001 0101
		*/
		return (number << shift_number) | 
			   (number >> (32 - shift_number));
	}
	MD5();
	//��ʼ��
	void init();
	//������ֵ
	void reset();
	//����һ��chunk��MD5ֵ
	void md5(uint* chunk);

	//������,������䣬�ټ���MD5
	void fill_md5();

	//��һ����������ת�ɶ�Ӧ��16�����ַ���
	std::string change(uint n);
	std::string get_Sting_md5(const std::string& str);
	std::string get_File_md5(const char* filePath);
private:
	//ѭ����λ��λ��
	static int Left_Shift[64];
	//k[i]= (size_t)(abs(sin(i + 1)) * pow(2, 32));
	uint k[64];
	//���ݿ飺64�ֽ�
	char chunk[Chunk_Byte];

	//�����ر���:
	//				���һ�����ݵ��ֽ�
	uint Last_Byte;
	//				���ֽ���
	uint Sum_Byte;
	//MD5��Ϣ��A,B,C,D
	uint A;
	uint B;
	uint C;
	uint D;
};
