#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
#include <node.h>

/*
*   Stack is a class that implement 
*   the data structure called LIFO 
*   (list with the priorite order: Last In First Out)
*   In this implementation, there is a template that indicates
*   the class type of the linked list (LIFO)
*   For example, T is an integer
*       -> Stack<int>* l = new Stack<int>()
*/
template <class T>
class Stack {
    private:
        Node<T>* head;
        int size;

    public:
        /*
        *   Constructs the linked list and initialize the head
        *   with the NULL pointer
        */
        Stack() {
            this->head = NULL;
            this->size = 0;
        }

        /*
        *   Constructs the linked list with the specified value and
        *   the appropriate pointer to the next node of the list
        */
        Stack(T value, Node<T>* next) {
            this->head = new Node<T>(value, next);
            this->size++;
        }

        /*
        *   Constructs the linked list with just a node that already
        *   has its value and next node pointer
        */
        Stack(Node<T>* node) {
            this->head = node;
            if (node != NULL) this->size++;
            else this->size = 0;
        }

        ~Stack() {
            delete this;
        }

        // Gets the head of the list
        Node<T>* getHead() { 
            return this->head; 
        }

        // Gets the size of the current list
        int getSize() {
            return this->size; 
        }

        // Sets the head of the list with the specified node
        void setHead(Node<T>* node) {
            this->head = node; 
        }

        // Adds a node in the current list as its last node
        void push(T value) {
            Node<T>* tmp = new Node<T>(value, this->head);
            this->head = tmp;
            this->size++;
        }

        // Instead of adding node as the last, it deletes the last created/added node
        void pop() {
            if (this->head == NULL) return;
            Node<T>* tmp = this->head;
            this->setHead(this->head->getNext());
            this->size--;
            free(tmp);
        }

        // Shows all each value of the list node
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

        // Verifies if the list is empty or not
        bool isEmpty() { 
            return this->size == 0; 
        }

        // Returns the first created/added node of the list
        // As if this is a LIFO, then the first node is the first created node
        // And the concept is the same for the pickLast method
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

        // Returns the last created/added node of the list
        T pickFirst() {
            if (!this->isEmpty()) return this->head->getValue();
            std::cout << "Empty list" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Returns the node at the specified index
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

        // Sets in an array of T the each value of list node
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