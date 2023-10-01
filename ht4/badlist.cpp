#include "badlist\badlist.ipp"
int main(){
    badlist<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_back(i);
	}
	std::cout << "list after 1st push" << std::endl;
	list.display();
	std::cout << "size of array " << list.size() << std::endl;
	list.erase(2);
	list.erase(3);
	list.erase(4);
	std::cout << "list after erasing elements" << std::endl;
	list.display();
	std::cout << "after inputing 10 at the beginning of list" << std::endl;
	list.push_front(10);
	list.display();
	std::cout << "after inputing 20 at the middle of array" << std::endl;
	list.insert((list.size()/2), 20);
	list.display();
	std::cout << "after inputing 30 at the end of array" << std::endl;
	list.push_back(30);
	list.display();
}