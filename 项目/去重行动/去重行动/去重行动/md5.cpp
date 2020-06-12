#include "md5.h"
#include<math.h>
#include<iostream>
#include<fstream>

//static成员初始化
int MD5::Left_Shift[64]= { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

MD5::MD5()
{
	init();
}
void MD5::init()
{
	//初始化k[i]
	//K[i] = floor(2^(32) * abs(sin(i + 1)))因为此处i从0开始，所以需要sin(i + 1) floor是取整的意思
	for (int i = 0;i < 64;++i)
	{
		k[i]=static_cast<uint>(abs(sin(i + 1.0))*pow(2.0, 32));
	}
	reset();
}
//重新设值
void MD5::reset()
{
	//初始化A,B,C,D
	A = 0x67452301;
	B = 0xefcdab89;
	C = 0x98badcfe;
	D = 0x10325476;
	//初始化chunk
	memset(chunk, 0, Chunk_Byte);
	Last_Byte = Sum_Byte = 0;
}

//计算一个chunk的MD5值
void MD5::md5(uint* chunk)
{
	int a = A;
	int b = B;
	int c = C;
	int d = D;
	int f, g;
	//4byte是一个处理单元，共执行64次
	for (int i = 0;i < 64;++i)
	{
		//位运算，F,G,H,I
		/*
			if (0 <= i < 16) g = i;
			if (16 <= i < 32) g = (5 * i + 1) % 16;
			if (32 <= i < 48) g = (3 * i + 5) % 16;
			if(48 <= i < 63) g = (7 * i) % 16;
		*/
		//0~15:F 
		if (0 <= i && i <= 15)
		{
			f = F(b, c, d);
			g = i;
		}
		//16~31:G
		else if (16 <= i && i <= 31)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		//32~47:H
		else if (32 <= i && i <= 47)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		//48~63:I
		else
		{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		//更新a,b,c,d，加法+循环左移
		int ta = a;
		int tb = b;
		int tc = c;
		int td = d;
		a = td;
		b = b + LeftShift(a + f + chunk[g] + k[i], Left_Shift[i]);
		c = tb;
		d = tc;
	}
	//更新A,B,C,D
	A += a;
	B += b;
	C += c;
	D += d;
}
//填充操作
void MD5::fill_md5()
{
	//填充冗余信息：第一位填1，其余填0
	//任何情况下，都至少填充一个字节的冗余信息
	//获取第一个要填充的位置
	char *p = chunk + Last_Byte;
	//首先填充1 byte 的冗余信息：1000 0000  
	//0x80(16进制)==128(10进制)
	*p++= 0x80;
	//剩余字节的位置
	int Surplus_Byte = Chunk_Byte - Last_Byte - 1;

	//如果剩余字节不够8字节，不能填充长度信息
	//应该先处理这块数据，然后再去构建一个新的数据块，前440位填0，最后的64位填长度xinx
	if (Surplus_Byte < 8)
	{
		//剩余位全部填0
		memset(p, 0, Surplus_Byte);
		md5((uint*)chunk);
		//构建一个新的chunk
		memset(chunk, 0, Chunk_Byte);
	}
	else
	{
		//剩余位全部补0
		memset(p, 0, Surplus_Byte);
	}
	//最终在最后一块数据的最后64位填充原始信息
	unsigned long long Sum_Bits = Sum_Byte;
	Sum_Bits *= 8;
	((unsigned long long *)chunk)[7] = Sum_Bits;
	md5((uint*)chunk);
}
std::string MD5::change(uint n)
{
	static std::string arr = "0123456789abcdef";
	std::string ret;
	//获取每个字节数据
	for (int i = 0;i < 4;++i)
	{
		//获取一个字节的数据
		/*
		将12345678的高位通过右移8位，然后通过和0xff(1111 1111)相与
		*/
		int cur = n >> (i * 8) & 0xff;
		//数据转成16进制字符
		std::string cur_str;
		//÷16获取高位，%16获取低位 在字节内部是没有逆序的
		cur_str += arr[cur / 16];
		cur_str += arr[cur % 16];

		//在字节之间是逆序的
		ret += cur_str;
	}
	return ret;
}
std::string MD5::get_Sting_md5(const std::string& str)
{
	if (str.empty())
	{
		return change(A).append(change(B)).append(change(C)).append(change(D));
	}
	Sum_Byte = str.size();
	uint chunk_Num = Sum_Byte / Chunk_Byte;
	const char* str_Ptr = str.c_str();
	for (int i = 0;i < (int)chunk_Num;++i)
	{
		memcpy(chunk, str_Ptr + i * Chunk_Byte, Chunk_Byte);
		md5((uint*)chunk);
	}
	//计算最后一个数据：需要填充
	Last_Byte = Sum_Byte % Chunk_Byte;
	memcpy(chunk, str_Ptr + chunk_Num * Chunk_Byte, Last_Byte);
	fill_md5();
	return change(A).append(change(B)).append(change(C)).append(change(D));
}
/*seekg 在输入序列中设置位置
	istream& seekg (streampos pos);pos你想获取位置的指针
	istream& seekg (streamoff off, ios_base::seekdir way);
	off  起始的偏移量，可正可负
	way  基地址只能是：
		ios：：beg：表示输入流的开始位置
		ios：：cur：表示输入流的当前位置
		ios：：end：表示输入流的结束位置

	tellg获取输入序列中的位置
	streampos tellg();

	gcount  获取字符计数
	返回最后一次对该对象执行的无格式输入操作提取的字符数。
	修改此函数返回值的非格式化输入操作有:get、getline、ignore、peek、read、readsome、putback和unget。
	但是请注意，peek、putback和unget实际上并没有提取任何字符，因此gcount在调用任何字符后总是返回0。

	*/
std::string MD5::get_File_md5(const char* filePath)
{
	std::ifstream fin(filePath, std::ifstream::binary);
	//std::fstream fin(filePath, std::ifstream::binary | std::ifstream::app);
	//std::fstream fin(filePath);
	if (!fin.is_open())
	{
		std::cout << filePath;
		perror("file open failed!!!");
		return "";
	}
	while (!fin.eof())
	{
		fin.read(chunk, Chunk_Byte);
		//是否读取到64个字节的内容
		if (Chunk_Byte != fin.gcount())
		{
			//说明是最后一块数据
			break;
		}
		Sum_Byte += Chunk_Byte;
		md5((uint*)chunk);
	}
	Last_Byte = fin.gcount();
	//gcount:可以调用多次，始终返回最近一次读入的字节数
	Sum_Byte += Last_Byte;
	fill_md5();
	return change(A).append(change(B)).append(change(C)).append(change(D));
}
