#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__
#include <iostream>
#include <double-link-node.h>

template <class T>
class DoubleLinkedList {
    private:
        DoubleLinkNode<T>* head;
        DoubleLinkNode<T>* tail;
        int size;

    public:
        DoubleLinkedList() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }

        ~DoubleLinkedList() {
            delete this->head;
            delete this->tail;
            delete this;
        }

        void pushFirst(T value) {
            
        }

        DoubleLinkNode<T>* getHead() {
            return this->head;
        }

        DoubleLinkNode<T>* getTail() {
            return this->tail;
        }

        int getSize() {
            return this->size;
        }

        void setHead(DoubleLinkNode<T>* head) {
            this->head = head;
        }

        void setTail(DoubleLinkNode<T>* tail) {
            this->tail = tail;
        }

        void setSize(int size) {
            this->size = size;
        }

        bool isEmpty() {
            return this->size == 0;
        }
};

#endif