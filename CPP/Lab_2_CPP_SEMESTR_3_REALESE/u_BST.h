#pragma once
#include <string>
#include <iostream>
#include <QDebug>
template <typename T>
class Node_BST {
public:
    T data;
    Node_BST* right = nullptr;
    Node_BST* left = nullptr;
    Node_BST* parent = nullptr;
};

template <typename T>
class u_BST_conteiner : public Node_BST<T> {
private:
    Node_BST<T>* head = nullptr;
    Node_BST<T>* tmp;


    void get_down(Node_BST<T> * head, size_t tabs = 0) {
        if (head)
        {
            qDebug() << std::string(tabs * 2, ' ')  << head->data << std::endl;

            get_down(head->left, tabs + 1);
            get_down(head->right, tabs + 1);
        }
    }

    Node_BST<T>* u_find(Node_BST<T> * tmp, T data) {
        if (tmp->data < data) {
            return u_find(tmp->right, data);
        }
        else if (tmp->data > data) {
            return u_find(tmp->left, data);
        }
        else {
            return tmp;
        }
    }

public:
    u_BST_conteiner() {}
    ~u_BST_conteiner() {}


    T get_head() {
        return head;
    }

    void insert(T data) {
        if (!head) {
            this->head = new Node_BST<T>;
            this->head->data = data;
            this->tmp = head;
        }
        else {
            if (this->tmp->data < data) {
                if(!this->tmp->right) {
                    this->tmp->right = new Node_BST<T>;
                    this->tmp->right->data = data;
                    this->tmp->right->parent = this->tmp;
                    this->tmp = this->head;
                }
                else {
                    this->tmp = this->tmp->right;
                    return insert(data);
                }
            }
            else {
                if (!this->tmp->left) {
                    this->tmp->left = new Node_BST<T>;
                    this->tmp->left->data = data;
                    this->tmp->left->parent = this->tmp;
                    this->tmp = this->head;
                }
                else {
                    this->tmp = this->tmp->left;
                    return insert(data);
                }
            }
        }
    }

    void erase(T data) {
        Node_BST<T> * p = u_find(this->tmp, data);
        if (!p->left && p->right) {
            Node_BST<T> * del = p;
            p = p->right;
            delete del;

        }

        else if (p->left && !p->right) {
            Node_BST<T>* del = this->tmp;
            this->tmp = this->tmp->left;
            delete del;
        }

        else if (!p->left && !p->right) {
            Node_BST<T>* check = p->parent;
            if (check->right == p)check->right = nullptr;
            else check->left = nullptr;
            delete p;
        }

        else {
            Node_BST<T>* mem = p;
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            mem->data = p->data;
            Node_BST<T>* check = p->parent;
            if (check->right == p) check->right = nullptr;
            else check->left = nullptr;
            delete p;

        }
    }

    Node_BST<T> * searc(T data) {
        Node_BST<T>* res = u_find(this->tmp, data);
        this->tmp = head;
        return res;
    }


    void show_tree(){
        get_down(tmp);
    }

};
