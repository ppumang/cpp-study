#include "utils.hpp"

namespace MyExcel {
    Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}
    void Vector::push_back(string s) {
        if (capacity <= length) {
            string* temp = new string[capacity*2];
            for (int i = 0; i< length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }
    string Vector::operator[](int i) {return data[i];}
    void Vector::remove(int x) {
        for (int i = x; i < length-1; i++) {
            data[x] = data[x+1];
        }
        length--;
    }
    int Vector::size() {return length;}
    Vector::~Vector() {
        if (data) {
            delete[] data;
        }
    }

    Stack::Stack() : start(NULL, "") {current = &start;}
    void Stack::push(string s) {
        Node* n = new Node(current, s);
        current = n;
    }
    string Stack::pop() {
        if (current == &start) return "";

        string s = current -> s;
        Node* prev_ = current;
        current = current -> prev;
        delete prev_;
        return s;
    }
    string Stack::peek() {return current -> s;}
    bool Stack::is_empty() {
        return current == &start;
    }
    Stack::~Stack() {
        while (current != &start) {
            Node* prev_ = current;
            current = current -> prev;
            delete prev_;
        }
    }
    NumStack::NumStack() : start(NULL, 0) {current = &start;}
    void NumStack::push(double s) {
        Node* n = new Node(current, s);
        current = n;
    }
    double NumStack::pop() {
        if (current == &start) return 0;
        double s = current -> s;
        Node* prev_ = current;
        current = current -> prev;

        delete prev_;
        return s;
    }
    double NumStack::peek() {return current -> s;}
    bool NumStack::is_empty() {
        return current == &start;
    }
    NumStack::~NumStack() {
        while (current != &start) {
            Node* prev_ = current;
            current = current -> prev;
            delete prev_;
        }
    }
}