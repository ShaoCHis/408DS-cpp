//
// Created by ShaoCHi on 2022/10/29.
//

#ifndef INC_408DS_CPP_SINGAL_LINK_H
#define INC_408DS_CPP_SINGAL_LINK_H

#include<iostream>
///实现单链表的生成、插入、删除等操作
struct Node{
    int value;
    Node* next;
    Node(){};
    Node(int _value):value(_value),next(nullptr){};
};

class test_link {
private:
    Node* head;

public:
    test_link(Node* node){
        this->head=node;
    }

    Node* getHead(){
        return this->head;
    }
//在链表的末尾进行插入操作
    void insert_last(int item){
        Node* temp = this->head;
        if(temp== nullptr){
            Node* node = new Node(item);
            this->head=node;
            return;
        }
        while (temp->next!= nullptr)
            temp=temp->next;
        temp->next = new Node(item);
    }
//删除链表中结点value等于item的结点
    void delete_value(int item){
        //取值操作前应该首先判断一下该指针是否为空
        if(this->head== nullptr)
            return;
        Node* temp = this->head;
        //若头结点满足该条件，应该一直循环直到不满足条件，更新头结点
        while(temp->value==item){
            Node* node=temp;
            temp=temp->next;
            delete node;
        }
        this->head=temp;
        if(this->head== nullptr)
            return;
        //单链表需要进行连接操作，所以需要判断是当前结点的下一个结点的value值与item的关系
        while(temp->next!= nullptr){
            if (temp->next->value!=item)
                temp=temp->next;
            else{
                Node* node = temp->next;
                temp->next=temp->next->next;
                delete node;
            }
        }
    }
//查找链表中结点value等于item的结点
    Node* search_value(int item){
        if(this->head== nullptr)
            return nullptr;
        Node* temp=this->head;
        while(temp->next!= nullptr){
            if(temp->value==item){
                return temp;
            }
            else{
                temp=temp->next;
            }
        }
        if(temp->value==item)
            return temp;
        else
            return nullptr;
    }
//显示链表
    void show(){
        if (this->head== nullptr) {
            std::cout << "sorry!this link is null" << std::endl;
            return;
        }
        Node* temp= this->head;
        while(temp!= nullptr and temp->next!= nullptr){
            std::cout<<temp->value<<"->";
            temp=temp->next;
        }
        std::cout<<temp->value<<std::endl;
    }
    ~test_link(){
        Node* temp=this->head;
        while(temp!= nullptr){
            Node* n=temp;
            temp=temp->next;
            delete n;
        }
    }
};


#endif //INC_408DS_CPP_SINGAL_LINK_H
