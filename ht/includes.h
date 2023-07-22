#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>  
using std::cout, std::cin, std::endl, std::rand, std::string, std::fstream, std::vector, std::swap, std::ifstream, std::ofstream;
class player;
uint64_t level();
uint64_t rand_num();
void file_read(vector<player> &v);
void file_write(vector<player> &v);
class player {
private:
	string nick;
	uint64_t attempts;
public:
	player(const string& s, uint64_t at) : nick(s), attempts(at)
	{ };
	player() : nick(0), attempts(0)
	{ };
	void set(const string& s, uint64_t at) {
		nick = s;
		attempts = at;
	}
	bool operator<(const player& p) const;
	bool operator>(const player& p) const;
	bool operator==(const player& p) const;
	void sort(vector<player>& ptr);
	void remove_same(vector<player>& arr);
	void show(const vector<player>& arr);
	void full_sort(vector<player>& arr);
	string get_nick();
	uint64_t get_attempts();

};