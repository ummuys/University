#pragma once
#include "u_conteiner.h"


template<typename T>
class u_stack_conteiner : public u_conteiner<T> {
public:
    u_stack_conteiner() {}
    ~u_stack_conteiner() {}

    T& operator[] (const int i) {
        if (i > this->c_emels || i < 0) return this->tail->data;
        int ind = i;
        Node<T>* tmp = this->tail->prev;
        while (ind > 0) {
            tmp = tmp->prev;
            ind--;
        }
        return tmp->data;
    }

    Node<T>* get_tail(){
        return this->tail;
    }

    void push(T data) {
        Node<T>* new_node = new Node<T>;
        new_node->data = data;
        new_node->prev = this->tail->prev;
        this->tail->prev = new_node;
        this->c_emels++;
    }

    void pop() {
        Node<T>* tmp = this->tail->prev;
        this->tail->prev = this->tail->prev->prev;
        this->c_emels--;
        delete tmp->data;
        delete tmp;
    }

    T top() {
        return this->tail->prev->data;
    }

    T d_top(){
        return this->tail->prev->prev->data;
    }

    size_t size() {
        return this->c_emels;
    }

    bool empty() {
        return this->c_emels? 0 : 1;
    }

    void clear() {
        while (this->tail) {
            Node<T>* mem = this->tail;
            this->tail = this->tail->prev;
            delete mem;
        }
        this->tail = new Node<T>;
        this->head = new Node<T>;
        this->c_emels = 0;
    }

    void clear_and_update(Node<T>* new_tail, size_t new_emels){
        while (this->tail) {
            Node<T>* mem = this->tail;
            this->tail = this->tail->prev;
            delete mem;
        }
        this->tail = new_tail;
        this->c_emels = new_emels;
    }
};
