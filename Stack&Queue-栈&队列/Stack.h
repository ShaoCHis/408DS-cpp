//
// Created by 沈韬 on 2022/11/18.
//

#ifndef INC_408DS_CPP_STACK_H
#define INC_408DS_CPP_STACK_H

#include<iostream>
/***
 * 栈实现：
 * 这里分别实现链式栈和顺序表栈
 */

/***
 * 链式栈实现
 * 带头结点的链式栈实现
 */
typedef struct Stack_Node {
    int value;
    Stack_Node *next;

    Stack_Node() : value(-1), next(nullptr) {};

    Stack_Node(int _value) : value(_value), next(nullptr) {};
} Stack_Node;

class stack_link {
    int value;
    Stack_Node *head;
public:
// 链表初始化
    stack_link() : value(-1), head(new Stack_Node()) {};

    ~stack_link() {
        Stack_Node *temp = head;
        while (temp->next != nullptr) {
            Stack_Node *node = temp->next;
            temp->next = node->next;
            free(node);
        }
        free(head);
    }

    void show_stack() {
        Stack_Node *temp = head;
        std::cout << "stack->";
        while (temp->next != nullptr) {
            std::cout << temp->next->value << "->";
            temp = temp->next;
        }
        std::cout << temp->value << "->end" << std::endl;
    }

    void push(int _value) {
        if (head->next == nullptr) {
            head->next = new Stack_Node(_value);
        } else {
            Stack_Node *node = new Stack_Node(_value);
            node->next = head->next;
            head->next = node;
        }
    }

    int pop() {
        if (head->next == nullptr) {
            std::cout << "stack is null!Operation pop is false!" << std::endl;
            return -1;
        } else {
            int result = 0;
            Stack_Node *temp = head->next;
            head->next = temp->next;
            result = temp->value;
            free(temp);
            return result;
        }
    }
};

/***
 * 顺序表栈实现
 * 定义数组空间的最大值，通过数组下标来进行栈空间的判断
 * 以及出栈和入栈操作
 */
#define MAX_SIZE 20

//
class stack_arr {
    int length;
    int *stack;
public:
    stack_arr() {
        length = 0;
        stack = new int[MAX_SIZE];
    }

    ~stack_arr() {
        free(stack);
    }

    void show_stack() {
        if (length == 0)
            std::cout << "Stack is Empty!" << std::endl;
        else {
            std::cout << "Stack:";
            for (int i = length - 1; i > 0; i--) {
                std::cout << stack[i] << "->";
            }
            std::cout << stack[0] << "->end" << std::endl;
        }
    }

    void push(int _value) {
        if (length == MAX_SIZE)
            std::cout << "Stack is full!Operation push is false!" << std::endl;
        else {
            stack[length++] = _value;
            std::cout << "Push successfully!" << std::endl;
        }
    }

    int pop() {
        if (length == 0) {
            std::cout << "Stack is Empty!Operation pop is false!" << std::endl;
            return -1;
        } else {
            std::cout << "Pop successfully!" << std::endl;
            return stack[--length];
        }
    }
};

#endif //INC_408DS_CPP_STACK_H
