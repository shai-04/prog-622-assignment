#pragma once
#include <iostream>

template <class T>
class Node {
    public:
        Node* next;
        T value;

        Node(T v) {
            next = NULL;
            this->value = v;
        };

};

template <class T>
class List {
    private:
        Node<T> *current, *head;

    public:
        List() {
            current = NULL;
            head = NULL;
        }

        void add(T v) {
            Node<T> *n = new Node<T>(v);
            
            if (head == NULL) {
                head = n;
                current = head;
            }
            else {
                current->next = n;
                current = current->next;
            }

            this->sort();
        }

        void remove(T v) {
            Node<T> *delPtr = NULL;
            Node<T> *temp = head;

            current = head;

            while (current != NULL && current->value != v) {
                temp = current;
                current = current->next;
            }

            if (current->value == v) {
                delPtr = current;
                current = current->next;
                temp->next = current;

                if (delPtr == head) {
                    head = head->next;
                    temp = NULL;
                }

                delete delPtr;
            }
        }

        void print() {
            std::cout << "[";

            current = head;

            while (current != NULL) {
                std::cout << current->value << ", ";
                current = current->next;
            }

            std::cout << "]" << std::endl;
        }

        void sort() {
            Node<T> *i = head;
            Node<T> *j;

            T temp;

            for (i; i->next != NULL; i = i->next) {
                for (j = i->next; j != NULL; j = j->next) {
                    if (i->value > j->value) {
                        temp = i->value;
                        i->value = j->value;
                        j->value = temp;
                    }
                }
            }
        }
};