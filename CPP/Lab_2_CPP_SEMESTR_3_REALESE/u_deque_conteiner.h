#pragma once
#include "u_queue_conteiner.h"
#include <QDebug>
template<typename T>
class u_deque_conteiner : public u_queue_conteiner<T> {
public:

    void push_front(T data) {
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
            Node<T>* new_node = new Node<T>;
            Node<T>* tmp = this->head->next;
            new_node->data = data;
            this->head->next = new_node;
            new_node->next = tmp;
            new_node->prev = this->head;
            tmp->prev = new_node;
            this->c_emels++;
        }
    }

    void pop_back() {
        if (!(this->c_emels - 1)) {
            Node<T>* tmp = this->tail->prev;
            this->tail->prev = this->head;
            this->head->next = this->tail;
            this->c_emels--;
            delete tmp->data;
            delete tmp;
        }

        else {
            Node<T>* tmp = this->tail->prev;
            this->tail->prev = tmp->prev;
            tmp->prev->next = this->tail;
            this->c_emels--;
            delete tmp->data;
            delete tmp;
        }
    }

    T back() {
        return this->tail->prev->data;
    }
};
