#include "includes&&headers.h"
void file_read( vector<player> &arr){
	ifstream file("data.txt");
	if (!file.is_open()) {
		cout << "Error opening file";
	}
	arr.reserve(15);
	string n;
	uint64_t a;
	while (!file.eof())
	{
		file >> n;
		file >> a;
		arr.push_back(player(n,a));
	}

}
void file_write( vector<player> &arr){
    fstream file("data.txt", std::ios::app | std::ios::in | std::ios::out);
	if (!file.is_open()) {
		cout << "Error opening file";
	}
	arr[1].sort(arr);
	for (int i = 0; i < size(arr); i++) {
		arr[i].show();
	}
}


