#include <iostream>
#include <vector>

#include "Bus.h"
#include "Passenger.h"

void removePassengers(std::vector<Passenger> &p, short &s, short stop) {
    s = 0;
    std::vector<Passenger> temp;

    while (!p.empty()) {
        if (p.back().getDropOff() == stop) {
            s++;
        }
        else {
            temp.push_back(p.back());
        }

        p.pop_back();
    }

    p.swap(temp);
}

int main() {
    Bus b; // Instance of the bus class
    std::vector<Passenger> passengers; // contains passengers

    short p; // will contain number of passengers to get in
    short s; // will contain what stop passenger will get off at
    short pOff; // will contain the number of passengers that will get off

    system("pause");

    // route starts at stop 1 and ends at stop 7
    for (short i = 1; i < 8; i++) {
        system("cls"); // clear console for each stop
        s = p = 0;

        std::cout << "\nArrived at stop " << i << ". How many passengers are there to pick up? >>> ";
        std::cin >> p;

        if (p > 0) {
            for (short j = 1; j <= p; j++) {
                std::cout << "\nAt which stop does passenger " << j << " wish to get off? >>> ";
                std::cin >> s;

                passengers.push_back(Passenger(s));
            }

            b.loadPassenger(p);
            b.addTotalPassengers(p);
            b.collectFare(p);
        }
        else {
            p = 0;
        }

        std::cout << "\nBoarding " << p << " passengers.\n";

        // check if there are any passengers disembarking
        removePassengers(passengers, pOff, i);
        b.unloadPassenger(pOff);

        system("pause");
    }

    system("cls");
    b.unloadPassenger(b.getCurrentPassengers());

    return 0;
}