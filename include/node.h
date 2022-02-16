#ifndef __NODE_H__
#define __NODE_H__

/*
*   This is a node implementation with T class type
*   A node is an element of a linked list that has by default
*   two subelement:
*       - the value
*       - the pointer to the next node
*   This implementation is made for the simple linked list data structure
*/
template <class T>
class Node {
    private:
        T value;
        Node<T>* next;
        
    public:
        Node(T value, Node<T>* next) {
            this->value = value;
            this->next = next;
        }

        ~Node() {
            delete this;
        }
        
        T getValue() {
            return this->value; 
        }

        Node<T>* getNext() {
            return this->next; 
        }

        void setValue(T value) {
            this->value = value; 
        }

        void setNext(Node<T>* next) {
            this->next = next; 
        }

};

#endif