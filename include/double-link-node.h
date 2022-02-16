#ifndef __DOUBLE_LINK_NODE_H__
#define __DOUBLE_LINK_NODE_H__
#include <node.h>

template <class T>
class DoubleLinkNode {
    private:
        DoubleLinkNode<T>* prev;
        T value;
        DoubleLinkNode<T>* next;
    
    public:
        DoubleLinkNode(T value, DoubleLinkNode<T>* prev, DoubleLinkNode<T>* next) {
            this->value = value;
            this->prev = prev;
            this->next = next;
        }

        ~DoubleLinkNode() {
            delete this;
        }

        T getValue() {
            return this->value;
        }

        DoubleLinkNode<T>* getPrev() {
            return this->prev;
        }

        DoubleLinkNode<T>* getNext() {
            return this->next;
        }

        void setValue(T value) {
            this->value = value;
        }

        void setPrev(DoubleLinkNode<T>* prev) {
            this->prev = prev;
        }
        
        void setNext(DoubleLinkNode<T>* next) {
            this->next = next;
        }
};

#endif