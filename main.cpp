#include <iostream>
// #include <double-linked-list.h>
#include <cmath>
#include <stack.h>

using namespace std;

typedef struct Fpoint {
    float x,y;
} FPoint;

FPoint rotate(FPoint point, float theta) {
    return (FPoint){cos(theta) * (point.x) - sin(theta) * (point.y), cos(theta) * (point.y) + sin(theta) * (point.x)};
}

void show(Stack<FPoint>* stack) {
    if (stack->isEmpty()) return;
    Node<FPoint>* tmp = stack->getHead();
    while (tmp != NULL) {
        cout << "(" << tmp->getValue().x << ";" << tmp->getValue().y << ")" << endl;
        tmp = tmp->getNext();
    }
}

void polygon(int side, Stack<FPoint>* stack) {
    Fpoint A = {-2.0f, 2.0f};
    int i = 0;
    float theta = (2.0f * M_PI) / (float)side;
    stack->push(A);
    while (i < side - 1) {
        FPoint rot = rotate(stack->getHead()->getValue(), theta);
        stack->push(rot);
        i++;
    }
}

int main() {
    cout << "Hello Collection C++" << endl;
    return 0;
}