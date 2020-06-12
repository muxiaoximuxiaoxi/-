MD5.h
#define CHUNK_BYTE 64
typedef unsigned int uint32;
class MD5
{
	public:
	/*
	F(B,C,D) = (B & C) | ((~B) & D)
	G(B,C,D) = (B & D) | ( C & (~D))
	H(B,C,D) = B ^ C ^ D
	I(B,C,D) = C ^ (B | (~D))
	*/
	//位运算的函数，F，G，H，I
	uint32 F(uint32 b,uint32 c,uint32 d)
	{
		return (b&c)|((~b)&d);
	}
	
	uint32 G(uint32 b,uint32 c,uint32 d)
	{
		return (b&d)|(c&(~d));
	}
	
	uint32 H(uint32 b,uint32 c,uint32 d)
	{
		return b^c^d;
	}
	
	uint32 I(uint32 b,uint32 c,uint32 d)
	{
		return c^(b|(~d));
	}
	//循环左移
	uint32 leftShift(uint32 number,int shfitnumber)
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
		return (number<<shfitnumber)|(number>>(32-shfitnumber));
	}
	void init();
	
	//重新设值
	void reset();
	
	//计算一个chunk的MD5值
	void calMD5(uint32* chunk);//int型的数组
	
	//填充操作
	void calFinalMD5();
	
	//把一个整数数据转成对应的16进制字符串
	std::string changeHex(uint32 n);
	std::string getStringMD5(const std::string& str);
	std::string getFileMD5(const char* filePath);
	private:
	//循环移位的位数
	static int _leftShift[64];
	//k[i]的算法,k[i] = (size_t)(abs(sin(i + 1)) * pow(2, 32));
	uint32 _k[64];
	//数据块：64字节
	char _chunk[CHUNK_BYTE];
	//填充相关变量
	
	//最后一块数据的字节数
	uint32 _lastByte;
	//总字节数
	uint32 _totalByte;
	
	//MD5信息A,B,C,D
	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};










