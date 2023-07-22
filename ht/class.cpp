#include "includes.h"
bool player::operator<(const player& p) const {
	return attempts < p.attempts;
}
bool player::operator>(const player& p) const {
	return attempts > p.attempts;
}
bool player::operator==(const player& p)const {
	return nick == p.nick;
}
void player::remove_same(vector<player>& arr) {
	for (int i = 0; i < size(arr) - 1; i++) {
		for (int j = 0; j < size(arr) - 2; j++) {
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
	for (int i = 0; i < size(arr) - 1; i++) {
		for (int j = 0; j < size(arr) - 2; j++) {
			if (arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}
void player::full_sort(vector<player>& arr) {
	arr[0].sort(arr);
	arr[0].remove_same(arr);
}
string player::get_nick() {
	return this->nick;
}
uint64_t player::get_attempts() {
	return this->attempts;
}
void player::show(const vector<player>& arr) {
	cout << "Record table: " << endl;
	for (int i = 0; i < size(arr); i++) {
		cout << "Nickname: " << arr[i].nick << " Attempts: " << arr[i].attempts << endl;
	}
}