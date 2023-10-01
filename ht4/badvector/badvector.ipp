#include "badvector.h"
using std::cout, std::endl;
#define TT template <typename T>
TT
size_t badvector<T>::capacity() const {
    return _capacity;
}
TT
size_t badvector<T>::size() const {
    return _size;
}
TT
void badvector<T>::push_back(T arg) {
    if (_size == _capacity) {
        reserve(_capacity + 5);
    }
    this->arrptr[_size] = std::move(arg);
    ++_size;
}
TT
void badvector<T>::reserve(size_t sz) {
    if (!resizable) throw std::runtime_error("you are not able to resize badvector");
    if (sz <= _capacity) {
        return;
    }
    std::unique_ptr<T[]> temp(new T[sz]);
    for (size_t i = 0; i < _size; ++i) {
        temp[i] = std::move(arrptr[i]);
    }
    arrptr = std::move(temp);
    _capacity = sz;
}
TT
void badvector<T>::resize(size_t sz) {
    if (!resizable) throw std::exception("you are not able to resize badvector");
    if (sz == _size) return;
    if (sz < _size) {
        std::unique_ptr<T[]> temp(new T[sz]);
        for (size_t i = 0; i < _size; ++i) {
            temp[i] = std::move(arrptr[i]);
        }
    }
    else {
        reserve(sz);
    }
    _capacity = sz;
    resizable = 0;
}
TT
void badvector<T>::insert(size_t pos, T num) {
    ++_size;
    ++_capacity;
    shared_ptr<T[]> temp(new T[_size]);
    for (size_t i = 0; i < _size; ++i) {
        if (i < pos) {
            temp[i] = std::move(arrptr[i]);
        }
        else if (i == pos) {
            temp[i] = std::move(num);
        }
        else {
            temp[i] = std::move(arrptr[i - 1]);
        }
    }
    this->arrptr.reset();
    this->arrptr = std::move(temp);
}

TT
T badvector<T>::operator[](size_t position) const {
    if (position >= _size) {
        throw throw std::exception("badvector out of range");
    }
    return arrptr[position];
}
TT
void badvector<T>::erase(size_t pos) {
    --_size;
    --_capacity;
    shared_ptr<T[]> temp(new T[_size]);
    for (size_t i = 0; i < _size; ++i) {
        if (i < pos) {
            temp[i] = std::move(arrptr[i]);
        }
        else {
            temp[i] = std::move(arrptr[i] + 1);
        }
    }
    this->arrptr.reset();
    this->arrptr = std::move(temp);
}
TT
void badvector<T>::print(size_t position) const {
    if (position >= _size) {
        throw std::exception("out of range");
    }
    cout << arrptr[position] << " ";
}
TT
const T* badvector<T>::cbegin(){
    return arrptr.get();
}
TT
T* badvector<T>::begin() {
    return arrptr.get();
}
TT
const T* badvector<T>::cend(){
    return arrptr.get() + _size;
}
TT
T* badvector<T>::end() {
    return arrptr.get() + _size;
}
TT
badvector<T>& badvector<T>::operator=(const badvector<T>& sc) {
    if (this == &sc) {
        return *this;
    }
    sc.arrptr.reset();
    size_t sz = this->_size;
    sc.arrptr(new T[sz]);
    sc.initialize(arrptr, sz);
    sc._capacity = this->_capacity;
    sc._size = this->_size;
    sc.arrptr = this->arrptr;
    sc.resizable = this->resizable;
}
TT
void badvector<T>::print_all() {
    for (size_t i = 0; i < this->_size; ++i) {
        print(i);
        if (i == (this->_size - 1)) {
            cout << endl;
        }
    }
}
TT
badvector<T>& badvector<T>::operator=(badvector<T>& sc) {
    if (this == &sc) {
        return *this;
    }
    sc.arrptr.reset();
    size_t sz = this->_size;
    sc.arrptr(new T[sz]);
    sc.initialize(arrptr, sz);
    sc._capacity = this->_capacity;
    sc._size = this->_size;
    sc.arrptr = this->arrptr;
    sc.resizable = this->resizable;
}
TT
badvector<T>::badvector(const badvector<T>& sc) {
    if (this == &sc) {
        return;
    }
    this->_size = sc._size;
    this->_capacity = sc._capacity;
    this->resizable = sc.resizable;
    arrptr.reset(new T[_capacity]);
    initialize(arrptr, _size);
    for (size_t i = 0; i < _size; ++i) {
        arrptr[i] = sc.arrptr[i];
    }
}
TT
badvector<T>::badvector(badvector<T>& sc) {
    if (this == &sc) {
        return;
    }
    this->_size = sc._size;
    this->_capacity = sc._capacity;
    this->resizable = sc.resizable;
    arrptr.reset(new T[_capacity]);
    initialize(arrptr, _size);
    for (size_t i = 0; i < _size; ++i) {
        arrptr[i] = sc.arrptr[i];
    }
}
