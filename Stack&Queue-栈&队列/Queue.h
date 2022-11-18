//
// Created by ShaoCHi on 2022/11/18.
//

#ifndef INC_408DS_CPP_QUEUE_H
#define INC_408DS_CPP_QUEUE_H
/***
 * 本文件从链表与顺序表实现队列
 */

#include "iostream"

using namespace std;

//链表实现队列
struct Node {
    int value;
    Node *next;

    Node() : value(-1), next(nullptr) {};

    Node(int _value) : value(_value), next(nullptr){};
};

//带头结点的链表实现队列
/***
 * 队尾指针为空时，代表队列为空
 * FIFO，队尾进，队首出
 * 尾插法！！！！！！！！！！！！
 */

class queue {
    Node *head;
    Node *rear;
public:
    queue() : head(new Node(-1)), rear(nullptr) {};

    ~queue() {
        Node* temp = head;
        while (temp->next!= nullptr){
            Node* node = temp->next;
            temp->next = node->next;
        }
        free(head);
    }

    bool is_empty() {
        if (rear == nullptr)
            return true;
        else
            return false;
    }

    void push(int _value) {
        Node *node = new Node(_value);
        node->next = head->next;
        head->next = node;
        if(rear== nullptr)
            rear = node;
    }

    int get_top_item(){
        return rear->value;
    }
};

#endif //INC_408DS_CPP_QUEUE_H
