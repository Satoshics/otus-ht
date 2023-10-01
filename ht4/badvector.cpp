#include "badvector\badvector.ipp"
int main() {
	badvector<int> vector;
	vector.reserve(10);
	for (int i = 0; i < 10; ++i) {
		vector.push_back(i);
	}
	cout << "array after 1st push" << endl;
	vector.print_all();
	cout << "size of array " << vector.capacity() << endl;
	vector.erase(2);
	vector.erase(3);
	vector.erase(4);
	cout << "array after erasing elements" << endl;
	vector.print_all();
	cout << "after inputing 10 at the beginning of array" << endl;
	vector.insert(0, 10);
	vector.print_all();
	cout << "after inputing 20 at the middle of array" << endl;
	vector.insert((vector.size()/2), 20);
	vector.print_all();
	cout << "after inputing 30 at the end of array" << endl;
	vector.push_back(30);
	vector.print_all();
}
