#pragma once
#include<string>
#include<unordered_set>
#include<unordered_map>
#include"md5.h"
#include<utility>
class file_manager
{
public:
	void get_md5_to_file();
	void scanner_dir(const std::string& path);
	void get_copy_list();
	//所有的删除，保证一个文件不存在副本
	void delete_by_name(const std::string& name);
	void delete_by_md5(const std::string& md5);
	void delete_all_copy();
	//删除所有包含'match'的文件
	void delete_by_match(const std::string& match);

	void show_copy_list();
	void show_all_file();
private:
	std::unordered_set<std::string> _file;
	//md5映射文件
	std::unordered_multimap<std::string, std::string> _md5_to_file;
	//文件映射md5
	std::unordered_map<std::string, std::string> _file_to_md5;
	MD5 _md5;
};