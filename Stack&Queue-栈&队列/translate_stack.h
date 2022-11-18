//
// Created by ShaoCHi on 2022/11/18.
//

#ifndef INC_408DS_CPP_TRANSLATE_STACK_H
#define INC_408DS_CPP_TRANSLATE_STACK_H

#include "iostream"

/***
 * 本栈文件用于实现表达式的转换
 * （为方便使用，重新实现了一个便于表达式转换利用的栈）
 */

typedef struct Stack_Node {
    char value;
    Stack_Node *next;

    Stack_Node() : value(' '), next(nullptr) {};

    Stack_Node(char _value) : value(_value), next(nullptr) {};
} Stack_Node;

class stack_link {
    char value;
    Stack_Node *head;
public:
// 链表初始化
    stack_link() : value(' '), head(new Stack_Node()) {};

    ~stack_link() {
        Stack_Node *temp = head;
        while (temp->next != nullptr) {
            Stack_Node *node = temp->next;
            temp->next = node->next;
            free(node);
        }
        free(head);
    }

    bool is_empty() {
        if (head->next == nullptr)
            return true;
        else
            return false;
    }

    char get_pop_item() {
        return head->next->value;
    }

    void pop() {
        Stack_Node *temp = head->next;
        head->next = temp->next;
        free(temp);
    }

    void push(char _value) {
        Stack_Node *node = new Stack_Node(_value);
        node->next = head->next;
        head->next = node;
    }
};

#endif //INC_408DS_CPP_TRANSLATE_STACK_H
