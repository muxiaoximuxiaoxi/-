#pragma once
#include<io.h>
#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>

void search_dir(const std::string& path, std::unordered_set<std::string>& sum_file);

void delete_file(const char* filename);