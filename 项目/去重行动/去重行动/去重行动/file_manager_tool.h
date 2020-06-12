#pragma once
#include"file_manager.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class file_manager_tool
{
public:
	void scanner();
	void delete_by_md5();
	void delete_by_name();
	void delete_all_copy();
	void delete_by_match();
	void show_all_file();
	void show_copy();
private:
	file_manager _fm;
};