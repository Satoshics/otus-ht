#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
using std::cout, std::cin, std::endl, std::rand, std::string, std::fstream, std::vector, std::swap, std::ifstream, std::ofstream;
int level();
int rand_num();
void file_read(vector<player> &v);
void file_write(vector<player> &v);
class player {
private:
	string nick;
	uint64_t attempts;
public:
	player(const string& s, uint64_t at) : nick(s), attempts(at)
	{ };
	void set(const string& s, uint64_t at){
		nick = s;
		attempts = at;
	}
	void show() {
		cout << "Nickname = " << nick << " " << "attempts = " << attempts << endl;
	}
	bool operator<(const player& p) const;
	bool operator>(const player& p) const;
	void sort(vector<player> &ptr);
    bool operator==(const player& p);
			
};
bool player::operator<(const player& p) const {
	return attempts < p.attempts;
}
bool player::operator>(const player& p) const {
	return attempts > p.attempts;
}
bool player::operator==(const player& p){
    return nick==p.nick;
}
void player::sort(vector<player>& arr) {
	for (int i = 0; i < size(arr)-1; i++) {
		for (int j = 0; j < size(arr) - 2; j++) {
			if (arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}
