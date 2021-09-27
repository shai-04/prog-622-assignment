#pragma once
#define PASSENGER_H

class Passenger {
    private:
        short dropOffPoint;

    public:
        Passenger(short d) {
            this->dropOffPoint = d;
        }

        inline short getDropOff() {
            return this->dropOffPoint;
        }

        ~Passenger() {}
};