#include<iostream>
#include"MD5.h"
#include<math.h>
#include<fstream>
MD5::MD5()
{
	init();
}
//初始化成员
static MD5::_leftShift[64]={ 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

	void MD5::init()
	{
		//初始化k[i]
		//K[i] = floor(2^(32) * abs(sin(i + 1)))因为此处i从0开始，所以需要sin(i + 1)
		for(int i=0;i<64;++i)
		{
			_k[i]=static_cast<uint32>(abs(sin(i+1))*pow(2,32));
		}
	}
	
	//重新设值
	void MD5::reset()
	{
		//初始化A,B,C,D
		_a = 0x67452301;
		_b = 0xefcdab89;
		_c = 0x98badcfe;
		_d = 0x10325476;
		
		//初始化chunk
		memset(_chunk,0,CHUNK_BYTE);
		_lastByte=_totalByte=0;
	}
	
	//计算一个chunk的MD5值
	void calMD5(uint32* chunk)//int型的数组
	{
		int a=_a,b=_b,c=_c,d=_d;
		int f,g;
		//4byte为一个处理单元
		//共执行64次操作
		for(int i=0;i<64;++i)
		{
			//位运算，F,G,H,I
			//0~15:F 
			/*
			if (0 <= i < 16) g = i;
			if (16 <= i < 32) g = (5 * i + 1) % 16;
			if (32 <= i < 48) g = (3 * i + 5) % 16;
			if(48 <= i < 63) g = (7 * i) % 16;
			*/
			if(0<=i&&i<=15)
			{
				f=F(b,c,d);
				g=i;
			}
			//16~31:G
			else if (16<=i&&i<=31)
			{
				f=G(b,c,d);
				g=(5*i+1)%16;
			}
			//32~47:H 
			else if(32<=i&&i<=47)
			{
				f=H(b,c,d);
				g=(3*i+5)%16;
			}
			//48~63:I 
			else
			{
				f=I(b,c,d);
				g=(7*i)%16;
			}
			
			//更新，加法+循环左移
			int tmp=d;
			d=c;
			c=b;
			b=b+leftShift(a+f+chunk[g]+_k[i],_leftShift[i]);
			a=tmp;
		}
		//更新A,B,C,D
		_a+=a;
		_b+=b;
		_c+=c;
		_d+=d;
	}
	//填充操作
	void MD5::calFinalMD5()
	{
		//填充冗余信息:第一位填1，其余填0
		//任何情况下，都至少填充一个Byte的冗余信息
		//获取第一个待填充的位置
		char* p=_chunk+_lastByte;
		
		//首先填充一个字节的冗余信息:1000 0000
		*p++ =0x80;
		
		int remainByte=CHUNK_BYTE-_lastByte;
		//如果剩余字节不够8byte->64byte，不能填充长度信息
		//先处理一块数据，再去构建一个新的数据块，前440位填0，最后64位填长度信息
		if(remainByte<8)
		{
			//剩余位全部补0
			meset(p,0,remainByte);
			calMD5((uint32*)_chunk);
			//构建一个新的数据块
			meset(_chunk,0,CHUNK_BYTE);
		}
		else
		{
			//剩余位全部补0
			meset(p,0,remainByte);
			
		}
		//最终的最后一块数据，给最后64位填充原始信息
		unsigned long long totalBits=_totalByte;
		totalBits *=8;
		((unsigned long long*)_chunk)[7]=totalBits;
		calMD5((uint32*)_chunk);
		
	}
	std::string MD5::changeHex(uint32 n)
	{
		std::string strMap="0123456789abcdef";
		std::string ret;
		//获取每一个字节数据
		for(int i=0;i<4;++i)
		{
			//获取一个字节的数据
			int curByte = n>>(i*8)&0xff;
			//数据转成16进制字符
			std::string curRet;
			//÷16获取高位 %16获取低位 字节内不逆序
			curRet += strMap[curByte/16];
			curRet += strMap[curByte%16];
			//字节间逆序
			ret+=curRet;
		}
		return ret;
	}
	std::string MD5::getStringMD5(const std::string& str)
	{
		if(str.empty())
		{
			return changeHex(_a).append(changeHex(_b)).append(changeHex(_c)).append(changeHex(_d));
		}
		_totlByte =str.size();
		uint32 chunkNum=_totalByte/CHUNK_BYTE;
		const char* strPtr =str.c_str();
		for(int i=0;i<chunkNum;++i)
		{
			memcpy(_chunk,strPtr+i*CHUNK_BYTE,CHUNK_BYTE)；
			calMD5((uint32*)_chunk);
		}
		//计算最后一个数据：需要填充
		_lastByte = _totalByte%CHUNK_BYTE;
		memcpy(_chunk,strPtr+chunkNum*CHUNK_BYTE,_lastByte);
		calFinalMD5();
		return changeHex(_a).append(changeHex(_b)).append(changeHex(_c)).append(changeHex(_d));
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
	
	gcount  获取字符计数
	返回最后一次对该对象执行的无格式输入操作提取的字符数。
	修改此函数返回值的非格式化输入操作有:get、getline、ignore、peek、read、readsome、putback和unget。
	但是请注意，peek、putback和unget实际上并没有提取任何字符，因此gcount在调用任何字符后总是返回0。
	
	streampos tellg();
	*/
	std::string MD5::getFileMD5(const char* filePath) 
	{
		std::fstream fin(filePath,std::ifstream::binary);
		if(!fin.is_open)
		{
			std::cout<<filePath;
			perror("file open failed!");
			return "";
		}
		while(!fin.eof())
		{
			/*
			//1.全部读进来：seekg,tellg获取文件大小，空间换时间，需要一个很大的辅助空间，主要针对小文件
			fin.seekg(0,fin.end)；
			uint32 length = fin.tellg();
			fin.seekg(0,fin.beg);
			char* tatalData = new char [length];
			fin.read(totalData,length);
			*/
			//2.每次只读取一个数据  时间换空间，时间效率低，主要针对大文件
			fin.read(_chunk,CHUNK_BYTE);
			//是否读取到64个字节的内容
			if(CHUNK_BYTE != fin.gcount())
			{
				//说明为最后一块数据
				break;
			}
			_totalByte+=CHUNK_BYTE;
			calMD5((uint32*)_chunk);
		}
		//gcount:可以调用多次，始终返回最近一次读入的字节数
		_lastByte=fin.gcount();
		_totalByte+=_lastByte;
		calFinalMD5();
		return changeHex(_a).append(changeHex(_b)).append(changeHex(_c)).append(changeHex(_d));
	}
	
	