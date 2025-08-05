#pragma once
#include "u_conteiner.h"


template<typename T>
class u_queue_conteiner : public u_conteiner<T> {
public:
    u_queue_conteiner() {}
    ~u_queue_conteiner() {}

    Node<T>* get_head(){
        return this->head;
    }

    Node<T>* get_tail(){
        return this->tail;
    }

    T& operator[] (const int i) {
        if (i > this->c_emels || i < 0) return this->head->data;
        int ind = i;
        Node<T>* tmp = this->head->next;
        while (ind > 0) {
            tmp = tmp->next;
            ind--;
        }
        return tmp->data;
    }

    void push_back(T data) {
        Node<T>* new_node = new Node<T>;
        if (!this->head->next) {
            new_node->data = data;
            this->head->next = new_node;
            new_node->prev = this->head;
            new_node->next = this->tail;
            this->tail->prev = new_node;
            this->c_emels++;
        }
        else {
            new_node->data = data;
            new_node->prev = this->tail->prev;
            this->tail->prev->next = new_node;
            this->tail->prev = new_node;
            new_node->next = this->tail;
            this->c_emels++;
        }


    }

    void pop_front() {
        Node<T>* tmp = this->head->next;
        if (!(this->c_emels - 1))this->head->next = nullptr;
        else this->head->next = this->head->next->next;
        this->c_emels--;
        delete tmp->data;
        delete tmp;
    }

    void insert(int ind, T data) {
        if (ind < 0 || ind > this->c_emels)return;
        int i = 0;
        Node<T>* tmp = this->head->next;
        Node<T>* new_node = new Node<T>;
        while (i < ind) {
            tmp = tmp->next;
            i++;
        }
        new_node->data = data;
        new_node->prev = tmp->prev;
        tmp->prev->next = new_node;
        new_node->next = tmp;
        tmp->prev = new_node;
        this->c_emels++;
    }

    T front() {
        return this->head->next->data;
    }

    size_t size() {
        return this->c_emels;
    }

    void clear() {
        while (this->head) {
            Node<T>* mem = this->head;
            this->head = this->head->next;
            delete mem;
        }
        this->tail = new Node<T>;
        this->head = new Node<T>;
        this->c_emels = 0;
    }

    void destroy(){
        while (this->head) {
            Node<T>* mem = this->head;
            this->head = this->head->next;
            delete mem;
        }
    }

    void clear_and_update(Node<T>* new_head, Node<T>* new_tail, size_t new_emels){
        while (this->head) {
            Node<T>* mem = this->head;
            this->head = this->head->next;
            delete mem;
        }
        this->tail = new_tail;
        this->head = new_head;
        this->c_emels = new_emels;
    }

    void erase(T data) {
        Node<T>* del = this->head->next;
        while (del->data != data && del != this->tail) {
            del = del->next;
        }
        del->prev->next = del->next;
        del->next->prev = del->prev;
        this->c_emels--;
        delete del;
    }

    bool empty() {
        return this->c_emels ? 0 : 1;
    }
};
