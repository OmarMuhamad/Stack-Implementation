#ifndef STACKHEADER_H_INCLUDED
#define STACKHEADER_H_INCLUDED
#include <iostream>
using namespace std;

class StackFull {
private:
    int sz;
public:
    StackFull(int n) : sz(n) {}

    int get_size() {
        return sz;
    }
};

class StackEmpty {};

template<typename T>
class Stack {
private:
    int Capacity;
    int Top;
    T* stck;
public:
    // constructor
    Stack() {
        Capacity = 0;
    }
    Stack(int sz) {
        stck = new T[sz];
        Capacity = sz;
        Top = -1;
    }
    // push an element to the top of the stack
    void push(T element);
    // popping the first element
    void pop();

    // return top element of the stack
    T top() {
        return stck[Top];
    }
    // return the size of the stack
    int Size();
    // checks if the stack is empty
    bool empty();

    void manageStack(Stack<T>stck);
    // destructor
    ~Stack() {
        delete[] stck;
    }
};
template<typename T> void Stack<T>::push(T element) {
        if (Top >= Capacity - 1 ) {

            throw StackFull(Capacity);
        }
        else {
            Top++;
            stck[Top] = element;
        }
}
template<typename T> void Stack<T>::pop() {
        if (Top == -1) {
            throw StackEmpty();
        }
        else {
            Top--;
        }
}

template<typename T> int Stack<T>::Size() {
        return Top + 1;
}

template<typename T> bool Stack<T>::empty() {
        return (Top == -1);
}

template<typename T> void Stack<T>::manageStack(Stack<T>stck) {
    int choice;

    string message = "1 - Top element\n"
        "2 - Push element\n"
        "3 - Pop element\n"
        "4 - Size of the stack\n"
        "5 - Check if the stack is empty\n"
        "6 - end the program and delete the stack\n";

    while (true) {

        cout << message;

        cout << "Enter \n";
        cin >> choice;
        try {

            switch (choice) {
            case 1: {
                cout << stck.top() << endl;
                break;
            }
            case 2: {
                T element;
                cin >> element;
                stck.push(element);
                break;
            }
            case 3: {
                stck.pop();
                break;
            }
            case 4: {
                cout << stck.Size() << endl;
                break;
            }
            case 5: {
                cout << stck.empty() << endl;
                break;
            }
            default: {
                stck.~Stack();
                return;
            }

            }
        }
        catch (StackFull s) {
            cout << "StackOverFlow" << endl;
        }
        catch (StackEmpty) {
            cout << "Sorry Empty Stack" << endl;
        }
    }
}

#endif // STACKHEADER_H_INCLUDED
