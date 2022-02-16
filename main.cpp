#include <iostream>
#include <queue.h>
#include <stack.h>

using namespace std;

int main() {
    Queue<int>* q = new Queue<int>();
    Stack<int>* s = new Stack<int>();
    cout << "Difference between STACK(LIFO) and QUEUE(FIFO) :)" << endl;
    cout << "Input: [1,2,3,4,5]" << endl;
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(4);
    q->push(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);
    cout << "Outputs:" << endl;
    cout << "QUEUE: ";
    q->show();
    cout << "STACK: ";
    s->show();
    return 0;
}