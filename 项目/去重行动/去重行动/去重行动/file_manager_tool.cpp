#include"file_manager_tool.h"



void file_manager_tool::scanner()
{
	cout << "������Ҫɨ����ļ��У�" << endl;
	std::string path;
	getline(cin, path);
	_fm.scanner_dir(path);
}
void file_manager_tool::delete_by_md5()
{
	cout << "������Ҫɾ�����ļ��е�MD5ֵ��" << endl;
	std::string md5;
	cin >> md5;
	_fm.delete_by_md5(md5);
}
void file_manager_tool::delete_by_name()
{
	cout << "������Ҫɾ�����ļ�����" << endl;
	std::string file_name;
	getline(cin, file_name);
	_fm.delete_by_name(file_name);
}
void file_manager_tool::delete_all_copy()
{
	_fm.delete_all_copy();
}
void file_manager_tool::delete_by_match()
{
	cout << "������Ҫɾ���ļ������������ݣ�" << endl;
	std::string md5;
	cin >> md5;
	_fm.delete_by_match(md5);
}
void file_manager_tool::show_all_file()
{
	_fm.show_all_file();
}
void file_manager_tool::show_copy()
{
	_fm.show_copy_list();
}