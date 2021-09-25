#include <iostream>
#include "arraylist.h"

using namespace std;

int main() {
    arraylist<int> marks;

    // Adding elements to an arrayList
    marks.add(4);
    marks.add(5);
    marks.add(6);
    marks.add(64);
    marks.add(2);
    marks.add(7658);

    // Displaying the elements in the arrayList
    cout << "Displaying current elements" << endl;
    for (int i = 0; i < marks.getSize(); i++) {
        cout << *(marks.get(i)) << endl;
    }

    // Removing the last element from the arrayList
    marks.remove(marks.getSize()); // remove the last element

    marks.add(1, 100); // adds 100 to the 2nd position and shifts others up

    marks.set(0, 64); // set the first element to 64

    cout << "The last position of 64 is: " << marks.lastIndexOf(64) << endl;
    cout << "The first position of 5 is: " << marks.indexOf(5) << endl;

    if (marks.contains(2)) {
        cout << "The arrayList contains 2" << endl;
    }
    else {
        cout << "The arrayList doesn't contain 2" << endl;
    }


    return 0;
}