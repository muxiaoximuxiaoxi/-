#include"file.h"

void search_dir(const std::string& path, std::unordered_set<std::string>& sum_file)
{
	std::string match = path + "\\" + "*.*";
	_finddata_t file_attr;
	long handle = _findfirst(match.c_str(), &file_attr);
	if (handle == -1)
	{
		perror("search failed!!!");
		std::cout << match << std::endl;
		return;
	}
	do
	{
		if (file_attr.attrib & _A_SUBDIR)
		{
			if (strcmp(file_attr.name, ".") != 0 && strcmp(file_attr.name, "..") != 0)
			{
				//��ǰΪĿ¼����������
				search_dir(path + "\\" + file_attr.name, sum_file);
			}
		}
		else
		{
			//��ǰΪ�ļ����򱣴�
			sum_file.insert(path + "\\" + file_attr.name);
		}
	} while (_findnext(handle, &file_attr) == 0);
	_findclose(handle);
}


void delete_file(const char* filename)
{
	if (remove(filename) == 0)
	{
		std::cout << "delete file:" << filename << "success!!!" << std::endl;
	}
	else
	{
		perror("delete file failed!!!");
	}
}