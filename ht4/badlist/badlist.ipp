#include "badlist.h"
TT
void badlist<T>::push_back(T data) {
    if (check(data)) {

    }
    else {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
        _tail->_next = newNode;
        newNode->_prev = _tail;
        _tail = newNode;
    }
    ++this->_size;
}
TT
void badlist<T>::display() {
    std::shared_ptr<Node<T>> current = _head;
    for (size_t i = 0; i < _size; ++i) {
        std::cout << current->_data << " ";
        current = current->_next;
    }
    std::cout << std::endl;
}
TT
void badlist<T>::push_front(T data) {
    if (check(data)) {

    }
    else {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
        newNode->_next = _head;
        _head->_prev = newNode;
        _head = newNode;
    }
    ++this->_size;
}
TT
void badlist<T>::insert(size_t pos, T data) {
    if (check(data)) {

    }
    else {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
        std::shared_ptr<Node<T>> _temp;
        if (pos > (_size / 2)) {
            _temp = _tail;
            for (long long i = _size; i >= pos; --i) {
                _temp = _temp->_prev;
                if (i == pos + 1) {
                    newNode->_next = _temp;
                    newNode->_prev = _temp->_prev;
                    _temp->_prev->_next = newNode;
                    _temp->_prev = newNode;
                }
            }

        }
        else {
            _temp = _head;
            for (size_t i = 0; i < pos; ++i) {
                _temp = _temp->_next;
                if (i == pos - 1) {
                    newNode->_prev = _temp;
                    newNode->_next = _temp->_next;
                    _temp->_next->_prev = newNode;
                    _temp->_next = newNode;
                }
            }
        }
        _temp.~shared_ptr();
    }
    ++this->_size;

}
TT
bool badlist<T>::check(T data) {
    if (_size == 0 || _tail == nullptr || _head == nullptr) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
        this->_head = newNode;
        this->_tail = _head;
        _tail->_prev = nullptr;
        return 1;
    }
    else {
        return 0;
    }
}
TT
void badlist<T>::erase(size_t pos) {
    if (pos > _size || pos < 0) {
        throw std::invalid_argument("element out of range");
    }
    std::shared_ptr<Node<T>> _temp;
    if (pos > (_size / 2)) {
        _temp = _tail;
        for (size_t i = _size; i > pos; --i) {
            _temp = _temp->_prev;
            if (i == pos + 1) {
                _temp->_next->_prev = _temp->_prev;
                _temp->_prev->_next = _temp->_next;
            }
        }
    }
    else {
        _temp = _head;
        for (size_t i = 0; i < pos; ++i) {
            _temp = _temp->_next;
            if (i == pos - 1) {
                _temp->_next->_prev = _temp->_prev;
                _temp->_prev->_next = _temp->_next;
            }
        }
    }
    _temp.~shared_ptr();
    --this->_size;
}
TT 
size_t badlist<T>::size(){
    return this->_size;
}
TT
T badlist<T>::operator[](size_t pos){
    if(pos > _size || pos < 0) {
        throw std::out_of_range("input out of range");
    }
    std::shared_ptr<Node<T>> _temp;
    if (pos > (_size / 2)) {
        _temp = _tail;
        for (size_t i = _size; i > pos; --i) {
            _temp = _temp->_prev;
    }
    }
    else {
        _temp = _head;
            for (size_t i = 0; i < pos; ++i) {
                _temp = _temp->_next;
        }
    }
    return _temp->_data;
}