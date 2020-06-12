#pragma once
#include<string>
#define Chunk_Byte 64
typedef unsigned int uint;
class MD5
{
public:
	//位运算的函数,F,G,H,I
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
	//循环左移
	uint LeftShift(uint number, int shift_number)
	{
		/*
		number 1byte --->1100 1010
		number 左移一位  1001 0101
		(number<<1)|(number>>7) --->
		number<<1: 1001 0100
		number>>7: 0000 0001
					或运算
				   1001 0101
		*/
		return (number << shift_number) | 
			   (number >> (32 - shift_number));
	}
	MD5();
	//初始化
	void init();
	//重新设值
	void reset();
	//计算一个chunk的MD5值
	void md5(uint* chunk);

	//填充操作,进行填充，再计算MD5
	void fill_md5();

	//把一个整数数据转成对应的16进制字符串
	std::string change(uint n);
	std::string get_Sting_md5(const std::string& str);
	std::string get_File_md5(const char* filePath);
private:
	//循环移位的位数
	static int Left_Shift[64];
	//k[i]= (size_t)(abs(sin(i + 1)) * pow(2, 32));
	uint k[64];
	//数据块：64字节
	char chunk[Chunk_Byte];

	//填充相关变量:
	//				最后一块数据的字节
	uint Last_Byte;
	//				总字节数
	uint Sum_Byte;
	//MD5信息的A,B,C,D
	uint A;
	uint B;
	uint C;
	uint D;
};
