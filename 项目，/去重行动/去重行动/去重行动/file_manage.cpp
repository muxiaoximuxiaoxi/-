#include"file_manager.h"
#include"file.h"
#include<utility>
void file_manager::scanner_dir(const std::string& path)
{
	//清理容器
	_file.clear();
	search_dir(path, _file);
	//std::cout << "all file" << std::endl;
	show_all_file();
	get_md5_to_file();
	show_copy_list();

	std::cout << "Only duplicate files" << std::endl;
	get_copy_list();
	//std::cout << "copy list" << std::endl;
	show_copy_list();
	show_all_file();
}
void file_manager::get_md5_to_file()
{
	_md5_to_file.clear();
	for (const auto &a : _file)
	{
		//计算新文件前重置
		_md5.reset();
		//string 转换成 char *
		//如果要将string直接转换成const char *类型。string有2个函数可以运用。
		//一个是.c_str()，一个是data成员函数。
		_md5_to_file.insert(make_pair(_md5.get_File_md5(a.c_str()), a));

	}
}
//只保留内容重复文件的结果
void file_manager::get_copy_list()
{
	_file_to_md5.clear();
	//不要用范围for,涉及删除操作
	auto it = _md5_to_file.begin();
	while (it != _md5_to_file.end())
	{
		//查找每个MD5对应所有文件的结果
		if (_md5_to_file.count(it->first) > 1)
		{
			//equal_range 返回值：pair<beginIt,endIt>:[beginIt,endIt)--->迭代器遍历时连续
			auto pair_it = _md5_to_file.equal_range(it->first);
			auto begin = pair_it.first;
			while (begin != pair_it.second)
			{
				//只存放重复文件的映射关系
				_file_to_md5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//下一个不同的MD5的起始位置
			it = pair_it.second;
		}
		else
		{
			//先删除，再更新
			_file.erase(it->second);
			//erase的返回值，被删除元素的下一个位置
			it = _md5_to_file.erase(it);
		}
	}
}
//所有的删除，保证一个文件不存在副本
void file_manager::delete_by_name(const std::string& name)
{
	if (_file_to_md5.count(name) == 0)
	{
		std::cout << name << "\tnot exist!!!" << std::endl;
		return;
	}
	std::string cur_md5 = _file_to_md5[name];
	std::cout << name << "--->" << _md5_to_file.count(cur_md5) << std::endl;
	auto pair_it = _md5_to_file.equal_range(cur_md5);
	auto cur_it = pair_it.first;
	int count = 0;
	while (cur_it != pair_it.second)
	{
		if (cur_it->second != name)
		{
			_file.erase(cur_it->second);
			_file_to_md5.erase(cur_it->second);
			delete_file(cur_it->second.c_str());
			++count;
		}
		++cur_it;
	}
	cur_it = pair_it.first;
	while (cur_it != pair_it.second)
	{
		if (cur_it->second != name)
		{
			//key==md5
			_md5_to_file.erase(cur_it);
			pair_it = _md5_to_file.equal_range(cur_md5);
			cur_it = pair_it.first;
		}
		++cur_it;
	}
	std::cout << "delete files ：" << count << std::endl;
}
void file_manager::delete_by_md5(const std::string& md5)
{
	//md5映射file
	if (_md5_to_file.count(md5) == 0)
	{
		std::cout << md5 << "not exist!!!" << std::endl;
		return;
	}
	//删除时需要保留一份，规定保留第一个文件
	auto pair_it = _md5_to_file.equal_range(md5);
	std::cout << "md5值：" << md5 << "---have---" << _md5_to_file.count(md5) << std::endl;
	auto cur_it = pair_it.first;
	++cur_it;
	int count = 0;
	while (cur_it != pair_it.second)
	{
		_file.erase(cur_it->second);
		_file_to_md5.erase(cur_it->second);
		//文件从磁盘中删除
		delete_file(cur_it->second.c_str());
		++count;
		++cur_it;
	}
	//更新一下MD5到file的映射
	cur_it = pair_it.first;
	++cur_it;
	//erase(first,last)----> 删除区间[first,last)
	_md5_to_file.erase(cur_it, pair_it.second);
	std::cout << "delete files number：" << count << std::endl;
}
//所有重复的文件只保留一个
void file_manager::delete_all_copy()
{
	std::unordered_set<std::string> md5_set;
	//找出所有的md5值
	for (const auto& a : _md5_to_file)
	{
		md5_set.insert(a.first);
	}
	for (const auto& b : md5_set)
	{
		delete_by_md5(b);
	}
}
//删除所有包含'match'的文件
void file_manager::delete_by_match(const std::string& match)
{
	std::unordered_set<std::string> all_file;
	//遍历所有文件
	for (const auto& a : _file)
	{
		if (a.find(match) != std::string::npos)
			all_file.insert(a);
	}
	for (const auto & b : all_file)
	{
		if (_file_to_md5.count(b) != 0)
			delete_by_name(b);
	}
}

void file_manager::show_copy_list()
{
	std::cout << "+++++++++++++++++++++++" << std::endl;
	std::cout << "show_copy_list" << std::endl;
	auto it = _md5_to_file.begin();
	int total = _md5_to_file.size();
	int count = 0;
	while (it != _md5_to_file.end())
	{
		//md5值相同的显示在一起
		int idx = 1;
		auto pair_it = _md5_to_file.equal_range(it->first);
		auto cur_it = pair_it.first;
		std::cout << "cut md5:" << it->first << std::endl;
		while (cur_it != pair_it.second)
		{
			std::cout << "\t第" << idx << "文件" << "\t";
			std::cout << cur_it->second << std::endl;
			++count;
			++cur_it;
			++idx;
		}
		it = pair_it.second;
	}
	std::cout << "文件总数:" << total << "\t" << count << std::endl;
	std::cout << "+++++++++++++++++++++++" << std::endl;
}
void file_manager::show_all_file()
{
	std::cout << "=======================" << std::endl;
	std::cout << "show_all_file" << std::endl;
	for (const auto& a : _file)
	{
		std::cout << a << std::endl;
	}
	std::cout << "file count:" << _file.size() << std::endl;
	std::cout << "=======================" << std::endl;
}
