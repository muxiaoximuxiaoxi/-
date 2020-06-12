#include"file_manager.h"
#include"file.h"
#include<utility>
void file_manager::scanner_dir(const std::string& path)
{
	//��������
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
		//�������ļ�ǰ����
		_md5.reset();
		//string ת���� char *
		//���Ҫ��stringֱ��ת����const char *���͡�string��2�������������á�
		//һ����.c_str()��һ����data��Ա������
		_md5_to_file.insert(make_pair(_md5.get_File_md5(a.c_str()), a));

	}
}
//ֻ���������ظ��ļ��Ľ��
void file_manager::get_copy_list()
{
	_file_to_md5.clear();
	//��Ҫ�÷�Χfor,�漰ɾ������
	auto it = _md5_to_file.begin();
	while (it != _md5_to_file.end())
	{
		//����ÿ��MD5��Ӧ�����ļ��Ľ��
		if (_md5_to_file.count(it->first) > 1)
		{
			//equal_range ����ֵ��pair<beginIt,endIt>:[beginIt,endIt)--->����������ʱ����
			auto pair_it = _md5_to_file.equal_range(it->first);
			auto begin = pair_it.first;
			while (begin != pair_it.second)
			{
				//ֻ����ظ��ļ���ӳ���ϵ
				_file_to_md5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//��һ����ͬ��MD5����ʼλ��
			it = pair_it.second;
		}
		else
		{
			//��ɾ�����ٸ���
			_file.erase(it->second);
			//erase�ķ���ֵ����ɾ��Ԫ�ص���һ��λ��
			it = _md5_to_file.erase(it);
		}
	}
}
//���е�ɾ������֤һ���ļ������ڸ���
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
	std::cout << "delete files ��" << count << std::endl;
}
void file_manager::delete_by_md5(const std::string& md5)
{
	//md5ӳ��file
	if (_md5_to_file.count(md5) == 0)
	{
		std::cout << md5 << "not exist!!!" << std::endl;
		return;
	}
	//ɾ��ʱ��Ҫ����һ�ݣ��涨������һ���ļ�
	auto pair_it = _md5_to_file.equal_range(md5);
	std::cout << "md5ֵ��" << md5 << "---have---" << _md5_to_file.count(md5) << std::endl;
	auto cur_it = pair_it.first;
	++cur_it;
	int count = 0;
	while (cur_it != pair_it.second)
	{
		_file.erase(cur_it->second);
		_file_to_md5.erase(cur_it->second);
		//�ļ��Ӵ�����ɾ��
		delete_file(cur_it->second.c_str());
		++count;
		++cur_it;
	}
	//����һ��MD5��file��ӳ��
	cur_it = pair_it.first;
	++cur_it;
	//erase(first,last)----> ɾ������[first,last)
	_md5_to_file.erase(cur_it, pair_it.second);
	std::cout << "delete files number��" << count << std::endl;
}
//�����ظ����ļ�ֻ����һ��
void file_manager::delete_all_copy()
{
	std::unordered_set<std::string> md5_set;
	//�ҳ����е�md5ֵ
	for (const auto& a : _md5_to_file)
	{
		md5_set.insert(a.first);
	}
	for (const auto& b : md5_set)
	{
		delete_by_md5(b);
	}
}
//ɾ�����а���'match'���ļ�
void file_manager::delete_by_match(const std::string& match)
{
	std::unordered_set<std::string> all_file;
	//���������ļ�
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
		//md5ֵ��ͬ����ʾ��һ��
		int idx = 1;
		auto pair_it = _md5_to_file.equal_range(it->first);
		auto cur_it = pair_it.first;
		std::cout << "cut md5:" << it->first << std::endl;
		while (cur_it != pair_it.second)
		{
			std::cout << "\t��" << idx << "�ļ�" << "\t";
			std::cout << cur_it->second << std::endl;
			++count;
			++cur_it;
			++idx;
		}
		it = pair_it.second;
	}
	std::cout << "�ļ�����:" << total << "\t" << count << std::endl;
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
