#define ARRAYLIST_H

template <class T>
class arraylist {
    private:
        T *data;
        int length; // how many elements can data hold
        int size; // how many elements are currently in data

        void resize();
        bool needToResize();

    public:
        // constructor
        arraylist() {
            length = 64;
            data = new T[length];
            size = 0;
        }

        // accessors
        bool contains(T item);

        int indexOf(T item);
        int lastIndexOf(T item);

        T *get(int index);

        int getSize();

        // mutators
        void add(T item);
        void add(int index, T item);

        void set(int index, T item);

        void remove(int index);
        // void remove(T item);

/*         // destructor
        ~arraylist(); */

};

#include "arraylist.cpp"