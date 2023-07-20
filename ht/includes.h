#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
using std::cout, std::cin, std::endl, std::rand, std::string, std::fstream, std::vector, std::swap, std::ifstream, std::ofstream;
class player {
private:
	string nick;
	uint64_t attempts;
public:
	player(const string& s, uint64_t at) : nick(s), attempts(at)
	{ };
    player() : nick(0), attempts(0)
	{ };
	void set(const string& s, uint64_t at){
		nick = s;
		attempts = at;
	}
	bool operator<(const player& p) const;
	bool operator>(const player& p) const;
	void sort(vector<player> &ptr);
    bool operator==(const player& p);
    void remove_same(vector<player>& arr);
    void show(const vector<player>& arr);
    void full_sort(vector<player>& arr);
    string get_nick();
    uint64_t get_attempts();
			
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
void player::remove_same(vector<player>& arr) {
	for (int i = 0; i < size(arr)-1; i++) {
		for (int j = 0; j < size(arr)-2; j++) {
			if (arr[i] == arr[j]) {
				if (arr[i] > arr[j]) {
					arr.erase(arr.begin() + i);
				}
				else if (arr[i] == arr[j]) {
					arr.erase(arr.begin() + i);
				}
				else {
					arr.erase(arr.begin() + j);
				}
			}
		}
	}
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
void player::full_sort(vector<player>& arr){
    arr[1].sort(arr);
    arr[1].remove_same(arr);
}
string player::get_nick(){
    return this->nick;
}
uint64_t player::get_attempts(){
    return this->attempts;
}
void player::show(const vector<player>& arr){
    cout << "Record table:" << endl;
    for(int i =0; i < size(arr); i++){
        cout << "Nickname:" <<  arr[i].nick << "    Attempts: " << arr[i].attempts; 
    }
}
int level();
int rand_num();
void file_read(vector<player> &v);
void file_write(const vector<player> &v);