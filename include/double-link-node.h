#ifndef __DOUBLE_LINK_NODE_H__
#define __DOUBLE_LINK_NODE_H__

template <class T>
class DoubleLinkNode {
    private:
        Node<T>* prev;
        T value;
        Node<T>* next;
    
    public:
        DoubleLinkNode(T value, Node<T>* prev, Node<T>* next) {
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

        Node<T>* getPrev() {
            return this->prev;
        }

        Node<T>* getNext() {
            return this->next;
        }

        void setValue(T value) {
            this->value = value;
        }

        void setPrev(Node<T>* prev) {
            this->prev = prev;
        }
        
        void setNext(Node<T>* next) {
            this->next = next;
        }
};

#endif