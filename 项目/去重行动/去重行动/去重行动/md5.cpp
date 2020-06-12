#include "md5.h"
#include<math.h>
#include<iostream>
#include<fstream>

//static��Ա��ʼ��
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
	//��ʼ��k[i]
	//K[i] = floor(2^(32) * abs(sin(i + 1)))��Ϊ�˴�i��0��ʼ��������Ҫsin(i + 1) floor��ȡ������˼
	for (int i = 0;i < 64;++i)
	{
		k[i]=static_cast<uint>(abs(sin(i + 1.0))*pow(2.0, 32));
	}
	reset();
}
//������ֵ
void MD5::reset()
{
	//��ʼ��A,B,C,D
	A = 0x67452301;
	B = 0xefcdab89;
	C = 0x98badcfe;
	D = 0x10325476;
	//��ʼ��chunk
	memset(chunk, 0, Chunk_Byte);
	Last_Byte = Sum_Byte = 0;
}

//����һ��chunk��MD5ֵ
void MD5::md5(uint* chunk)
{
	int a = A;
	int b = B;
	int c = C;
	int d = D;
	int f, g;
	//4byte��һ������Ԫ����ִ��64��
	for (int i = 0;i < 64;++i)
	{
		//λ���㣬F,G,H,I
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
		//����a,b,c,d���ӷ�+ѭ������
		int ta = a;
		int tb = b;
		int tc = c;
		int td = d;
		a = td;
		b = b + LeftShift(a + f + chunk[g] + k[i], Left_Shift[i]);
		c = tb;
		d = tc;
	}
	//����A,B,C,D
	A += a;
	B += b;
	C += c;
	D += d;
}
//������
void MD5::fill_md5()
{
	//���������Ϣ����һλ��1��������0
	//�κ�����£����������һ���ֽڵ�������Ϣ
	//��ȡ��һ��Ҫ����λ��
	char *p = chunk + Last_Byte;
	//�������1 byte ��������Ϣ��1000 0000  
	//0x80(16����)==128(10����)
	*p++= 0x80;
	//ʣ���ֽڵ�λ��
	int Surplus_Byte = Chunk_Byte - Last_Byte - 1;

	//���ʣ���ֽڲ���8�ֽڣ�������䳤����Ϣ
	//Ӧ���ȴ���������ݣ�Ȼ����ȥ����һ���µ����ݿ飬ǰ440λ��0������64λ���xinx
	if (Surplus_Byte < 8)
	{
		//ʣ��λȫ����0
		memset(p, 0, Surplus_Byte);
		md5((uint*)chunk);
		//����һ���µ�chunk
		memset(chunk, 0, Chunk_Byte);
	}
	else
	{
		//ʣ��λȫ����0
		memset(p, 0, Surplus_Byte);
	}
	//���������һ�����ݵ����64λ���ԭʼ��Ϣ
	unsigned long long Sum_Bits = Sum_Byte;
	Sum_Bits *= 8;
	((unsigned long long *)chunk)[7] = Sum_Bits;
	md5((uint*)chunk);
}
std::string MD5::change(uint n)
{
	static std::string arr = "0123456789abcdef";
	std::string ret;
	//��ȡÿ���ֽ�����
	for (int i = 0;i < 4;++i)
	{
		//��ȡһ���ֽڵ�����
		/*
		��12345678�ĸ�λͨ������8λ��Ȼ��ͨ����0xff(1111 1111)����
		*/
		int cur = n >> (i * 8) & 0xff;
		//����ת��16�����ַ�
		std::string cur_str;
		//��16��ȡ��λ��%16��ȡ��λ ���ֽ��ڲ���û�������
		cur_str += arr[cur / 16];
		cur_str += arr[cur % 16];

		//���ֽ�֮���������
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
	//�������һ�����ݣ���Ҫ���
	Last_Byte = Sum_Byte % Chunk_Byte;
	memcpy(chunk, str_Ptr + chunk_Num * Chunk_Byte, Last_Byte);
	fill_md5();
	return change(A).append(change(B)).append(change(C)).append(change(D));
}
/*seekg ����������������λ��
	istream& seekg (streampos pos);pos�����ȡλ�õ�ָ��
	istream& seekg (streamoff off, ios_base::seekdir way);
	off  ��ʼ��ƫ�����������ɸ�
	way  ����ַֻ���ǣ�
		ios����beg����ʾ�������Ŀ�ʼλ��
		ios����cur����ʾ�������ĵ�ǰλ��
		ios����end����ʾ�������Ľ���λ��

	tellg��ȡ���������е�λ��
	streampos tellg();

	gcount  ��ȡ�ַ�����
	�������һ�ζԸö���ִ�е��޸�ʽ���������ȡ���ַ�����
	�޸Ĵ˺�������ֵ�ķǸ�ʽ�����������:get��getline��ignore��peek��read��readsome��putback��unget��
	������ע�⣬peek��putback��ungetʵ���ϲ�û����ȡ�κ��ַ������gcount�ڵ����κ��ַ������Ƿ���0��

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
		//�Ƿ��ȡ��64���ֽڵ�����
		if (Chunk_Byte != fin.gcount())
		{
			//˵�������һ������
			break;
		}
		Sum_Byte += Chunk_Byte;
		md5((uint*)chunk);
	}
	Last_Byte = fin.gcount();
	//gcount:���Ե��ö�Σ�ʼ�շ������һ�ζ�����ֽ���
	Sum_Byte += Last_Byte;
	fill_md5();
	return change(A).append(change(B)).append(change(C)).append(change(D));
}
