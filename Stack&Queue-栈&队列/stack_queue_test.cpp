//
// Created by ShaoCHi on 2022/11/18.
//

#include<iostream>
#include "Stack.h"

int main() {
    stack_link s = stack_link();
    std::cout << "=============stack with Link Start===============" << std::endl;
    s.show_stack();
    std::cout << "Pop::" << s.pop() << std::endl;
    for (int i = 0; i < 10; i++) {
        s.push(rand() % 100);
    }
    s.show_stack();
    std::cout << "Pop::" << s.pop() << std::endl;
    s.show_stack();

    std::cout << "=============stack with Array Start===============" << std::endl;
    stack_arr e = stack_arr();
    e.show_stack();
    std::cout << "Pop::" << e.pop() << std::endl;
    for (int j = 0; j < 10; ++j) {
        e.push(rand() % 100);
    }
    e.show_stack();
    std::cout << "Pop::" << e.pop() << std::endl;
    e.show_stack();
}
