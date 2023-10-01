#include <memory>
#include <stdexcept>
#include <iostream>
using std::shared_ptr;
template <typename T>
class badvector {
private:
    size_t _size;
    size_t _capacity;
    shared_ptr<T[]> arrptr;
    bool resizable;
    void initialize() {
        for (size_t i = 0; i < _capacity; ++i) {
            arrptr[i] = T();
        }
    }
    void initialize(shared_ptr<T[]>& ptrarr, size_t sz) {
        for (size_t i = 0; i < sz; ++i) {
            arrptr[i] = T();
        }
    }
public:
    badvector() : _size(0), _capacity(5), arrptr(new T[5]), resizable(1) {
        initialize();
    }
    ~badvector() = default;
    size_t capacity() const;
    size_t size() const;
    void push_back(T arg);
    void reserve(size_t sz);
    void resize(size_t sz);
    void insert(size_t pos, T num);
    void erase(size_t pos);
    void print_all();
    T operator[](size_t position) const;
    const T* cbegin();
    T* begin();
    const T* cend();
    T* end();
    void print(size_t position) const;
    badvector<T>& operator=(const badvector<T>& sc);
    badvector<T>& operator=(badvector<T>& sc);
    badvector<T>(const badvector<T>& sc);
    badvector<T>(badvector<T>& sc);
};
