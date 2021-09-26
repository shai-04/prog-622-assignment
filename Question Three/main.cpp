#include <stack>
#include <iostream>

#include "Course.h"

int main() {
    // Creating 3 stacks of type Course (such that Name, Surname
    /// and Score can be held in the same stack)
    std::stack<Course> stack1;
    std::stack<Course> stack2;
    std::stack<Course> stack3;

    // Temporary stack is created to store data lost from stacks
    // when using pop() method. This data can then be swapped back
    // with the stack when all data is displayed
    std::stack<Course> tempStack;

    // Adding the given information to the first stack
    stack1.push(Course("Kathrine", "Bruckner", 42));
    stack1.push(Course("Jack", "Mohamed", 27));
    stack1.push(Course("Aaron", "Black", 83));
    stack1.push(Course("Daniel", "Rose", 64));
    stack1.push(Course("Anna", "Mishima", 34));
    stack1.push(Course("Isaac", "Wayne", 74));
    stack1.push(Course("Nick", "Roberts", 26));
    stack1.push(Course("Mat", "Jackson", 38));
    stack1.push(Course("Sarah", "Khosa", 81));
    stack1.push(Course("Simon", "Johnson", 75));
    stack1.push(Course("John", "Phoenix", 85));
    stack1.push(Course("Sam", "Williams", 60));

    // Displaying the contents of stack1
    std::cout << "Displaying the contents of stack1:" << std::endl;

    while (!stack1.empty()) {
        Course data = stack1.top();

        std::cout << data.getName() << " " << data.getSurname() << " " << data.getScore() << std::endl;

        // If the students surname begins with R, J or M, remove them
        // from the first stack and add them to stack2. Otherwise, add
        // them o tempStack such that they can be readded to stack1
        if (data.getSurname()[0] == 'R' || data.getSurname()[0] == 'J' || data.getSurname()[0] == 'M') {
            stack2.push(data);
        }
        else {
            tempStack.push(data);
        }

        stack1.pop();
    }

    std::cout << std::endl;

    // Since data is lost from stack1 but is stored in the temp stack, 
    stack1.swap(tempStack);

    system("pause"); // Allows user to see results before moving on
    system("cls"); // Clears the console for next output of stacks

    std::cout << "Displaying the contents of stack1:" << std::endl;

    while (!stack1.empty()) {
        Course data = stack1.top();

        std::cout << data.getName() << " " << data.getSurname() << " " << data.getScore() << std::endl;

        if (data.getScore() < 50) {
            stack3.push(data);
        }
        else {
            tempStack.push(data);
        }

        stack1.pop();
    }

    // Since data is lost from stack1 but is stored in the temp stack, 
    stack1.swap(tempStack);

    std::cout << std::endl;

    std::cout << "\nDisplaying the contents of stack2:" << std::endl;

    while (!stack2.empty()) {
        Course data = stack2.top();

        std::cout << data.getName() << " " << data.getSurname() << " " << data.getScore() << std::endl;

        if (data.getScore() < 50) {
            stack3.push(data);
        }
        else {
            tempStack.push(data);
        }

        stack2.pop();

    }

    // Since data is lost from stack2 but is stored in the temp stack, 
    stack2.swap(tempStack);

    std::cout << std::endl;

    system("pause"); // Allows user to see results before moving on
    system("cls"); // Clears the console for next output of stacks

    std::cout << "\nDisplaying the contents of stack1:" << std::endl;

    while (!stack1.empty()) {
        Course data = stack1.top();

        std::cout << data.getName() << " " << data.getSurname() << " " << data.getScore() << std::endl;

        stack1.pop();
    }

    std::cout << std::endl;

    std::cout << "\nDisplaying the contents of stack2:" << std::endl;

    while (!stack2.empty()) {
        Course data = stack2.top();

        std::cout << data.getName() << " " << data.getSurname() << " " << data.getScore() << std::endl;

        stack2.pop();
    }

    std::cout << std::endl;

    std::cout << "\nDisplaying the contents of stack3:" << std::endl;

    while (!stack3.empty()) {
        Course data = stack3.top();

        std::cout << data.getName() << " " << data.getSurname() << " " << data.getScore() << std::endl;

        stack3.pop();
    }

    std::cout << std::endl;

    return 0;
}