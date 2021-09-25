#ifndef ARRAYLIST_H
#include "arraylist.h"
#endif

template <class T>
void arraylist<T>::resize() {
    T *temp = new T[length * 2];

    for (int i = 0; i < length; i++) {
        temp[i] = data[i];
    }

    data = temp;

    length *= 2;
}

template <class T>
bool arraylist<T>::needToResize() {
    return length == size;
}

template <class T>
void arraylist<T>::add(T item) {
    if (needToResize()) {
        resize();
    }

    data[size++] = item;
}

template <class T>
void arraylist<T>::add(int index, T item) {
    if (needToResize()) {
        resize();
    }

    for (int i = size; i >= index; i--) {
        data[i + 1] = data[i];
    }

    data[index] = item;

    size++;
}

template <class T>
void arraylist<T>::remove(int index) {
    for (int i = index; i < size; i ++) {
        data[i] = data[i + 1];
    }

    size--;
}

template <class T>
T* arraylist<T>::get(int index) {
    if (index > -1 && index <= length) {
        return &data[index];
    }

    return nullptr;
}

template <class T>
void arraylist<T>::set(int index, T item) {
    if (index > -1 && index <= length) {
        data[index] = item;
    }
}

template <class T>
int arraylist<T>::indexOf(T item) {
    for (int i = 0; i <= size; i++) {
        if (item == data[i]) {
            return i;
        }
    }

    return -1;
}

template <class T>
int arraylist<T>::lastIndexOf(T item) {
    for (int i = size; i > -1; i--) {
        if (item == data[i]) {
            return i;
        }
    }

    return -1;
}

template <class T>
bool arraylist<T>::contains(T item) {
    return (indexOf(item) > -1);
}

template <class T>
int arraylist<T>::getSize() {
    return size;
}