#pragma once
#include <iostream>
#include <memory>
#include <exception>
#define TT template <typename T>
TT
class badlist {
public:
    badlist() : _size(0), _head(nullptr), _tail(nullptr) {
    }
    void push_back(T data);
    void display();
    void push_front(T data);
    void insert(size_t pos, T data);
    void erase(size_t pos);
    T operator[](size_t pos);
    size_t size();
private:
    bool check(T data);
    size_t _size;
    template <typename U>
    class Node {
    public:
        Node(U data = U(), Node<U>* next = nullptr, Node<U>* prev = nullptr) : _data(data), _prev(prev), _next(next) {
        }
        Node operator=(Node<T>& another_node) {
            another_node._data = this->_data;
            another_node._next = this->_next;
            another_node._prev = this->_prev;
        }
    private:
        U _data;
        std::shared_ptr<Node<U>> _prev;
        std::shared_ptr<Node<U>> _next;
        friend class badlist;
    };

    std::shared_ptr<Node<T>> _head;
    std::shared_ptr<Node<T>> _tail;
};