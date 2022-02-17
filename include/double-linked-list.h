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

        void addFirst(T value) {
            if (this->isEmpty()) {
                DoubleLinkNode<T>* tmp = new DoubleLinkNode<T>(value, this->head, this->tail);
                this->tail = tmp;
                this->head = tmp;
            } else {
                DoubleLinkNode<T>* tmp = new DoubleLinkNode<T>(value, this->head->getPrev(), this->head);
                this->head->setPrev(tmp);
                this->head = tmp;
            }
            this->size++;
        }

        void addLast(T value) {
            if (this->isEmpty()) {
                DoubleLinkNode<T>* tmp = new DoubleLinkNode<T>(value, this->head, this->tail);
                this->tail = tmp;
                this->head = tmp;
            } else {
                DoubleLinkNode<T>* tmp = new DoubleLinkNode<T>(value, this->tail, this->tail->getNext());
                this->tail->setNext(tmp);
                this->tail = tmp;
            }
            this->size++;
        }

        void removeFirst() {
            if (this->isEmpty()) return;
            DoubleLinkNode<T>* tmp = this->head;
            this->setHead(this->head->getNext());
            this->head->setPrev(tmp->getPrev());
            free(tmp);
            this->size--;
        }

        void removeLast() {
            if (this->isEmpty()) return;
            DoubleLinkNode<T>* tmp = this->tail;
            this->setTail(this->tail->getPrev());
            this->tail->setNext(tmp->getNext());
            free(tmp);
            this->size--;
        }

        void showForward() {
            if (this->isEmpty()) {
                std::cout << "Empty list" << std::endl;
                return;
            }
            DoubleLinkNode<T>* tmp = this->head;
            std::cout << "(" << this->size << ")[";
            while (tmp != NULL) {
                if (tmp->getNext() == NULL) std::cout << tmp->getValue() << "]" << std::endl;
                else std::cout << tmp->getValue() << ", ";
                tmp = tmp->getNext();
            }
        }

        void showBackward() {
            if (this->isEmpty()) {
                std::cout << "Empty list" << std::endl;
                return;
            }
            DoubleLinkNode<T>* tmp = this->tail;
            std::cout << "(" << this->size << ")[";
            while (tmp != NULL) {
                if (tmp->getPrev() == NULL) std::cout << tmp->getValue() << "]" << std::endl;
                else std::cout << tmp->getValue() << ", ";
                tmp = tmp->getPrev();
            }
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