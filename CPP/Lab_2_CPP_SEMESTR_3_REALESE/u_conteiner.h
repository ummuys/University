#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Node {
public:
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

template <typename T>
class u_conteiner: public Node<T>{
protected:
    Node<T>* head = new Node<T>;
    Node<T>* tail = new Node<T>;
    size_t c_emels = 0;
};

