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


/***
 * 采用尾插法可以解决队列出队操作后指针更新的问题
 * 1、采用头插法进行元素的插入会导致，head指针下一个元素为队尾，末尾指针指向队队头，在进行出队操作后，由于链表的特性，得到上一个元素的指针需要重新进行遍历或者使用双链表
 * 2、采用尾插法，即链表的head指针下一个元素为队头，链表的尾指针指向队尾，入队操作更新链表的尾指针，出队操作更新链表的头指针下一个结点即可完成操作
 */

//head->next指向队列的队头，rear指针指向队列的队尾
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

    void show_queue(){
        Node* temp = head;
        cout<<"queue::start->";
        while(temp->next!= nullptr){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<temp->value<<"->end"<<endl;
    }

    bool is_empty() {
        if (rear == nullptr)
            return true;
        else
            return false;
    }

    void push(int _value) {
        if (head->next== nullptr){
            head->next = new Node(_value);
            rear = head->next;
        }
        else{
            Node* node = new Node(_value);
            rear->next = node;
            rear = rear->next;
        }
    }

    int get_top_item(){
        return head->next->value;
    }

    void pop(){
        if (head->next==rear){
            Node* n=head->next;
            rear = nullptr;
            free(n);
        }
        else{
            Node* n =head->next;
            head->next = n->next;
            free(n);
        }
    }
};

#endif //INC_408DS_CPP_QUEUE_H
