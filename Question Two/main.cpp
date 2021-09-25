#include <string>
#include "List.h"

int main() {
    List<int> l;

    l.add(4);
    l.add(2);
    l.add(3);
    l.add(1);

    l.print();

    return 0;
}