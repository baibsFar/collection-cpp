#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
#include <stack.h>

/*
*   Queue is a class that implement 
*   the data structure called FIFO 
*   (list with the priorite order: First In First Out)
*   In this implementation, there is a template that indicates
*   the class type of the linked list (FIFO)
*   For example, T is an integer
*       -> Queue<int>* l = new Queue<int>()
*/
template <class T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        Queue() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }

        Queue(T value, Node<T>* next) {
            this->head = new Node<T>(value, next);
            this->tail = this->head;
            this->size++;
        }

        Queue(Node<T>* node) {
            this->head = node;
            this->tail = this->head;
            if (node != NULL) this->size++;
            else this->size = 0;
        }

        ~Queue() {
            delete this;
        }

        Node<T>* getHead() {
            return this->head;
        }

        Node<T>* getTail() {
            return this->tail;
        }

        int getSize() {
            return this->size;
        }

        void setHead(Node<T>* node) {
            this->head = node;
        }

        void setTail(Node<T>* node) {
            this->tail = node;
        }

        void setSize(int size) {
            this->size = size;
        }

        void push(T value) {
            Node<T>* tmp;
            if (this->tail == NULL) {
                tmp = new Node<T>(value, this->tail);
                this->head = tmp;
                this->tail = this->head;
            } else {
                tmp = new Node<T>(value, this->tail->getNext());
                this->tail->setNext(tmp);
                this->tail = tmp;
            }
            this->size++;
        }

        void pop() {
            if (this->head == NULL) return;
            Node<T>* tmp = this->head;
            this->setHead(this->head->getNext());
            this->size--;
            free(tmp);
            // Repositioning the tail
            tmp = this->head;
            while (tmp != NULL) {
                if (tmp->getNext() == NULL) this->tail = tmp;
                tmp = tmp->getNext();
            }
        }

        void show() {
            if (this->isEmpty()) {
                std::cout << "Empty list" << std::endl;
                return;
            }
            Node<T>* tmp = this->head;
            std::cout << "(" << this->size << ")[";
            while (tmp != NULL) {
                if (tmp->getNext() == NULL) std::cout << tmp->getValue() << "]" << std::endl;
                else std::cout << tmp->getValue() << ", ";
                tmp = tmp->getNext();
            }
        }

        bool isEmpty() {
            return this->size == 0;
        }

        T pickLast() {
            if (!this->isEmpty()) {
                Node<T>* tmp = this->head;
                while (tmp != NULL) {
                    if (tmp->getNext() == NULL) break;
                    tmp = tmp->getNext();
                }
                return tmp->getValue();
            }
            std::cout << "Empty list" << std::endl;
            exit(EXIT_FAILURE);
        }

        T pickFirst() {
            if (!this->isEmpty()) return this->head->getValue();
            std::cout << "Empty list" << std::endl;
            exit(EXIT_FAILURE);
        }

        T pick(int index) {
            if (index >= this->size) {
                std::cout << "Index out of bound" << std::endl;
                exit(EXIT_FAILURE);
            }
            Node<T>* tmp = this->head;
            int i = 0;
            while (i < index && tmp != NULL) {
                tmp = tmp->getNext();
                i++;
            }
            return tmp->getValue();
        }

        void toArray(T* array, int size) {
            if (!this->isEmpty()) {
                int i = 0;
                Node<T>* tmp = this->head;
                while (tmp != NULL && i < size) {
                    *(array + i) = tmp->getValue();
                    tmp = tmp->getNext();
                    i++;
                }
                return;
            }
            std::cout << "Empty list" << std::endl;
        }
};

#endif