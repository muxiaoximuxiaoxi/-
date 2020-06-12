#include"md5.h"
#include<iostream>
#include<stdlib.h>
#include"file.h"
#include"file_manager.h"
#include"file_manager_tool.h"
using std::endl;
using std::cout;

void test_change()
{
	MD5 m;
	uint n = 0x12345678;
	cout << m.change(n) << endl;
	/*std::string s = m.change(n);
	for (auto a : s)
	{
		cout << a;
		++a;
	}
	cout << endl;*/
}

void test_get_Sting_md5()
{
	MD5 m;
	std::string s = "123456789abcdefgh";
	cout << m.get_Sting_md5(s) << endl;
	std::string ss = "123456789abcdefgi";
	cout << m.get_Sting_md5(ss) << endl;
}
void test_get_File_md5()
{
	MD5 m;
	const char* f1 = "test_a.txt";
	const char* f2 = "test_b.txt";
	cout << m.get_File_md5(f1) << endl;
	//需要重置一下
	m.reset();
	cout << m.get_File_md5(f2) << endl;
}
void test_search()
{
	std::string path;
	cout << "please input search dir:" << endl;
	getline(std::cin, path);
	std::unordered_set<std::string> sum_file;
	search_dir(path, sum_file);
	for (const auto & a : sum_file)
	{
		cout << a << endl;
	}
}
void test_file_manage()
{
	file_manager fm;
	std::string path = "E:\\去重行动测试文件";
	//std::string path = "E:\\去重行动测试文件 - 副本";
	fm.scanner_dir(path);
}
void test_delete_by_md5()
{
	file_manager fm;
	std::string path = "E:\\去重行动测试文件";
	fm.scanner_dir(path);
	fm.delete_by_md5("38791e3e96967d228dce7a359e870611");
	//fm.scanner_dir(path);
}
void test_delete_by_name()
{
	file_manager fm;
	std::string path = "E:\\去重行动测试文件";
	fm.scanner_dir(path);
	fm.delete_by_name("20.doc");
}
void menu()
{
	cout << "***********************************************" << endl;
	cout << "1:scanner			2:show all		3:show copy" << endl;
	cout << "4:delete name		5:delete md5	6:delete all" << endl;
	cout << "7:delete matched	0:exit" << endl;
	cout << "***********************************************" << endl;
}
void test_tool()
{
	file_manager_tool fmt;
	int input;
	do
	{
		menu();
		std::string rubbish;
		cout << "请输入选项：";
		cin >> input;
		getline(cin, rubbish);
		switch (input)
		{
		case 1:
			fmt.scanner();
			break;
		case 2:
			fmt.show_all_file();
			break;
		case 3:
			fmt.show_copy();
			break;
		case 4:
			fmt.delete_by_name();
			break;
		case 5:
			fmt.delete_by_md5();
			break;
		case 6:
			fmt.delete_all_copy();
			break;
		case 7:
			fmt.delete_by_match();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);
}
int main()
{
	//test_change();
	//test_get_Sting_md5();
	//test_get_File_md5();
	//test_search();
	//test_file_manage();
	//test_delete_by_md5();
	//test_delete_by_name();
	test_tool();
	system("pause");
	return 0;
}