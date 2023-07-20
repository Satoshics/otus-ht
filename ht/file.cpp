#include "includes.h"
void file_read(vector<player> &arr){
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
    file.clear();
    file.close();

}
void file_write(vector<player> &arr){
    fstream file("data.txt", std::ios::app | std::ios::in | std::ios::out);
	if (!file.is_open()) {
		cout << "Error opening file";
	}
    file.clear();
	arr[1].full_sort(arr);
    for(int i=0; i < size(arr); i++){
        string nick = arr[i].get_nick();
        uint64_t at = arr[i].get_attempts();
        file << nick;
        file << at;
    }
    file.close();
}	
