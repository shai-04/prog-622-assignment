#pragma once

#define COURSE_H

#include <string>

class Course {
    private:
        std::string Name, Surname;
        short Score;

    public:
        Course(std::string n, std::string sn, short s) {
            this->Name = n;
            this->Surname = sn;
            this->Score = s;
        }

        inline std::string getName() {
            return this->Name;
        }

        inline std::string getSurname() {
            return this->Surname;
        }

        inline short getScore() {
            return this->Score;
        }

        ~Course() {}
};