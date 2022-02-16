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
        }

        ~DoubleLinkedList() {
            delete this;
        }
};

#endif