#include "includes.h"
void file_read(vector<player> &arr){
	cout << "Reading file with results" << endl;
	if (!arr.empty()) {
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
			arr.push_back(player(n, a));
		}
		file.clear();
		file.close();
	}
}
void file_write(vector<player> &arr){
	if(size(arr) >= 3){
		arr[0].full_sort(arr);
	}
	else if(size(arr) == 2){
		if(arr[1] >arr[0]){
			swap(arr[2], arr[1]);
		}
		if(arr[1] == arr[0]){
			if(arr[0] > arr[1]){
				arr.erase(arr.begin(), arr.begin()+1);
			}
			else{
				arr.erase(arr.begin(), arr.begin());
			}
		}
	}
	cout << "Writing file with results" << endl;
    fstream file("data.txt", std::ios::app | std::ios::in | std::ios::out);
	if (!file.is_open()) {
		cout << "Error opening file";
	}
    file.clear();
    for(int i = 0; i < size(arr); i++){
        string nick = arr[i].get_nick();
        uint64_t at = arr[i].get_attempts();
        file << nick << " ";
        file << at << endl;
    }
    file.close();
}	
