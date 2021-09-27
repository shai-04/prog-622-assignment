#pragma once
#define BUS_H

#include <iostream>

class Bus {
    private:
        int passengers; // Number of passengers in the bus
        int totalPassengers; // total passengers that took the bus
        int currentStop; // Which stop is the bus at
        float cash; // Total cash collected from passengers

        const float fare = 1.5; // fare for passenger to pay

    public:
        Bus() {
            // Route from starting point to first stop
            std::cout << "Shift started, en route to first stop.\n";

            this->passengers = 0;
            this->totalPassengers = 0;
            this->currentStop = 0;
            this->cash = 0.0f;
        }

        int getCurrentPassengers() {
            return this->passengers;
        }

        void loadPassenger(short p) {
            if (p == 1) {
                this->passengers++;
                this->cash += 1.5;
            }
            else {
                this->loadPassenger(p - 1);

                this->passengers++;
                this->cash += 1.5;
            }
        }

        void addTotalPassengers(short p) {
            this->totalPassengers += p;
        }

        void collectFare(short p) {
            std::cout << "Collected: R" << p * this->fare << "\n";
            std::cout << "Total: R" << this->cash << "\n";
        }

        void unloadPassenger(short p) {
            this->passengers -= p;
            std::cout << p << " passengers have disembarked\n";
        }

        ~Bus() {
            std::cout << "\nShift ended, route completed.\n";

            std::cout << "Total passengers: " << this->totalPassengers << "\n";
            std::cout << "Total fares: R" << this->cash << "\n";
        }
};