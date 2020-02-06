#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
private:
    vector<T> elements;
public:
    void push(T const &);

    T pop();

    bool isEmpty();

    T top();
};

template<typename T>
void Stack<T>::push(T const &elem) {
    elements.push_back(elem);
}

template<typename T>
T Stack<T>::pop() {
    if (elements.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    auto val = elements.back();
    elements.pop_back();
    return val;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return elements.empty();
}

template<typename T>
T Stack<T>::top() {
    if (elements.empty()) {
        throw out_of_range("Stack<>::Top(): empty stack");
    }
    return elements.back();
}


int main() {
    try {

        Stack<int> stack;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        while (!stack.isEmpty()) {
            cout << stack.pop() << endl;
        }

    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
    return 0;
}