#include"file_manager_tool.h"



void file_manager_tool::scanner()
{
	cout << "请输入要扫描的文件夹：" << endl;
	std::string path;
	getline(cin, path);
	_fm.scanner_dir(path);
}
void file_manager_tool::delete_by_md5()
{
	cout << "请输入要删除的文件夹的MD5值：" << endl;
	std::string md5;
	cin >> md5;
	_fm.delete_by_md5(md5);
}
void file_manager_tool::delete_by_name()
{
	cout << "请输入要删除的文件名：" << endl;
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
	cout << "请输入要删除文件所包含的内容：" << endl;
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